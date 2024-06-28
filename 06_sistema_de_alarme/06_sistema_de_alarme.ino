
#define foto_resistor A5
#define buzzer 10
#define laiser 9
#define led_verde 8


void setup()
{
  pinMode(foto_resistor, INPUT);
  
  pinMode(buzzer, OUTPUT);
  pinMode(laiser, OUTPUT);
  pinMode(led_verde, OUTPUT);
  
  
  
  Serial.begin(9600);
}

int resistencia_do_foto_resistor = 600;

void loop()
{
  digitalWrite(laiser, HIGH);
  if (analogRead(foto_resistor) < resistencia_do_foto_resistor)
  {
    digitalWrite(led_verde, HIGH);
    tone(buzzer, 1000);
    delay(500);
    
    int calcula = 1000/440;
    tone(buzzer, (int)calcula); //LA
    delay(400);
  } else {
    digitalWrite(led_verde, LOW);
    noTone(buzzer);
  }
  
  
}