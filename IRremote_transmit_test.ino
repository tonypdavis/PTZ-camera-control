/// Transmits IP signels to TV etc
/// taken from DroneBot Workshop
/// Tony Davis
/// 20.12.2020
/// tested and it works


// Include IR Remote Library by Ken Shirriff
 
#include <IRremote.h>
 
// Define switch pin
const int switchPin = 7;
 
// Define a variable for the button state
int buttonState = 0;
 
// Create IR Send Object
IRsend irsend;
 
void setup()
{
  // Set Switch pin as Input
  pinMode(switchPin, INPUT);
}
 
void loop() {
  
  // Set button state depending upon switch position
  buttonState = digitalRead(switchPin);
  
  // If button is pressed send power code command
   if (buttonState == HIGH) {
    irsend.sendSAMSUNG(0xE0E0D22D, 32); // TV code
  }
      
    // Add a small delay before repeating
    delay(200);
 
} 
