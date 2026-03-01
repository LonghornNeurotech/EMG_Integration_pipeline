
import serial
import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import rfft, rfftfreq
import time

# --- SERIAL SETUP ---
PORT = "COM9"
BAUD = 115200

USE_TEST_SIGNAL = True


# --- FFT SETTINGS ---
N = 512
FS = 5000
buffer = np.zeros(N)

# --- TEST SIGNAL SETTINGS ---
f1 = 440        # first frequency (Hz)
f2 = 1000       # second frequency (Hz)
t = 0
dt = 1 / FS

# --- PLOT SETUP ---
plt.ion()
fig, ax = plt.subplots()
x_freq = rfftfreq(N, 1 / FS)
line, = ax.plot(x_freq, np.zeros(len(x_freq)))

ax.set_ylim(0, 30000)
ax.set_xlim(0, 2000)
ax.set_xlabel("Frequency (Hz)")
ax.set_ylabel("Magnitude")

# --- MAIN LOOP ---
while True:
    try:
        if USE_TEST_SIGNAL:
            # Generate synthetic signal
            value = (
                100 * np.sin(2 * np.pi * f1 * t) +
                60 * np.sin(2 * np.pi * f2 * t) +
                20 * np.random.randn()
            )
            t += dt
            time.sleep(dt)  # simulate real sampling rate
        else:
            value = float(ser.readline().decode().strip())

        # Shift buffer left, add new sample
        buffer[:-1] = buffer[1:]
        buffer[-1] = value

        # FFT
        fft_mag = np.abs(rfft(buffer))

        line.set_ydata(fft_mag)
        fig.canvas.draw()
        fig.canvas.flush_events()

    except ValueError:
        pass