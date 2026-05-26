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
ax1=False
ax2=False

SEN_STREAM = Stream(deviceIp, isMaster, intervalInMicroseconds, axis0=ax0, axis1=ax1, axis2=ax2) 
SEN_STREAM.open()

# safe to use packet size as base buffer size for direct decoding, as the API will return 0 decoded bytes if the buffer is too small. 
BUFFER_SIZE = SEN_STREAM.packetSize * 1 

### plot ###
WINDOW = 60
MAX_POINTS = 1023 * 60
DESIRED_POINTS = SEN_STREAM.samplesPerPacket

print(f"Using buffer size: {BUFFER_SIZE} bytes, which corresponds to {SEN_STREAM.samplesPerPacket} samples per read")

numberOfAxes = sum([ax0, ax1, ax2])
print(f"Plotting {numberOfAxes} axes")
fig, axes = plt.subplots(numberOfAxes, 1, sharex=True)
axes = np.atleast_1d(axes)

lines = []
buffers = []
ptrs = []

for i, ax in enumerate(axes):
    ax.set_xlim(WINDOW, 0)
    ax.set_ylabel(f"axis {i+1} (nm)")
    ax.ticklabel_format(useOffset=False, style='plain', axis='y')

    line, = ax.plot([], [], lw=1)
    lines.append(line)

    buffers.append(np.full(MAX_POINTS, np.nan))
    ptrs.append(0)

axes[-1].set_xlabel("Time (s)")
axes[0].set_title(deviceName)

x_display = np.linspace(WINDOW, 0, MAX_POINTS)


def updateLine(axis_data):
    """
    axis_data = [axis1, axis2, axis3]
    """
    global buffers, ptrs

    for idx, new_values in enumerate(axis_data):

        sampleCount = len(new_values)

        # Subsample to reduce horizontal compression(optional)
        step = max(1, sampleCount // DESIRED_POINTS)
        y_to_add = new_values[::step]
        n = len(y_to_add)

        print(f"Sample count: {sampleCount}, Subsampling with step: {step}, adding {n} points to buffer")

        # insert into circular buffer
        ptr = ptrs[idx]
        y_buffer = buffers[idx]

        if ptr + n <= MAX_POINTS:
            y_buffer[ptr:ptr+n] = y_to_add
        else:
            first = MAX_POINTS - ptr
            y_buffer[ptr:] = y_to_add[:first]
            y_buffer[:n-first] = y_to_add[first:]

        ptr = (ptr + n) % MAX_POINTS

        buffers[idx] = y_buffer
        ptrs[idx] = ptr

        # Prepare y_display so newest values are at the end; convert from pm to nm
        y_display = np.roll(y_buffer, -ptr) / 1000

        # Update line
        lines[idx].set_data(x_display, y_display)

        # Dynamic y-axis with padding
        y_min = np.nanmin(y_display)
        y_max = np.nanmax(y_display)
        padding = (y_max - y_min) * 0.1 if y_max != y_min else 1

        axes[idx].set_ylim(y_min - padding, y_max + padding)

    return lines


def animate(frame):
    if SEN_STREAM is None:
        return None
    
    #read whenever animate is called, which is theoretically every 50ms in this example 
    decodedBytes, axis1, axis2, axis3, err0, err1, err2, *ecu = SEN_STREAM.read(BUFFER_SIZE)
    if decodedBytes == 0:
        raise Exception("No data read from stream")

    axis_data = []
    if ax0:
        axis_data.append(axis1)
    if ax1:
        axis_data.append(axis2)
    if ax2:
        axis_data.append(axis3)
    
    return updateLine(axis_data)


if __name__ == "__main__":
    try:
        #1200 frames with 50ms interval
        fig.ani = FuncAnimation(
            fig,
            animate,
            frames=1200,
            interval=50,
            blit=False,
            repeat=False
        )

        plt.tight_layout()
        plt.show()

    except Exception as e:
        print(e)