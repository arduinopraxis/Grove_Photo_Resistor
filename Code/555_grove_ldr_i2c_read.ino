//
// Grove I2C LDR mit MCP342x - Read Analog Value
// Datei: 555_grove_ldr_i2c_read.ino
// Datum: 15.09.22/TB
//
// Arduino Library
// https://github.com/uChip/MCP342X



#include  <Wire.h>
#include  <MCP342X.h>

MCP342X myADC;

void setup() 
{
  Wire.begin();
  TWBR = 12;  // 400 kHz (maximum)
  
  Serial.begin(9600);
  while (!Serial) {}  // wait for Serial comms to become ready
  Serial.println("Grove Photo Resistor..");
  Serial.println("Testing device connection...");
  Serial.println(myADC.testConnection() ? "MCP342X connection successful" : "MCP342X connection failed");
    
  myADC.configure( MCP342X_MODE_CONTINUOUS |
                   MCP342X_CHANNEL_1 |
                   MCP342X_SIZE_16BIT |
                   MCP342X_GAIN_1X
                 );

  Serial.println(myADC.getConfigRegShdw(), HEX);

  Serial.println("Environment Light:");
  Serial.println("-----------------------");

  delay(1000);
}

void loop() 
{
  static int16_t  result;
  
  myADC.startConversion();
  myADC.getResult(&result);
  // Ausgabe Dezimalwert
  Serial.println(result, DEC);

  // warten
  delay(1000);
  
}