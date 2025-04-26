# MPU6050-Based Roll Angle Control via HC-12 and Servo Motor

## Overview
This project utilizes an **MPU6050** motion sensor to calculate the **roll angle** of a surface, which is then transmitted wirelessly using **HC-12** modules. A separate receiver module receives the angle and controls a **servo motor** based on the data. This setup serves as a simple yet effective demonstration of real-time sensor-actuator communication.

---

## Features
- Computes **roll angle** using accelerometer data from MPU6050
- Transmits angle data wirelessly using HC-12 modules
- Receives data and actuates a servo motor accordingly
- Modular code for **transmitter** and **receiver**
- Real-time and responsive control

---

## Components Required

| Component                  | Quantity |
|---------------------------|----------|
| Arduino / ESP8266 (Tx)    | 1        |
| Arduino / ESP8266 (Rx)    | 1        |
| MPU6050 Module            | 1        |
| HC-12 Wireless Modules    | 2        |
| Servo Motor (e.g., SG90)  | 1        |
| Jumper Wires              | —        |
| Breadboard (Optional)     | —        |

---

## Transmitter Side

### Functionality
- Reads accelerometer values from the MPU6050 over I2C
- Calculates the roll angle using trigonometric functions
- Sends the angle via the HC-12 module in a formatted string (e.g., `s55e`)

### Wiring
**MPU6050:**
- VCC → 3.3V  
- GND → GND  
- SDA → A4 (or D2 for ESP8266)  
- SCL → A5 (or D1 for ESP8266)

**HC-12:**
- VCC → 5V  
- GND → GND  
- TX → Pin 10  
- RX → Pin 11  

---

## Receiver Side

### Functionality
- Listens for incoming angle data via the HC-12 module
- Parses the data between the prefix `s` and terminator `e`
- Converts the string to an integer
- Controls the servo motor using the received angle

### Wiring
**HC-12:**
- VCC → 5V  
- GND → GND  
- TX → Pin 10  
- RX → Pin 11  

**Servo Motor:**
- Signal → Pin 9  
- VCC → 5V  
- GND → GND  

---

## Applications
- Wireless gesture-controlled systems
- Basic remote robotic actuators
- Educational projects on motion sensing and control
- Gimbal or camera stabilization mechanisms

---

## Troubleshooting
- **Data not received:**
  - Confirm matching baud rates and proper antenna placement on HC-12 modules
  - Ensure clear line-of-sight or minimal interference
- **Servo doesn't respond:**
  - Check if the servo has sufficient power
  - Make sure the angle received is within valid bounds (typically 0–180°)

---

## License
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

## Contact
- **Email**: [keninish7965@gmail.com](mailto:keninish7965@gmail.com)  
- **LinkedIn**: [Nishant Keni](https://www.linkedin.com/in/nishantkeni)

---

## To Do
- Add pitch angle or full 3-axis tracking
- Integrate OLED for visual feedback
- Apply low-pass filtering to smooth motion data
