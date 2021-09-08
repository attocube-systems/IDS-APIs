import IDS

import time

IP = "192.168.1.1"

# Setup connection to IDS
ids = IDS.Device(IP)
ids.connect()

# Measure on axis 1
# Internally, axes are numbered 0 to 2
axis = 0 # Axis 1

# Start alignment
ids.system.startOpticsAlignment()

# Wait until alignment is running
while not ids.adjustment.getAdjustmentEnabled():
    time.sleep(1)

# Get contrast
warningNo, contrast, baseline, mixcontent = ids.adjustment.getContrastInPermille(axis)
print("Contrast:", contrast, "Baseline:", baseline, "Mixcontent:", mixcontent)

# Stop alignment and start measurement
ids.system.stopOpticsAlignment()
while ids.system.getCurrentMode() != "system idle":
    time.sleep(1)
ids.system.setInitMode(0) # enable high accuracy mode
ids.system.startMeasurement()

# Wait until measurement is running
while not ids.displacement.getMeasurementEnabled():
    time.sleep(1)

# Get position
warningNo, position = ids.displacement.getAbsolutePosition(axis)
print("Position:", position, "pm")

# Stop measurement
ids.system.stopMeasurement()

# Close connection
ids.close()
