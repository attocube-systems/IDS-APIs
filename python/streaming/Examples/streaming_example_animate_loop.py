# ==============================================================================
# attocube systems GmbH 2025
# 
# Script Overview:
# This script connects to a device via IP and streams high-frequency 
# position data for up to three axes. It initializes the stream, using a minimal 
# buffer size based on the stream packet size, the read function is able to read 
# and decode single data frames upon call and visualizes the data in real-time 
# using Matplotlib.
# 
# ==============================================================================

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import os
import sys
folder_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../..'))
sys.path.append(folder_path)

from python.SEN import Device
from streaming.stream import Stream

deviceIp = "192.168.1.1"
SEN = Device(deviceIp) 
SEN.connect()
deviceName = SEN.system_service.getDeviceName()
SEN.close()

isMaster = True
intervalInMicroseconds = 10
ax0=True
ax1=True
ax2=True
SEN_STREAM = Stream(deviceIp, isMaster, intervalInMicroseconds, axis0=ax0, axis1=ax1, axis2=ax2) 
SEN_STREAM.open()

# safe to use packet size as base buffer size for direct decoding, as the API will return 0 decoded bytes if the buffer is too small. 
# For streaming, it is recommended to use a larger buffer to read multiple packets at once and reduce overhead.
BUFFER_SIZE = SEN_STREAM.packetSize * 1
print(f"Using buffer size: {BUFFER_SIZE} bytes")

### plot ###
WINDOW = 60             # seconds visible
MAX_POINTS = 1023 * 60  # max points in buffer
DESIRED_POINTS = 1023   # number of points to actually display

fig, ax = plt.subplots()
ax.set_xlim(WINDOW, 0)
ax.set_xlabel("Time (s)")
ax.set_ylabel("position (nm)")
ax.set_title(deviceName)

# Disable scientific notation
ax.ticklabel_format(useOffset=False, style='plain', axis='y')

line, = ax.plot([], [], lw=1)
x_buffer = np.linspace(WINDOW, 0, MAX_POINTS)  #fixed x-axis: newest on right
y_buffer = np.full(MAX_POINTS, np.nan)         # buffer for y-values
ptr = 0                                        # circular buffer pointer

def updateLine(new_values):
    """
    Updates the line with a new array of values.
    new_values: array of length up to 1023
    """
    global y_buffer, ptr

    sampleCount = len(new_values)

    # Subsample to reduce horizontal compression(optional)
    step = max(1, sampleCount // DESIRED_POINTS)
    y_to_add = new_values[::step]
    n = len(y_to_add)

    print(f"Sample count: {sampleCount}, Subsampling with step: {step}, adding {n} points to buffer")

    # Insert new values into circular buffer
    if ptr + n <= MAX_POINTS:
        y_buffer[ptr:ptr+n] = y_to_add
    else:
        first = MAX_POINTS - ptr
        y_buffer[ptr:] = y_to_add[:first]
        y_buffer[:n-first] = y_to_add[first:]

    ptr = (ptr + n) % MAX_POINTS

    # Prepare y_display so newest values are at the end
    y_display = np.roll(y_buffer, -ptr) 
    y_display = y_display/1000  #convert pm to nm
    x_display = x_buffer

    # Update line
    line.set_data(x_display, y_display)

    # Dynamic y-axis with padding
    y_min = np.nanmin(y_display)
    y_max = np.nanmax(y_display)
    padding = (y_max - y_min) * 0.1
    ax.set_ylim(y_min - padding, y_max + padding)
    return line, ax

def animate(frame):
    if SEN_STREAM is None:
        return None
    #read whenever animate is called, which is theoretically every 50ms in this example 
    decodedBytes, axis1, axis2, axis3, err0, err1, err2 = SEN_STREAM.read(BUFFER_SIZE) 
    if decodedBytes == 0:
        raise Exception("No data read from stream")
    else:
        return updateLine(axis3) #plotting axis 3 as example


if __name__ == "__main__":
    try:
        #1200 frames with 50ms interval
        fig.ani = FuncAnimation(fig, animate, frames=1200, interval=50, blit=False, repeat=False)
        plt.show()
    except KeyboardInterrupt as e:
        print("Stopping animation...")
        plt.close(fig)
        SEN_STREAM.close()
    except Exception as e:
        print("Error in main:", e)
        plt.close(fig)
        SEN_STREAM.close()
    finally:
        print("Closing stream...")
        SEN_STREAM.close()
