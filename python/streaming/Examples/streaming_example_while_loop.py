# ==============================================================================
# attocube systems GmbH 2025
# 
# Script Overview:
# This script connects to a device via IP and streams high-frequency 
# position data for up to three axes. It initializes the stream, continuously 
# reads data in a while loop within a separate thread and adds the data to a queue. 
# The main thread continuously checks the queue for new data and prints out the 
# length of the queue, the number of samples in the fetched data, and a slice of 
# the first 10 values. 
# 
# ==============================================================================

import queue
import threading
import os
import sys
import time

folder_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../..'))
sys.path.append(folder_path)

from streaming.stream import Stream
from python.SEN import Device

deviceIp = "192.168.1.1"
SEN = Device(deviceIp)
SEN.connect()
deviceName = SEN.system_service.getDeviceName()
SEN.close()

isMaster = True
intervalInMicroseconds = 10
ax1=False
ax2=False
ax3=True

SEN_STREAM = Stream(deviceIp, isMaster, intervalInMicroseconds, axis0=ax1, axis1=ax2, axis2=ax3) 
BUFFER_SIZE = 16 * 1024  #16 KB buffer
print(f"Using buffer size: {BUFFER_SIZE} bytes")

data_queue = queue.Queue()
stop_event = threading.Event()

def read_stream_data(durationInSecs=5):
    SEN_STREAM.open()
    print("Stream opened, starting data thread...")
    start_time = time.time()
    while not stop_event.is_set() and SEN_STREAM.connected:
        decodedBytes, axis1, axis2, axis3, err0, err1, err2 = SEN_STREAM.read(BUFFER_SIZE)
        if decodedBytes <= 0:
            print("No more data to read.")
        else:
            if time.time() - start_time > durationInSecs:
                print("Reached streaming duration limit.")
                break
            data_queue.put(axis3)  # put new samples in queue


if __name__ == "__main__":
    try:
        thread = threading.Thread(target=read_stream_data, daemon=True)
        thread.start()
        while True:
            fetched_values = data_queue.get()
            print(f"length of queue: {data_queue.qsize()}")
            print(f"sample count: {len(fetched_values)}")
            print(f"sliced 10 values: {fetched_values[:10]}")
            time.sleep(1)
    except KeyboardInterrupt:
        stop_event.set()
        thread.join()
        SEN_STREAM.close()
    except Exception as e:
        print(f"Error in main: {e}")
        SEN_STREAM.close()
    finally:
        SEN_STREAM.close()
        stop_event.set()
        thread.join()
