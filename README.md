## 🧩 Overview

**Laser Quest** is a two-player collaborative penny arcade game that uses **lasers**, **mirrors**, and **photoresistors**. The goal? Reflect a laser beam using multiple servo-controlled mirrors to hit a moving target. Players must coordinate in real time to succeed, merging **mechatronics**, **optics**, and **game design** into a single engaging project.

---
## Introduction

The proposed project, "Laser Quest" presents a two-player interactive game that leverages the principles of light and reflection to create a collaborative gaming experience. Utilizing Laser technology, the game challenges players to manipulate laser beams using mirrors to hit a moving target. The target's position varies based on the game score, requiring continuous adjustment and coordination between players. Both the players adjust mirrors to direct the beam towards the photoresistor-equipped target. The game mechanics are facilitated by a combination of Arduino microcontrollers, servo motors, rack and pinion, photoresistors, and an ultrasonic sensor showcasing an innovative application of mechatronics and optical principles in a recreational context.

 <img width="450" alt="Laser Quest 2025-05-01 at 6 06 47 PM" src="https://github.com/user-attachments/assets/f2c89d8b-41b3-453f-834c-fd227895ec04" />

 ---
## 🎮 How It Works

- A **laser beam** is manipulated using **servo-mounted mirrors**.
- A **moving target** equipped with **photoresistors** detects when the laser hits.
- **Arduino Mega** controls the game logic and scoring.
- **Arduino Uno** and **joysticks** control mirror angles.
- **Ultrasonic sensor** detects the player to start the game.
- **LCD screen**, **LED indicators**, and a **buzzer** provide game feedback.

---

## Components Used: 
- Arduino Mega: This is the main logic control unit of the project. This controller has the logic to start, carry out the logic and end the game. Each component mentioned below is connected to this controller.
- Photoresistors (GM5539 resistor)
- Resistor
- Ultrasonic Sensor
- LCD Screen 
- LED light
- Buzzer
- Servo motor (SG90)
- Laser module
- Arduino Uno: This Arduino Uno module is used to control the mirrors in the game. This is a smaller Arduino as it doesn’t have a lot of inputs and outputs to process.
- Servo motor (MG996R)
- Joystick Module
---
## Schematic Diagrams
 <img width="450" alt="Screenshot 2025-05-01 at 6 06 47 PM" src="https://github.com/user-attachments/assets/514cc558-89db-433e-b5d4-955dd51a0f7e" />
<img width="450" alt="Screenshot 2025-05-01 at 6 07 04 PM" src="https://github.com/user-attachments/assets/ac7e0a73-ba14-465b-a210-d0bb61c2a85f" />
<img width="450" alt="Screenshot 2025-05-01 at 6 05 13 PM" src="https://github.com/user-attachments/assets/517246d5-f122-4de7-a4a2-e20d6a639adf" />

## 🛠️ Features

- Multiplayer cooperative gameplay
- Dynamic scoring system
- Real-time target movement
- Sensor-based input and feedback
- Real-world application of reflection and control systems

---

## 🗺️ System Architecture

- Arduino Mega controls:  
  - Game logic, photoresistors, servo motor for moving target, LCD, LED, buzzer.
- Arduino Uno controls:  
  - 4 servo motors mounted with mirrors via 4 joystick modules.
- Communication is handled internally; no external transmission protocols used.

---

## Author
- Prajyot Patil (ppatil4@scu.edu) 
