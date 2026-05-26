# ==============================================================================
# attocube systems GmbH 2025
# 
# Script Overview:
# This script connects to a device via IP and streams high-frequency 
# position data for up to three axes. It initializes the stream, continuously 
# reads data in a while loop and prints the first 10 samples per axis 
# along with associated error bits.
# 
# 
# ==============================================================================

import os
import sys
import time

folder_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../..'))
sys.path.append(folder_path)

from streaming.stream import Stream
from python.SEN import Device

deviceIp = "192.168.1.1"
isMaster = True
intervalInMicroseconds = 10
ax1=True
ax2=False
ax3=False

SEN_STREAM = Stream(deviceIp, isMaster, intervalInMicroseconds, axis0=ax1, axis1=ax2, axis2=ax3)

def readStream(durationInSecs):
    SEN_STREAM.open()
    packetSize = SEN_STREAM.packetSize
    BUFFER_SIZE = 1 * packetSize  #buffer size for a single packet per read.
    
    start_time = time.time()
    while time.time() - start_time < durationInSecs:
        decodedBytes, axis1, axis2, axis3, err1, err2, err3, temp, humidity, pressure, refractiveIndex = SEN_STREAM.read(BUFFER_SIZE)
        if decodedBytes <= 0:
            print("No more data to read.")
        else:
            print(f"\nDecoded Bytes: {decodedBytes}")
            print(f"temperature: {temp:.2f}°C, humidity: {humidity:.2f}%, pressure: {pressure:.2f}hPA, refractiveIndex: {refractiveIndex:.2f}")
            if ax1:
                print(f"Axis1: {axis1[:10]}\nAxis1 error bits: {err1[:10]}")
            if ax2:
                print(f"Axis2: {axis2[:10]}\nAxis2 error bits: {err2[:10]}")
            if ax3:
                print(f"Axis3: {axis3[:10]}\nAxis3 error bits: {err3[:10]}")


            

if __name__ == "__main__":
    try:
        readStream(5)
    except KeyboardInterrupt:
        print("Streaming interrupted by user.")
    except Exception as e:
        print(f"Error in main: {e}")
    finally:
        SEN_STREAM.close()
