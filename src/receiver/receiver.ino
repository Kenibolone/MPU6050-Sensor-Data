#include <SoftwareSerial.h>     // Include SoftwareSerial to communicate with HC-12 on custom pins
#include <Servo.h>              // Include Servo library to control the servo motor

SoftwareSerial HC12(10, 11);    // Create a software serial port on pins 10 (RX) and 11 (TX)
Servo myServo;                  // Create a Servo object to control the servo motor

void setup() 
{
  HC12.begin(9600);             // Start HC-12 serial communication at 9600 baud
  Serial.begin(9600);           // Start Serial Monitor communication at 9600 baud
  myServo.attach(9);            // Attach the servo signal pin to pin 9
}

void loop() 
{
  // Check if any data has been received from HC-12
  if (HC12.available())  
  {
    // Read the incoming string until the character 'e' is found (used as a terminator)
    String receivedData = HC12.readStringUntil('e');  

    // Check if the received string starts with 's' to indicate it's an angle command
    if (receivedData.startsWith("s"))  
    {
      receivedData = receivedData.substring(1);     // Remove the 's' character
      int angle = receivedData.toInt();             // Convert the remaining string to an integer

      Serial.print("Received Angle: ");
      Serial.println(angle);                        // Print the received angle to Serial Monitor

      myServo.write(angle);                         // Set servo to the received angle
    }
  }
}
