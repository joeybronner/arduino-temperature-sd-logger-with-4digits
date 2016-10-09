#include <TM1637Display.h>
#include <lm35.h>


// Variables
lm35 temps(0);
const int CLK = 9; //Set the CLK pin connection to the display
const int DIO = 8; //Set the DIO pin connection to the display

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

temps.MeasureTemp();
Serial.print(temps.TempInCelcius); // print temperature
Serial.println("C");

display.showNumberDec(temps.TempInCelcius);
delay(2000);
}
