# Hey-Auxi-Your All in One  home companion
Feature Highlights
On-Device AI with Edge Processing – Real-time face, gesture, and voice recognition with ultra-low latency on NXP’s i.MX RT117H MCU.
Far-Field Voice Recognition – Precise DSP-enhanced voice tracking, enabling seamless hands-free interaction even in noisy environments.
AI-Powered Security & Personalization – Facial ID-based user authentication for personalized automation and enhanced home security.
Gesture-Based Control – Advanced ML-powered gesture recognition for touchless smart home operation and accessibility support.
Adaptive Smart Home Automation – Learns user behavior to intelligently control lighting, climate, and appliances, optimizing energy efficiency.
Emotion-Aware AI Assistant – Real-time emotion detection and empathetic responses for intuitive human-machine interaction.
Assistive Technology for Accessibility – Hands-free voice commands, emergency alerts, and gesture-based control for elderly and disabled users.
Multi-Protocol Connectivity – Supports Wi-Fi, Zigbee, Bluetooth, NFC, and secure cloud integration for seamless device communication.
AI-Enhanced Learning & Interaction – Multimodal engagement (voice, vision, gestures) for interactive education and adaptive content delivery.
Ultra-Efficient Embedded AI – AI-driven processing optimized for low power consumption, ensuring continuous operation.

![Block_diagram](https://github.com/user-attachments/assets/2aef4133-d6e0-4fdf-ac3e-16d780be0105)

Project Title:
Hey Auxi – An Intelligent IoT-Powered Multi-Functional Assistant Robot
Abstract:
Hey Auxi is a voice-activated, gesture-controlled, AI-enabled robotic assistant integrated with IoT functionalities. Designed to serve as a multifunctional smart home companion, it brings together embedded systems, computer vision, wireless communication, and modular robotics. Auxi not only monitors health and environmental conditions but also controls smart devices via Blynk, acting as a central hub for interaction and automation. It is modular, scalable, and demonstrates a wide range of real-world applications.

🔗 Live Demonstration Video

Key Features:
🔊 Voice Command Interface
Responds to natural voice inputs.

Initiates various modes: Health, Cleaning, Gaming, IoT, Demo.

Talks back using a speaker for interactive feedback.

🧠 IoT Control via Blynk
Integrated with Blynk app for controlling external smart devices.

Can turn on/off appliances like lights, fans, etc.

Real-time control and monitoring through mobile.

🎮 Gesture Recognition Module
Rock-Paper-Scissors game using camera and hand gesture recognition.

Adds fun, interactive learning element.

🌡️ Smart Health & Environment Monitoring
Pulse and Body Temperature: IR sensor + LM35.

Room Conditions: DHT11 (temp & humidity), MQ gas sensor (air quality).

Data Transmission:

ESP32-to-ESP32 via Wi-Fi.

Bluetooth output via HC-05 to external devices.

🚗 Autonomous Cleaning Rover
A separate 6-wheeled ESP32-powered bot for cleaning tasks.

Controlled via voice or scheduled operation.

📺 Display Output
OLED screen displays live vitals, air quality, bot mode, etc.

🧪 Demo Mode
Activated by voice: “Hey Auxi, start demo”.

Self-runs all features while explaining functions.

System Architecture Overview:
Component	Function
NXP Board	Master controller, speaker output, motor logic
ESP32 #1	Health data acquisition (LM35, pulse)
ESP32 #2	Environment sensing + Bluetooth + Blynk
ESP32 #3	Cleaning rover control
HC-05	Bluetooth communication with external devices
Camera Module	Gesture recognition (OpenCV-enabled)
OLED Display	Visual feedback for vitals and system status

Communication Architecture:
Wi-Fi: ESP32 modules share sensor data internally.

Bluetooth: Mobile devices request data using trigger strings (##iot1## etc.).

Cloud (via Blynk): Device control and feedback via mobile app.

IoT Applications:
Real-time device switching via smartphone using Blynk app.

Expandable to include smart lights, alarms, or energy meters.

Full duplex command-feedback loop between bot and user.

Demonstration & Video:
Watch the system in action demonstrating voice, gesture, cleaning, health monitoring, and IoT control:
▶️ https://youtu.be/H7OEfFrr-FE

Software Stack:
Arduino/PlatformIO

FreeRTOS

OpenCV (if external vision unit used)

Blynk for IoT integration

C/C++ & Python (for various control layers)

Conclusion:
"Hey Auxi" is a compact, feature-rich demonstration of what embedded systems and IoT can achieve when merged effectively. Its integration with Blynk brings real-world IoT capability, enabling smart home control directly from the bot. With autonomous features, modular expansion, and intuitive interaction, it is a powerful prototype of future assistive and smart robots.

