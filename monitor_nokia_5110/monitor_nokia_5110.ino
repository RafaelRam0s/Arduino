/* ========================================================================================================
  Projeto: Desenhando no Display Nokia 5110
  
  **Código modificado da Adafruit**
  
  Data: 23/05/2019
  Todos os Direitos reservados.
// ==================================================================================================*/

#include "Adafruit_GFX.h"        // Biblioteca para utilizar as fontes
#include "Adafruit_PCD8544.h"    // Biblioteca para utilizar os comandos do Display

Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);      // Criando o construtor e passando a pinagem dele

// pin 8  - Serial clock out    (SCLK)
// pin 9  - Serial data out     (DIN)
// pin 10 - Data/Command select (D/C)
// pin 11 - LCD chip select     (CS)
// pin 12 - LCD reset           (RST)

void setup() {

  // Icializando o Display
  display.begin();

  // Aqui estamos definindo o valor do contraste que pode variar entre 0-127
  display.setContrast(55);

  // Limpa todo o display
  display.clearDisplay();

  // Escreve no Display
  display.setTextSize(2);       // Tamanho da Fonte
  display.setTextColor(BLACK);  // Cor da Fonte

  display.setCursor(((display.width() / 2) - 25), ((display.height() / 2) - 16)); // Posição no Display onde vamos escrever

  display.println("AUTO");   // Texto que será escrito
  display.display();
  delay(500);

  // Invertendo texto no Display
  display.setTextColor(WHITE, BLACK); // Comando para inverter a cor da Fonte (Preto --> Branco)
  display.setCursor(((display.width() / 2) - 25), display.height() / 2);

  display.println("CORE");
  display.display();

  delay(2000);
  display.clearDisplay();

  // ==== ESCREVENDO ARDUINO =====
  display.setTextColor(BLACK);     // Cor da Fonte
  
  display.setCursor(((display.width() / 2) - 20), (display.height() / 2) - 15);   // Posição de inicio para escrever

  display.drawLine(((display.width() / 2) - 20), (display.height() / 2) - 17, ((display.width() / 2) + 19), (display.height() / 2) - 17, BLACK); // Desenhando a 1º linha
  display.display();
  
  display.setTextSize(1);     // Tamanho da fonte
  display.println("ARDUINO");
  
  display.drawLine(((display.width() / 2) - 20), (display.height() / 2) - 7, ((display.width() / 2) + 19), (display.height() / 2) - 7, BLACK);   // Desenhando a 2º Linha
  display.display();

  // Escrevendo Caracteres da Tabela ASCII
  display.setCursor(((display.width() / 2) - 9), (display.height() / 2) - 4);

  display.setTextSize(3);
  display.write(3);        // escrevendo o caractere número (3) da tabela

  display.display();
  delay(2000);
  display.clearDisplay();

  // ==== ESCREVENDO ROBÓTICA ===
  display.setTextColor(BLACK);
  display.setCursor(((display.width() / 2) - 25), (display.height() / 2) - 15);

  display.drawLine(((display.width() / 2) - 25), (display.height() / 2) - 17, ((display.width() / 2) + 25), (display.height() / 2) - 17, BLACK);
  display.display();
  
  display.setTextSize(1);     // Tamanho da fonte
  display.println("ROBOTICA");
  
  display.drawLine(((display.width() / 2) - 25), (display.height() / 2) - 7, ((display.width() / 2) + 25), (display.height() / 2) - 7, BLACK);
  display.display();

  // Escrevendo Caracteres da Tabela ASCII
  display.setCursor(((display.width() / 2) - 9), (display.height() / 2) - 5);

  display.setTextSize(3);
  display.write(3);        // escrevendo o caractere número (3) da tabela

  display.display();
  delay(2000);
  display.clearDisplay();

  // ==== ESCREVENDO 'E' ====
  display.setTextColor(BLACK);
  display.setCursor(((display.width() / 2) - 10), (display.height() / 2) - 15);

  display.setTextSize(3);     // Tamanho da fonte
  display.println("E");

  display.display();
  delay(1000);
  display.clearDisplay();

  // ==== ESCREVENDO MUITO MAIS ====
  display.setTextColor(BLACK);
  display.setCursor(((display.width() / 2) - 30), (display.height() / 2) - 15);

  display.drawLine(((display.width() / 2) - 30), (display.height() / 2) - 17, ((display.width() / 2) + 30), (display.height() / 2) - 17, BLACK);
  display.display();
  
  display.setTextSize(1);     // Tamanho da fonte
  display.println("MUITO MAIS");
  
  display.drawLine(((display.width() / 2) - 30), (display.height() / 2) - 7, ((display.width() / 2) + 30), (display.height() / 2) - 7, BLACK);
  display.display();

  // Escrevendo Caracteres da Tabela ASCII
  display.setCursor(((display.width() / 2) - 9), (display.height() / 2) - 5);

  display.setTextSize(3);
  display.write(3);        // escrevendo o caractere número (3) da tabela

  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {}
// ============================== FIM ===================================