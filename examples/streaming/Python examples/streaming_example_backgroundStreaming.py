# ==============================================================================
# attocube systems GmbH 2025
# 
# Script Overview:
# This script connects to an IDS device via IP, initializes it (if necessary), 
# and records background streaming data for all three axes over 5 seconds. 
# The data is saved to a .aws file, then loaded and visualized using Plotly. 
# The script converts position data from picometers to nanometers and plots it 
# over time with appropriate axis formatting. It provides a quick way to test 
# streaming functionality and visualize recorded displacement data.
# ==============================================================================

from time import sleep
from matplotlib.ticker import ScalarFormatter
import numpy as np
import sys
import os
folder_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../..'))
sys.path.append(folder_path) #append containing folder to be able to import IDS
import IDS
import pandas as pd
import plotly.graph_objects as go

def main():
    filename = 'Testing' # name of the .aws file created
    
    ids = IDS.Device('192.168.1.1') #IP of IDS
    ids.connect()
    deviceType = ids.system.getDeviceType()

    
    if ids.displacement.getMeasurementEnabled() is False:

        print("starting Init")
        ids.system.setInitMode(0) # enable high accuracy mode
        ids.system.startMeasurement()
        
        print("init",end="")
        while not ids.displacement.getMeasurementEnabled():
            print(".",end="")
            sleep(5)
        print("")

    ids.streaming.startBackgroundStreaming(isMaster=True, intervalInMicroseconds=20, bufferSize=2<<3, filePath=filename+'.aws', axis0=True, axis1=True, axis2=True)

    print('Started Backgroundstreaming')
    sleep(5) # time to record
    print('Stop Backgroundstreaming')
    ids.streaming.stopBackgroundStreaming()

    #evalute Data
    ttime,axis0,axis1,axis2,error0,error1,error2 = zip(*ids.streaming.loadFile(filename+".aws")) #load file
    
    #create dataframe
    data = pd.DataFrame()
    
    #add to dataframe
    data['y in nm'] = np.array(axis0)/1000 #change from pm to nm
    data['Time1 in s'] = np.array(ttime)
    data.index = data['Time1 in s']

    # Create the figure
    fig = go.Figure()

    # Add the plot
    fig.add_trace(go.Scatter(x=data['Time1 in s'], y=data['y in nm'], mode='lines'))

    # Customize the layout (optional)
    fig.update_layout(
        title=deviceType,
        xaxis_title="time(s)",
        yaxis_title="position(nm)",
        yaxis=dict(tickformat=",.0f")  # Use thousands separator for better readability
    )

    # Show the plot
    fig.show()


if __name__ == '__main__':
    main()