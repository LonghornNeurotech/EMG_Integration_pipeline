#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// EMG signal pin (use an ADC1 pin — required for stable BT operation)
const int emgPin = 25;  // GPIO36 = ADC1_CH0

void setup() {
  Serial.begin(115200);

  // Start Bluetooth with device name
  SerialBT.begin("ESP32_EMG");
  Serial.println("Bluetooth started. Pair with device named ESP32_EMG");

  pinMode(emgPin, INPUT);
}

void loop() {
  // Read EMG value from MyoWare (0–4095)
  int emgValue = analogRead(emgPin);

  // Send value via Bluetooth
  SerialBT.println(emgValue);

  delay(5);  // ~200 samples/sec (adjust for smoother/faster streaming)
}