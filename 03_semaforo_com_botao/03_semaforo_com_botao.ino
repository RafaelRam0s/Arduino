// C++ code
//

int led_verde = 13;
int led_amarelo = 12;
int led_vermelho = 11;
int botao = 2;

int tempo = 0;
int cor = 0;
/*
	0 == verde
    1 == amarelo
    2 == vermelho
*/

void setup()
{
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  
  if (digitalRead(botao) == LOW)
  {
    cor = 1;
    tempo = 0;
  }
  
  if (cor == 0)
  {
    if (tempo <= 5000)
    {
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_vermelho, LOW);
      
      digitalWrite(led_verde, HIGH);
    } else {
      cor = 1;
      tempo = 0;
    }
  }
  
  if (cor == 1)
  {
    if (tempo <= 1500)
    {
      digitalWrite(led_verde, LOW);
      digitalWrite(led_vermelho, LOW);
      
      digitalWrite(led_amarelo, HIGH);
    } else {
      cor = 2;
      tempo = 0;
    }
  }
  
  if (cor == 2)
  {
    if (tempo <= 5000)
    {
      digitalWrite(led_verde, LOW);
      digitalWrite(led_amarelo, LOW);
      
      digitalWrite(led_vermelho, HIGH);
    } else {
      cor = 0;
      tempo = 0;
    }
  }
  
  tempo = tempo + 1;
  delay(1);
}
