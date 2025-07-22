# ==============================================================================
# attocube systems GmbH 2025
# 
# Script Overview:
# This script connects to a device via IP and streams high-frequency 
# position data for up to three axes. It initializes the stream, reads raw 
# measurement data into a buffer, decodes it, and prints the first 20 samples 
# per axis along with associated error bits. The Stream class is utilized to 
# manage the connection and handle the data flow efficiently.
# ==============================================================================


import os
import sys

folder_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../..'))
sys.path.append(folder_path)

from streaming.stream import Stream

def main():
    deviceIp = "192.168.1.1"
    isMaster = True
    intervalInMicroseconds = 10
    ax0=True
    ax1=True
    ax2=True
    buffer = bytearray(16 * 1024)  # 16 KB buffer
    bufferSize = len(buffer)

    
    senStream = Stream(deviceIp, isMaster, intervalInMicroseconds, axis0=ax0, axis1=ax1, axis2=ax2) 
    senStream.open()
    decodecBytes, axis1, axis2, axis3, err0, err1, err2 = senStream.read(bufferSize)
    
    # slice and print 20 samples each
    print(f"decoded bytes: {decodecBytes} \
          \naxis1: {axis1[:20]} \
          \naxis2: {axis2[:20]} \
          \naxis3: {axis3[:20]} \
          \nerr0: {err0[:20]} \
          \nerr1: {err1[:20]} \
          \nerr2: {err2[:20]}")
    senStream.close()

if __name__ == '__main__':
    main()