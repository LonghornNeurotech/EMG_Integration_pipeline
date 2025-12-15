# Longhorn Neurotech EMG Signal Processing Pipeline

This project implements a complete EMG (electromyography) signal processing pipeline using a MyoWare sensor and an ESP32 DevKit V1, combining embedded software and Python analysis. The pipeline reads raw analog EMG data, reduces noise, and visualizes the frequency components for research and analysis purposes.  

## Overview

The pipeline consists of two main stages:  

### 1. Embedded System Processing (ESP32 DevKit V1)
- **Raw Data Acquisition:** Reads analog EMG values from a MyoWare sensor using the Arduino IDE `analogRead`.
- **Oversampling & Averaging:** Multiple samples are collected and averaged in software to reduce electromagnetic and thermal noise from the hardware.
- **Data Transmission:** Individual processed samples are sent over serial to Python for further analysis.  

### 2. Python Analysis
- **Discrete FFT:** Converts the time-domain EMG signal to frequency-domain, showing both real and imaginary components.
- **Noise Visualization:** Enables observation of noise components such as power-line interference and ECG-related artifacts.
- **Software Filtering:** Applies various filters (Butterworth, low-pass, high-pass) to reduce remaining noise and highlight relevant EMG activity.
- **Plotting & Analysis:** Interactive visualization of frequency-domain signals to study muscle activation patterns and signal quality.

## Features
- Reduces hardware noise using software oversampling and averaging.
- Provides both time-domain and frequency-domain views of EMG signals.
- Supports multiple software filters for flexible signal cleaning.
- Visualizes real vs imaginary FFT components and their noise characteristics.
- Helps identify common noise sources, including power-line interference and physiological artifacts.

## Getting Started
1. Connect the MyoWare sensor to the ESP32 DevKit V1.
2. Load the Arduino sketch to the ESP32 using the Arduino IDE.
3. Open the Python script to receive data, perform FFT, filter signals, and visualize results.

## Dependencies
- Arduino IDE
- Python 3.x
- NumPy
- SciPy
- Matplotlib
- PySerial (for serial communication)

## Applications
- EMG signal analysis for research and rehabilitation.
- Real-time muscle activity monitoring.
- Educational tool for signal processing and embedded systems.

## Authors
- Longhorn Neurotech Team
