// C++ code
//

int botao_verde = 2;
int botao_vermelho = 3;
int botao_amarelo = 4;

int led_erro = 8;
int led_acerto = 9;

int led_amarelo = 11;
int led_vermelho = 12;
int led_verde = 13;

void setup()
{
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_acerto, OUTPUT);
  pinMode(led_erro, OUTPUT);
  
  pinMode(botao_verde, INPUT);
  pinMode(botao_vermelho, INPUT);
  pinMode(botao_amarelo, INPUT);
  
  // Para sortear numero aleatorio
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

int tempo_de_reset = 500;
int tempo_para_visualizar = 1000;

int modo_de_jogo = 0;
/*
	0 == Inicio
    1 == Sorteando/Mostrando
    2 == Escolha do Usuario
    3 == Verificando Escolha
*/
int numero_da_faze = 3;
int numero_de_valores_no_vetor = 0;
int valores_sorteados[10] = {0};
int cor_escolhida = 0;
/*
	1 == Verde
    2 == Vermelho
    3 == Amarelo
*/
int numero_de_valores_escolhidos = 0;
int ganhou = 1;
/*
  0 == perdeu
  1 == ganhou
*/

void loop()
{
  // Sinaliza o inicio da faze
  if (modo_de_jogo == 0)
  {
    acenderLeds();
    delay(tempo_de_reset);
      
    apagarLeds();
    delay(tempo_de_reset);
    
    modo_de_jogo = 1;
  }
  
  // Sortear cores
  if (modo_de_jogo == 1)
  {
    // Verificar se numero da faze está igual a quantidade de valores salvas no vetor
    if (numero_de_valores_no_vetor < numero_da_faze)
    {
      // Sortear um valor
      int numero_sorteado = random(3) + 1;
      while (numero_sorteado == valores_sorteados[numero_de_valores_no_vetor - 1])
      {
        numero_sorteado = random(3) + 1;
      }
      
      // Adicionar em um vetor o valor escolhido
      valores_sorteados[numero_de_valores_no_vetor] = numero_sorteado;
      // Adicionar no contador a quantidade de valores salvos
      numero_de_valores_no_vetor = numero_de_valores_no_vetor + 1;
      
      if(numero_sorteado == 1)
      {
        apagarLeds();
        digitalWrite(led_verde, HIGH);
		delay(tempo_para_visualizar);
        digitalWrite(led_verde, LOW);
        delay(tempo_de_reset);
        
      } else if (numero_sorteado == 2)
      {
        apagarLeds();
        digitalWrite(led_vermelho, HIGH);
		delay(tempo_para_visualizar);
        digitalWrite(led_vermelho, LOW);
        delay(tempo_de_reset);
        
      } else if (numero_sorteado == 3)
      {
        apagarLeds();
        digitalWrite(led_amarelo, HIGH);
		delay(tempo_para_visualizar);
        digitalWrite(led_amarelo, LOW);
        delay(tempo_de_reset);
      }
      
    } else
    {
      modo_de_jogo = 2;
    }
  }
  
  if (modo_de_jogo == 2)
  {
    if ( (numero_de_valores_escolhidos < numero_de_valores_no_vetor) && (ganhou == 1))
    {
      if ( (digitalRead(botao_verde) == HIGH) || (digitalRead(botao_vermelho) == HIGH) || (digitalRead(botao_amarelo) == HIGH) )
      {
        if (digitalRead(botao_verde) == HIGH)
        {
          digitalWrite(led_verde, HIGH);
          cor_escolhida = 1;
        }

        if (digitalRead(botao_vermelho) == HIGH)
        {
          digitalWrite(led_vermelho, HIGH);
          cor_escolhida = 2;
        }

        if (digitalRead(botao_amarelo) == HIGH)
        {
          digitalWrite(led_amarelo, HIGH);
          cor_escolhida = 3;
        }

        while ( (digitalRead(botao_verde) == HIGH) || (digitalRead(botao_vermelho) == HIGH) || (digitalRead(botao_amarelo) == HIGH) )
        {}
        apagarLeds();

        if ( (cor_escolhida != valores_sorteados[numero_de_valores_escolhidos]) && (ganhou == 1) )
        {
          ganhou = 0;
        }

        numero_de_valores_escolhidos = numero_de_valores_escolhidos + 1;

      }
    }
    else
    {
      modo_de_jogo = 3;
    }

    if ( modo_de_jogo == 3 )
    {
      if (ganhou == 1)
      {
        digitalWrite(led_acerto, HIGH);
        
        if (numero_da_faze >= 9)
        {
          numero_da_faze = 3;
        } else
        {
          numero_da_faze = numero_da_faze + 1;
        }
      } else
      {
        digitalWrite(led_erro, HIGH);
      }
      delay(5000);

      numero_de_valores_no_vetor = 0;
      valores_sorteados[10] = {0};
      cor_escolhida = 0;
      numero_de_valores_escolhidos = 0;
      ganhou = 1;

      modo_de_jogo = 0;
    }
  }
}

void acenderLeds()
{
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_vermelho, HIGH);
    digitalWrite(led_amarelo, HIGH);
    digitalWrite(led_acerto, HIGH);
    digitalWrite(led_erro, HIGH);
}
void apagarLeds()
{
    digitalWrite(led_verde, LOW);
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_acerto, LOW);
    digitalWrite(led_erro, LOW);
}





