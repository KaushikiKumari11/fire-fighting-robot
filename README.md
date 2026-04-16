# Fire-Fighting Robot using Arduino Uno

## Overview

This project presents the design and development of an autonomous fire-fighting robot capable of detecting and extinguishing fire with minimal human intervention. The system is built using an Arduino Uno microcontroller, flame sensors, and a water pump mechanism.

The robot is designed to operate in hazardous environments such as industrial areas, confined spaces, or fire-prone zones, reducing risks to human life.

---

## Objectives

- Detect fire using infrared flame sensors  
- Navigate autonomously toward the fire source  
- Extinguish fire using a water pump system  
- Provide manual control as a backup mode  

---

## Features

- Autonomous fire detection and suppression  
- Differential drive navigation system  
- Servo-controlled water spraying mechanism  
- Manual control support via serial commands  
- Portable battery-powered system  

---

## Components Used

### Hardware

- Arduino Uno  
- Flame Sensors (IR-based)  
- DC Motors  
- L298N Motor Driver  
- Servo Motor  
- Submersible Water Pump  
- Robot Chassis with Wheels  
- Li-ion Battery  

### Software

- Arduino IDE  
- Embedded C / Arduino Programming  
- Fritzing (for circuit design)  

---

## Working Principle

The robot operates in three main stages:

### 1. Fire Detection

Flame sensors continuously monitor the environment and detect fire using infrared radiation.

### 2. Navigation

Based on sensor readings, the Arduino determines the direction of the fire and controls the motors to move the robot toward the source.

### 3. Fire Extinguishing

Once the robot reaches close to the fire:

- Motors stop  
- Servo motor aligns the nozzle  
- Water pump activates to extinguish the fire  

---

## Control Modes

### Autonomous Mode ('S')

- Detects fire automatically  
- Moves toward fire  
- Activates pump when fire is near  

### Manual Mode

| Command | Action      |
|--------|--------------|
| F      | Move Forward |
| B      | Move Backward|
| L      | Turn Left    |
| R      | Turn Right   |
| V      | Spray Water  |

---

## Circuit Connections (Summary)

- Flame Sensors → A0, A1, A2  
- Motor Driver → Digital Pins (5, 6, 9, 10)  
- Servo Motor → Pin 3  
- Water Pump → Pin 7  

---

## Code Structure

The Arduino code is divided into:

- Setup Function  
  - Initializes pins and components  

- Loop Function  
  - Handles autonomous and manual modes  

- Movement Functions  
  - Forward, backward, left, right  

- Spray Function  
  - Controls pump and servo motion  

---

## Testing and Results

- Successfully detected fire using flame sensors  
- Robot navigated toward fire source accurately  
- Water pump effectively extinguished small flames  
- Issues like voltage fluctuation were resolved using better regulation  

---

## Challenges Faced

- Voltage drops due to high current components  
- Electrical noise from motors affecting sensors  
- Calibration of flame sensors  

---

## Future Enhancements

- Integration with IoT for remote monitoring  
- Use of thermal cameras for better detection  
- AI-based navigation and obstacle avoidance  
- Advanced extinguishing systems (CO₂, foam)  

---

## Applications

- Industrial fire safety  
- Hazardous environment monitoring  
- Disaster response systems  
- Smart firefighting systems  

---

## License

This project is developed for academic purposes and is open for learning and research use.

---
