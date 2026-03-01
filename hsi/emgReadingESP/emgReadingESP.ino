
#include "BluetoothSerial.h"


BluetoothSerial SerialBT;


// ===== EMG CONFIG =====
const int emgPin = 34;        // ADC1 pin (safe with BT)
const int SAMPLE_RATE = 5000; // Hz
const int AVG_FACTOR  = 64;   // Over-averaging factor


// ===== TIMER CONFIG =====
hw_timer_t* sampletimer = NULL;


// ===== SHARED DATA =====
volatile uint16_t averagedSample = 0;


// ===== TIMER ISR =====
void IRAM_ATTR onSampleTimer() {
  averagedSample = analogRead(emgPin);
  SerialBT.println(averagedSample);


 
}


void setup() {
  Serial.begin(115200);


  // Bluetooth start
  SerialBT.begin("ESP32_EMG");
 // Serial.println("Bluetooth started. Pair with ESP32_EMG");


  pinMode(emgPin, INPUT);


  // ADC settings (important for EMG)
  //analogReadResolution(12);          // 0–4095
  //analogSetAttenuation(ADC_11db);    // Full range ~3.3V


  // ===== TIMER SETUP =====
  sampletimer = timerBegin(80000000);
  // 80 MHz / 80 = 1 MHz → 1 tick = 1 µs


  timerAttachInterrupt(sampletimer, &onSampleTimer);
  timerAlarm(sampletimer, 80000000/SAMPLE_RATE, true, 0);
  //timerAlarmWrite(sampletimer, 80000000 / SAMPLE_RATE, true);
}
