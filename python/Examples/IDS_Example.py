from ids_api import SEN # IDS API is the folder, in which the API is located.

import time

IP = "192.168.1.1" # IP of the IDS device
checkAlignment = True
data_samples = 10

# Setup connection to IDS
ids = SEN.Device(IP)
ids.connect()
   
axis = 0 # Internally, axes are numbered 0 to 2

ids.displacement.setAverageN(14) # this is important: it sets the average of the IDS displacement 

# check alignment
if checkAlignment:
    if ids.system.getCurrentMode() == 'measurement running':
        ids.system.stopMeasurement()
        time.sleep(3)
        
    if ids.system.getCurrentMode() == "system idle":
        ids.system.startOpticsAlignment()
        while ids.system.getCurrentMode() == 'optics alignment starting':
            time.sleep(1)
    for i in range(5):
        print("Alignment: ", ids.adjustment.getContrastInPermille(axis))
    ids.system.stopOpticsAlignment()
    time.sleep(5)
    

# check if the IDS measurement is running and start the measurement: 
if ids.system.getCurrentMode() != 'measurement running':
    if ids.system.getCurrentMode() == "optics alignment running":
        ids.system.stopOpticsAlignment()
        time.sleep(3)
    if ids.system.getCurrentMode() == "system idle":
        ids.system.startMeasurement()
        time.sleep(1)
        print('measurement will be started')
        while ids.system.getCurrentMode() == "measurement starting":
            time.sleep(2)

if ids.system.getCurrentMode() != 'measurement running':
    raise Exception("IDS not in measurement mode. Please check mode!")

# readout data
for i in range(data_samples):
    error, value = ids.displacement.getAxisDisplacement(axis)
    print("Displacement: ", value)
    time.sleep(0.5)    
    
# turn off measurement mode
ids.system.stopMeasurement()

ids.close()
