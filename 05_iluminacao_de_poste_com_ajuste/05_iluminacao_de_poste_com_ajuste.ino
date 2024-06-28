
#define foto_resistor A5

#define led_vermelho 9
#define led_verde 8
#define botao_abaixa_resistor 7
#define botao_aumenta_resistor 6

void setup()
{
  pinMode(foto_resistor, INPUT);
  
  pinMode(botao_abaixa_resistor, INPUT);
  pinMode(botao_aumenta_resistor, INPUT);
  
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);

  Serial.begin(9600);
}

int resistencia_do_resistor = 600;

void loop()
{
  if (analogRead(foto_resistor) < resistencia_do_resistor)
  {
    digitalWrite(led_verde, HIGH);
  } else
  {
    digitalWrite(led_verde, LOW);
  }

  if (digitalRead(botao_abaixa_resistor) == HIGH)
  {
    digitalWrite(led_vermelho, HIGH);
    if (resistencia_do_resistor != 0)
    {
      resistencia_do_resistor = resistencia_do_resistor - 50;  
    }

    while (digitalRead(botao_abaixa_resistor) == HIGH) {}
    digitalWrite(led_vermelho, LOW);
  }

  if (digitalRead(botao_aumenta_resistor) == HIGH)
  {
    digitalWrite(led_vermelho, HIGH);
    if (resistencia_do_resistor != 1000)
    {
      resistencia_do_resistor = resistencia_do_resistor + 50;  
    }
    
    while (digitalRead(botao_aumenta_resistor) == HIGH) {}
    digitalWrite(led_vermelho, LOW);
  }
  
  Serial.println(analogRead(foto_resistor));
  delay(100);
}
