 /*
 Arduino Slave for Raspberry Pi Master
  i2c_slave_ard.ino
  Connects to Raspberry Pi via I2C
  and transmits IR codes to AVer 520 camera
  Tony Davis 18.01.2021
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

  while (Wire.available()) { // loop through all but the last
    int c = Wire.read(); // receive byte as a character
    Serial.println(c);

  if(c == 1)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C73807F, 32);  // Key pad 1
    }


 if(c == 2)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C7340BF, 32);  // Key pad 2
    }

 if(c == 3)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C73C03F, 32);  // Key pad 3
    }

 if(c == 4)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C7320DF, 32);  // Key pad 4
    }

 if(c == 5)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C73A05F, 32);  // Key pad 5
    }

 if(c == 6)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C73609F, 32);  // Key pad 6
    }

 if(c == 7)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C73E01F, 32);  // Key pad 7
    }

 if(c == 8)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C7310EF, 32);  // Key pad 8
    }

 if(c == 9)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C73906F, 32);  // Key pad 9
    }


 if(c == 10)
    {
      irsend.sendNEC(0x2C73A857, 32);
      delay(10000);
      irsend.sendNEC(0x2C7300FF, 32);  // Key pad 0      
    }

 if(c == 11)
    {
      irsend.sendNEC(0x2C738877, 32);  // Tilt up
    }

 if(c == 12)
    {
      irsend.sendNEC(0x2C7328D7, 32);  // Tilt down
    }

 if(c == 13)
    {
      irsend.sendNEC(0x2C7348B7, 32);  // Pan left
    }

 if(c == 14)
    {

      irsend.sendNEC(0x2C73C837, 32);  // Pan right
    }


 if(c == 15)
    {

      irsend.sendNEC(0x2C7330CF, 32);  // Zoom in
    }

if(c == 0)
    {

      irsend.sendNEC(0x2C73F00F, 32);  // Zoom out  
    }


   


 
    }
  }

void loop() {
  //delay(100);
}
