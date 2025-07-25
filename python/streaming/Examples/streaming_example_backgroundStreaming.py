# ==============================================================================
# attocube systems GmbH 2025
# 
# Script Overview:
# This script connects to a SEN device via IP, initializes it (if necessary), 
# and records background streaming data for all three axes over 5 seconds. 
# The data is saved to a .aws file, then loaded and visualized using Matplotlib. 
# The script converts position data from picometers to nanometers and plots it 
# over time with appropriate axis formatting. It provides a quick way to test 
# streaming functionality and visualize recorded displacement data.

# Refer to the README.txt on how to run this example
# ==============================================================================

from time import sleep
from matplotlib.ticker import ScalarFormatter
import numpy as np
from ... import SEN
import pandas as pd
import matplotlib.pyplot as plt


def main():
    filename = 'Testing' # name of the .aws file created
    
    sen = SEN.Device('192.168.1.1') #IP of device
    sen.connect()
    deviceType = sen.system.getDeviceType()

    
    if sen.displacement.getMeasurementEnabled() is False:

        print("starting Init")
        sen.system.setInitMode(0) # enable high accuracy mode
        sen.system.startMeasurement()
        
        print("init",end="")
        while not sen.displacement.getMeasurementEnabled():
            print(".",end="")
            sleep(5)
        print("")

    sen.streaming.startBackgroundStreaming(isMaster=True, intervalInMicroseconds=20, bufferSize=2<<3, filePath=filename+'.aws', axis0=True, axis1=True, axis2=True)

    print('Started Backgroundstreaming')
    sleep(5) # time to record
    print('Stop Backgroundstreaming')
    sen.streaming.stopBackgroundStreaming()

    #evalute Data
    ttime,axis0,axis1,axis2,error0,error1,error2 = zip(*sen.streaming.loadFile(filename+".aws")) #load file
    
    #create dataframe
    data = pd.DataFrame()
    
    #add to dataframe
    data['y in nm'] = np.array(axis0)/1000 #change from pm to nm
    data['Time1 in s'] = np.array(ttime)
    data.index = data['Time1 in s']

    # Plot graph
    fig, ax = plt.subplots()
    ax.plot(data['Time1 in s'], data['y in nm'], label='y in nm')

    ax.set_title(deviceType)
    ax.set_xlabel("time(s)")
    ax.set_ylabel("position(nm)")
    ax.yaxis.set_major_formatter(ScalarFormatter(useMathText=True))
    ax.ticklabel_format(style='plain', axis='y')  # Prevent scientific notation
    ax.grid(True)
    plt.tight_layout()
    plt.show()

if __name__ == '__main__':
    main()