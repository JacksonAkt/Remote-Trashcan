# Remote-Trashcan
A normal trashcan that can be controlled via remote control. Created by me who find it annoying to get out of bed to dump trash

⚡ Electrical Systems

This project implements a remote-controlled trash can lid using an infrared (IR) communication system and a servo motor for mechanical actuation. An IR receiver module is used to detect signals from a handheld remote and send them to an Arduino Uno for processing.

Microcontroller: Arduino Uno R3
Components: IR module + random remote control, DS3230 High_Torque Servo motor
Circuit: Wiring system
Communication Protocol: Infrared Remote

The system includes:

An IR receiver module connected to the Arduino for wireless signal input
A high-torque DS3230 (30 kg·cm) servo motor used to control lid movement
A mechanical string-pull setup that converts servo rotation into linear motion to open and close the lid
Power and signal connections between the Arduino, IR module, and servo

The servo motor provides enough torque to reliably move the lid, while the IR module enables wireless control without physical contact.


💻 Software

The system is programmed in C++ using the Arduino IDE. The software reads IR signals from the remote and controls the servo motor based on the received commands.

Key features:

IR signal decoding to detect specific remote button presses 
Mapping of remote inputs to actions (open and close lid)
Servo control using PWM signals to adjust position
Simple and modular code structure for easy modification

The program allows the user to open and close the trash can lid remotely, demonstrating integration of wireless communication, microcontroller control, and mechanical actuation.
