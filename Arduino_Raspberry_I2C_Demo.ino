 /*
 Arduino Slave for Raspberry Pi Master
  Connects to Raspberry Pi via I2C
  and transmits IR codes 
  Tony Davis -05.01.2021
  */
 
// Include the Wire library for I2C
#include <Wire.h>

// Include the IRremote library for IR trasmission
#include <IRremote.h>

// create IR send object
IRsend irsend;
 
void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);

  // Call receiveEvent when data received 
  // this acts like an interrupt and stopt the programs
  // to run the code                
  Wire.onReceive(receiveEvent);
  

   // Setup Serial Monitor 
  Serial.begin(9600);
  Serial.println("Receiving data from Raspberry Pi");

}

void pause()
{
delay(200000);
}
 
// Function that executes whenever data is received from master
void receiveEvent(int howMany) {

  while (Wire.available()) { // loop through 
    int c = Wire.read(); // receive byte as a character
    Serial.println(c);

  if(c == 1)
    {

      irsend.sendNEC(0x2C73807F, 32);  // Key pad 1
    }


 if(c == 2)
    {

      irsend.sendNEC(0x2C7340BF, 32);  // Key pad 2
    }

 if(c == 3)
    {

      irsend.sendNEC(0x2C73C03F, 32);  // Key pad 3
    }

  
    }
  }

void loop() {
  //delay(100);
}
