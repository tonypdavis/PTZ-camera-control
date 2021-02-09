/// Sketch to use IR to turn on two LEDS
/// Tony Davis
/// 19.12.2020
/// tested and works


// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>
 
// Define sensor pin
const int RECV_PIN = 4;
 
// Define LED pin constants
const int redPin = 8; 
const int yellowPin = 7;
 
// Define integer to remember toggle state
int togglestate = 0;
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;
 
 
void setup(){
  // Enable the IR Receiver
  irrecv.enableIRIn();
  // Set LED pins as Outputs
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}
 
 
void loop(){
    if (irrecv.decode(&results)){
 
        switch(results.value){
          case 0xE0E036C9: //Red Keypad Button
        // Turn on LED for 2 Seconds
        digitalWrite(redPin, HIGH);
        delay(2000);
        digitalWrite(redPin, LOW);
        break;
   
          case 0xE0E0A857: //Yellow Keypad Button
        // Toggle LED On or Off
        if(togglestate==0){
        digitalWrite(yellowPin, HIGH);
        togglestate=1;
        }
        else {
        digitalWrite(yellowPin, LOW);
        togglestate=0;
        }
        break;
        
    }
    irrecv.resume(); 
  }
 
}
