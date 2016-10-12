#include <SD.h>
#include <SPI.h>
#include <dht.h>
#include <TM1637Display.h>

// SD Documentation: https://oscarliang.com/sd-card-arduino/

// Variables
#define DHT11_PIN 2
const int CLK = 9; //Set the CLK pin connection to the display
const int DIO = 8; //Set the DIO pin connection to the display
const int sdPin = 4;
dht DHT;
TM1637Display display(CLK, DIO);
File myFile;

/*
 * Setup
 */
void setup()
{
  Serial.begin(9600);
  Serial.print("SD Card initialization");
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  if (SD.exists("test.txt")) {
    SD.remove("test.txt");
  }
  
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  display.setBrightness(0x0a);
}

/*
 * Loop - run over and over again
 */
void loop()
{
int chk = DHT.read11(DHT11_PIN);
display.showNumberDec(DHT.temperature);
/*
File dataFile = SD.open("data.txt", FILE_WRITE);
if (dataFile) {
    dataFile.print("Temperature: ");
    dataFile.println(DHT.temperature);
    dataFile.close();
}*/

delay(1000);
}
