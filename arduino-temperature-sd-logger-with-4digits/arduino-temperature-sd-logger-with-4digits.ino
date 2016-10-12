#include <SD.h>
#include <dht.h>
#include <TM1637Display.h>

// Variables
#define DHT11_PIN 2
const int CLK = 9; //Set the CLK pin connection to the display
const int DIO = 8; //Set the DIO pin connection to the display
dht DHT;
TM1637Display display(CLK, DIO);
 
/*
 * Setup
 */
void setup()
{
  Serial.begin(9600);
  display.setBrightness(0x0a);
}

/*
 * Loop - run over and over again
 */
void loop()
{
int chk = DHT.read11(DHT11_PIN);
display.showNumberDec(DHT.temperature);
delay(500);
}
