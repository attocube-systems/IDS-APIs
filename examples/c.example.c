#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "attocubeJSONCall.h"
#include "generatedAPI.h"

int main ()
{
    const char* ip = "192.168.1.1";
    int ids = 0;

    Connect(ip, &ids);

    // Measure on axis 1
    // Internally, axes are numbered 0 to 2
    int axis = 0; // Axis 1

    // Start alignment
    IDS_system_startOpticsAlignment(ids);

    // Wait until alignment is running
    bool adjustmentRunning;
    IDS_adjustment_getAdjustmentEnabled(ids, &adjustmentRunning);
    while (!adjustmentRunning) {
        sleep(1);
        IDS_adjustment_getAdjustmentEnabled(ids, &adjustmentRunning);
    }

    // Get contrast
    int warningNo, contrast, baseline, mixcontent;
    IDS_adjustment_getContrastInPermille(ids, axis, &warningNo, &contrast, &baseline, &mixcontent);
    printf("Contrast: %i, Baseline: %i, Mixcontent: %i\n", contrast, baseline, mixcontent);

    // Stop alignment and start measurement
    IDS_system_stopOpticsAlignment(ids);
    char systemState[32];
    IDS_system_getCurrentMode(ids, systemState, 32);
    while (strcmp(systemState, "system idle") != 0) {
        sleep(1);
        IDS_system_getCurrentMode(ids, systemState, 32);
    }
    IDS_system_setInitMode(ids, 0); // enable high accuracy mode
    IDS_system_startMeasurement(ids);

    // Wait until measurement is running
    bool measurementRunning;
    IDS_displacement_getMeasurementEnabled(ids, &measurementRunning);
    while (!measurementRunning) {
        sleep(1);
        IDS_displacement_getMeasurementEnabled(ids, &measurementRunning);
    }

    // Get position
    double position;
    IDS_displacement_getAbsolutePosition(ids, axis, &warningNo, &position);
    printf("Position %f pm\n", position);

    // Stop measurement
    IDS_system_stopMeasurement(ids);

    Disconnect(ids);
}
