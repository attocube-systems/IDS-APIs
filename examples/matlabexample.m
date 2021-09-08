pause on

IP = '192.168.1.1';

% Setup connection to IDS
ids = connect(IP);

% Measure on axis 1
% Internally, axes are numbered 0 to 2
axis = 0; % Axis 1

% Start alignment
system_startOpticsAlignment(ids);

% Wait until alignment is running
[errNo, adjustmentEnabled] = adjustment_getAdjustmentEnabled(ids);
while ~adjustmentEnabled
    pause(1);
    [errNo, adjustmentEnabled] = adjustment_getAdjustmentEnabled(ids);
end

% Get contrast
[warningNo, contrast, baseline, mixcontent] = adjustment_getContrastInPermille(ids, axis);
fprintf('Contrast: %i, Baseline: %i, Mixcontent: %i', contrast, baseline, mixcontent);

% Stop alignment and start measurement
system_stopOpticsAlignment(ids);
[errNo, currentmode] = system_getCurrentMode(ids);
while ~strcmp(currentMode, 'system idle'):
    time.sleep(1)
    [errNo, currentmode] = system_getCurrentMode(ids);
system_setInitMode(ids, 0); % enable high accuracy mode
system_startMeasurement(ids);

% Wait until measurement is running
[errNo, measurementEnabled] = displacement_getMeasurementEnabled(ids);
while ~measurementEnabled
    pause(1);
    [errNo, measurementEnabled] = displacement_getMeasurementEnabled(ids);
end

% Get position
[warningNo, position] = displacement_getAbsolutePosition(ids, axis);
fprintf("Position %f pm\n", position);

% Stop measurement
system_stopMeasurement(ids);

% Close connection
disconnect(ids);
