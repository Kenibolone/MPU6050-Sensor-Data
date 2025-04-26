#include <Wire.h>               // Include the Wire library for I2C communication
#include <SoftwareSerial.h>     // Include SoftwareSerial library to use other digital pins for serial

#define MPU_ADDR 0x68           // I2C address of the MPU6050 sensor

SoftwareSerial HC12(10, 11);    // Define HC-12 module RX and TX on pins 10 and 11

int16_t ax, ay, az;             // Raw accelerometer values
float angleX, angleY;           // Calculated tilt angles in X and Y axes

void setup() 
{
  Serial.begin(9600);           // Start Serial Monitor communication at 9600 baud
  HC12.begin(9600);             // Start HC-12 communication at 9600 baud

  Wire.begin();                 // Start I2C communication
  Wire.beginTransmission(MPU_ADDR); // Begin transmission to MPU6050
  Wire.write(0x6B);             // Access power management register
  Wire.write(0);                // Wake up the MPU6050 (set sleep = 0)
  Wire.endTransmission(true);  // End transmission
  delay(100);                   // Give it time to initialize
}

void loop() 
{
  // Begin reading from accelerometer registers
  Wire.beginTransmission(MPU_ADDR); 
  Wire.write(0x3B);             // Starting register for accelerometer readings
  Wire.endTransmission(false); 
  Wire.requestFrom(MPU_ADDR, 6, true); // Request 6 bytes (X, Y, Z)

  // Combine high and low bytes for each axis
  ax = Wire.read() << 8 | Wire.read(); // Accel X
  ay = Wire.read() << 8 | Wire.read(); // Accel Y
  az = Wire.read() << 8 | Wire.read(); // Accel Z

  // Calculate tilt angles using trigonometry
  angleX = atan2(ay, az) * 180.0 / PI; // X angle in degrees
  angleY = atan2(ax, az) * 180.0 / PI; // Y angle in degrees

  angleY = fabs(angleY);               // Use absolute value for cleaner servo control

  // Send angle via HC-12
  HC12.print("Roll Angle: ");
  HC12.println(angleY);

  // Also print to Serial Monitor for debugging
  Serial.print("Roll Angle: ");
  Serial.println(angleY);

  delay(112);   // Delay for stability and lower data rate (approx ~8–9 Hz)
}
