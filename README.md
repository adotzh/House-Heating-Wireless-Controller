# House-Heating-Wireless-Controller
This project creates a wireless controller for managing a house heating system through a web interface.

## Hardware Requirements
- ESP8266 or ESP32 microcontroller
- Relay module (if controlling a high-power heating system)
- Temperature sensor (optional, for reading current room temperature)
- Jumper wires
- Power supply for the microcontroller

## Software Requirements
- Arduino IDE (https://www.arduino.cc/en/software)

## Installation and Setup
1. Install the Arduino IDE on your computer.
2. Connect your ESP8266 or ESP32 microcontroller to your computer via USB.
3. Open the `House_Heating_Controller.ino` sketch in the Arduino IDE.
4. Update the following variables in the sketch with your Wi-Fi credentials:
    ```cpp
    const char* ssid = "YourWiFiSSID";
    const char* password = "YourWiFiPassword";
    ```
5. Install the necessary libraries through the Arduino Library Manager:
   - ESP8266WiFi
   - ESP8266WebServer (for ESP8266) or WebServer (for ESP32)
6. Select the appropriate board and port from the Arduino IDE's Tools menu.
7. Upload the sketch to your microcontroller.


## Usage
1. Once the sketch is uploaded, open the Serial Monitor in the Arduino IDE to view the IP address of the microcontroller.
2. Enter this IP address in a web browser to access the heating system controller interface.
3. The interface displays the current status of the heating system and provides a button to toggle its state.

## Deploying the Web Server
- Connect the relay module to the microcontroller's GPIO pins to control the heating system.
- Ensure the microcontroller is powered on and connected to your Wi-Fi network.
- Access the controller interface through the microcontroller's IP address in a web browser to control the heating system remotely.
