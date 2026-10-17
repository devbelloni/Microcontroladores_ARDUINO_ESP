# Embedded and IoT Portfolio: Arduino, ESP8266, ESP32, LoRa

A collection of microcontroller sketches (C++/Arduino) covering wireless communication,
sensing and user interfaces. Each folder is a self-contained sketch.

## Contents

| Area | Folders |
|---|---|
| **Wi-Fi (ESP8266 / NodeMCU)** | `ESP8266/` (Wi-Fi scan and a Wi-Fi TCP server), `IR_nodemu_webserver/` (web server driving an IR emitter), `nodemcu_testa_pinos/` |
| **MQTT (ESP32)** | `ESP32_MQTT_Sensor_LED/`: publishes sensor data and controls an LED through an MQTT broker (separate Wi-Fi, MQTT and data-sending modules) |
| **LoRa radio** | `Transmissor/`, `Receptor/`, `Teste_Emissor_LORA/`, `Teste_Emissor_potenciometro_LORA/`, `LoRa_Potentiometer_Emitter_v2/`, `Teste_Receptor_LORA/` |
| **Infrared remote** | `TesteIR/`, `TesteIResp/`, `Controle_remoto_com_uno/` (Arduino Uno with a matrix keypad) |
| **Displays and sensors** | `OLEDESP8266/`, `TESTE_OLED/`, `Medidor_de_distancia/` (ultrasonic distance with an LCD), `I2C_SCANER/` |
| **Serial and data** | `TESTE COMUNICA SERIAL/`, `teste_separa_string/`, `Excell/`, `keyboard/` |

## Hardware

Arduino Uno, ESP8266 (NodeMCU), ESP32, LoRa Mesh radios, HC-SR04 ultrasonic sensor,
IR emitter and receiver, matrix keypad, OLED and LCD displays.

## Using the sketches

Open a `.ino` file in the Arduino IDE (or PlatformIO), install the libraries named in its
`#include` lines, and select the right board. Sketches that connect to Wi-Fi contain the
placeholders `YOUR_WIFI_SSID` and `YOUR_WIFI_PASSWORD`; replace them with your own network
credentials and never commit real ones.

## Author

**Márcio Belloni**, AI/ML Engineer with an electrical and computer engineering background.
[LinkedIn](https://www.linkedin.com/in/marcio-belloni/) · [GitHub](https://github.com/devbelloni)
