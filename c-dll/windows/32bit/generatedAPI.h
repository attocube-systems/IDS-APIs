   

/**

    Copyright (C) 2020 attocube systems AG

    

    Usage is up to a separate agreement

*/



/**

 * @file generatedAPI.h

 * @brief API for use with attocube devices

 *

*/



// The generated API could look like this



#ifndef __GENERATEDAPI_H__

#define __GENERATEDAPI_H__



#include <stdbool.h>



#include "attocubeJSONCall.h"



#ifdef __cplusplus

extern "C" {

#endif







/** @brief @IDS_adjustment_getAdjustmentEnabled
*
*  This function can be used to see if the adjustment is running
*
*  @param  deviceHandle  Handle of device
*  @param  enable: enable true = enabled; false = disabled
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_adjustment_getAdjustmentEnabled(int deviceHandle, bool* enable);






/** @brief @IDS_adjustment_getContrastInPermille
*
*  This function can be used to monitor the alignment contrast (peak-to-peak of the 
           basic interference signal amplitude) and the basline (its offset) during alignment 
           mode. It is used to monitor and optimize the optical alignment such that it allows the 
           successful initialization of a measurement. To monitor the optical contrast during a 
           running measurement, please use the getAxisSignalQuality function.
           
           Important: The baseline and contrast needs to be added, otherwise an overload can 
           occure without being recognized. Example: baseline 15permille and contrast 850permille. Just 
           from the contrast it looks good. Adding the baseline the overload is visible.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  Axis to get the value from [0..2]
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  contast: contast Contrast of the base band signal in permille
*  @param  baseline: baseline Offset of the contrast measurement in permille
*  @param  mixcontrast: mixcontrast lower contrast measurment when measuring a mix contrast (indicated by error code)
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_adjustment_getContrastInPermille(int deviceHandle, int axis, int* warningNo, int* contast, int* baseline, int* mixcontrast);






/** @brief @IDS_axis_apply
*
*  Applies new axis settings. Necessary after JSON set commands.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_axis_apply(int deviceHandle);






/** @brief @IDS_axis_discard
*
*  Discards new axis settings. Necessary after JSON set commands instead of apply() in case of failure.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_axis_discard(int deviceHandle);






/** @brief @IDS_axis_getMasterAxis
*
*  Returns the master axis (for more information please refer to the IDS User Manual).
            ADD MORE INFO
*
*  @param  deviceHandle  Handle of device
*  @param  masteraxis: masteraxis Axis which is operating as masteraxis [0..2]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_axis_getMasterAxis(int deviceHandle, int* masteraxis);






/** @brief @IDS_axis_getPassMode
*
*  Reads out the current pass mode.
*
*  @param  deviceHandle  Handle of device
*  @param  mode: mode 0 = single; pass 1 = dual pass
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_axis_getPassMode(int deviceHandle, int* mode);






/** @brief @IDS_axis_setMasterAxis
*
*  Sets the master axis (for more information please refer to the IDS User Manual).
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  Axis which is operating as masteraxis [0..2]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_axis_setMasterAxis(int deviceHandle, int axis);






/** @brief @IDS_axis_setPassMode
*
*  Sets the desired pass mode. Effectively this mode defines, if the correction factor of two (necessary for measurements in optical dual pass configuration) is applied.
*
*  @param  deviceHandle  Handle of device
*  @param  mode:  0 = single pass; 1 = dual pass
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_axis_setPassMode(int deviceHandle, int mode);






/** @brief @IDS_displacement_getAbsolutePosition
*
*  The absolute position information is estimated at the measurement initialization procedure. 
           This initial absolute position information is not updated during system 
           operation, whereas the IDS continuously measures the relative displacement from 
           that point. This function outputs the sum of the static absolute position register value 
           and the continuously updated displacement register value for a single axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  position: position position of the axis in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getAbsolutePosition(int deviceHandle, int axis, int* warningNo, double* position);






/** @brief @IDS_displacement_getAbsolutePositions
*
*  The absolute position information is estimated at the measurement initialization 
           procedure. This initial absolute position information is not updated during system 
           operation, whereas the IDS continuously measures the relative displacement from 
           that point. This function outputs the sum of the static absolute position register value 
           and the continuously updated displacement register value for all three axes.
*
*  @param  deviceHandle  Handle of device
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  position0: position0 position of the axis 0 in pm
*  @param  position1: position1 position of the axis 1 in pm
*  @param  position2: position2 position of the axis 2 in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getAbsolutePositions(int deviceHandle, int* warningNo, double* position0, double* position1, double* position2);






/** @brief @IDS_displacement_getAverageN
*
*  Reads-out the averaging (lowpass) parameter N. The averaging time is calculated by 
           (2^N)*40ns, where N is the averaging value. Please refere to the manual for a table with stopband and 3dB cut-off frequency.
*
*  @param  deviceHandle  Handle of device
*  @param  averageN: averageN A value from 0 to 24
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getAverageN(int deviceHandle, int* averageN);






/** @brief @IDS_displacement_getAxesDisplacement
*
*  Reads out the displacement values of all three measurement axes.
*
*  @param  deviceHandle  Handle of device
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  displacement0: displacement0 displacement of the axis 0 in pm
*  @param  displacement1: displacement1 displacement of the axis 1 in pm
*  @param  displacement2: displacement2 displacement of the axis 2 in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getAxesDisplacement(int deviceHandle, int* warningNo, double* displacement0, double* displacement1, double* displacement2);






/** @brief @IDS_displacement_getAxisDisplacement
*
*  Reads out the displacement value of a specific measurement axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  displacement: displacement Displacement of the axis in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getAxisDisplacement(int deviceHandle, int axis, int* warningNo, double* displacement);






/** @brief @IDS_displacement_getAxisSignalQuality
*
*  This function can be used to monitor the alignment contrast (peak-to-peak of the basic 
           interference signal amplitude) and the basline (its offset) during a running 
           measurement. Please note that the getAxisSignalQuality function output is only 
           updated when a displacement is measured. This means that angular misalignments 
           without displacement changes on the measurement axes cannot be detected. 
           Furthermore, we recommend using the IDS high accuracy initialization to obtain 
           correct values directly after measurement initialization. When using the quick 
           initialization, the initial value might be falsified at first, but correct after some detected 
           measurement (because it is updated with the correct value then).
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  contrast: contrast Contrast of the base band signal in â€°
*  @param  baseline: baseline Offset of the contrast measurement in â€°
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getAxisSignalQuality(int deviceHandle, int axis, int* warningNo, int* contrast, int* baseline);






/** @brief @IDS_displacement_getMeasurementEnabled
*
*  This function can be used to see if the measurement is running
*
*  @param  deviceHandle  Handle of device
*  @param  enable: enable true = enabled; false = disabled
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getMeasurementEnabled(int deviceHandle, bool* enable);






/** @brief @IDS_displacement_getReferencePosition
*
*  The reference position information is estimated at the measurement initialization procedure or on reset. 
           This initial absolute position information is not updated during system 
           operation, whereas the IDS continuously measures the relative displacement from 
           that point.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  position: position reference position of the axis in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getReferencePosition(int deviceHandle, int axis, int* warningNo, double* position);






/** @brief @IDS_displacement_getReferencePositions
*
*  The reference position information is estimated at the measurement initialization procedure or on reset. 
           This initial absolute position information is not updated during system 
           operation, whereas the IDS continuously measures the relative displacement from 
           that point.
*
*  @param  deviceHandle  Handle of device
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  position0: position0 position of the axis 0 in pm
*  @param  position1: position1 position of the axis 1 in pm
*  @param  position2: position2 position of the axis 2 in pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getReferencePositions(int deviceHandle, int* warningNo, double* position0, double* position1, double* position2);






/** @brief @IDS_displacement_getSignalQuality
*
*  This function can be used to monitor the alignment contrast (peak-to-peak of the basic 
           interference signal amplitude) and the basline (its offset) during a running 
           measurement. Please note that the getAxisSignalQuality function output is only 
           updated when a displacement is measured. This means that angular misalignments 
           without displacement changes on the measurement axes cannot be detected. 
           Furthermore, we recommend using the IDS high accuracy initialization to obtain 
           correct values directly after measurement initialization. When using the quick 
           initialization, the initial value might be falsified at first, but correct after some detected 
           measurement (because it is updated with the correct value then).
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
*  @param  contrast: contrast Contrast of the base band signal in â€°
*  @param  baseline: baseline Offset of the contrast measurement in â€°
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_getSignalQuality(int deviceHandle, int axis, int* warningNo, int* contrast, int* baseline);






/** @brief @IDS_displacement_linProc
*
*  Important note: This function is not actively supported anymore. With IDS firmware 1.7.0, a new set of functions corresponding to the linearization procedure was introduced and effectively outdated this function.
           
           Starts linearization procedure (additional IDS feature).
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*  @param  fringesnbr:  Number of fringes to be acquired
*  @param  samplesperfringe:  Number of samples per fringe
*  @param  set:  0 = evaluate current nonlinear amplitude 
            1 = perform linearization and upload look up table 
            2 = Clear look up table 
            3 = Perform only calculation of Phi file
*  @param  lintable: lintable String, which contains all 512 phase related correction values
*  @param  nonlinearamp: nonlinearamp String which contains the residual positive and negative maximal nonlinear amplitude
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_linProc(int deviceHandle, int axis, int fringesnbr, int samplesperfringe, int set, int* lintable, int* nonlinearamp);






/** @brief @IDS_displacement_setAverageN
*
*  Sets the averaging (lowpass) parameter N. The averaging time is calculated by 
           (2^N)*40ns, where N is the averaging value. Please refere to the manual for a table with stopband and 3dB cut-off frequency.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  AverageN value from 0 to 24
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_displacement_setAverageN(int deviceHandle, int value);






/** @brief @IDS_ecu_disable
*
*  Disables the ECU interface.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_disable(int deviceHandle);






/** @brief @IDS_ecu_enable
*
*  Enables the ECU interface.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_enable(int deviceHandle);






/** @brief @IDS_ecu_getConnected
*
*  Reads out whether the ECU interface is physically connected or not. Checking if the ECU is connected can only be done on an enabled ECU interface.
*
*  @param  deviceHandle  Handle of device
*  @param  connected: boolean
            true if connected, false if not
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_getConnected(int deviceHandle, bool* connected);






/** @brief @IDS_ecu_getEnabled
*
*  Reads out whether the ECU interface is enabled or not. Enabling the ECU interface is crucial for working with the ECU.
*
*  @param  deviceHandle  Handle of device
*  @param  enabled: boolean
            true if enabled, false if not
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_getEnabled(int deviceHandle, bool* enabled);






/** @brief @IDS_ecu_getHumidityInPercent
*
*  Reads out the ECU measured air humidity in percent.
*
*  @param  deviceHandle  Handle of device
*  @param  humidity: double
            humidity in %
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_getHumidityInPercent(int deviceHandle, double* humidity);






/** @brief @IDS_ecu_getPressureInHPa
*
*  Reads out the ECU measured air pressure in hPa.
*
*  @param  deviceHandle  Handle of device
*  @param  pressure: double
            pressure in hPa
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_getPressureInHPa(int deviceHandle, double* pressure);






/** @brief @IDS_ecu_getRefractiveIndex
*
*  Reads out the ECU estimated refractive index for the current
        ECU readings. To get the refractive index for other modes, please see
        getRefractiveIndexForCompensation.
*
*  @param  deviceHandle  Handle of device
*  @param  rIndex: double
            refractive index
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_getRefractiveIndex(int deviceHandle, double* rIndex);






/** @brief @IDS_ecu_getRefractiveIndexCompensationMode
*
*  Reads out the compensation mode (see below) which is currently used for the environmental compensation.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to get the mode for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  mode: int32
            mode see defintion in set function
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_getRefractiveIndexCompensationMode(int deviceHandle, int axis, int* mode);






/** @brief @IDS_ecu_getRefractiveIndexForCompensation
*
*  Reads out the refractive index used according to the current environmental compensation mode for this axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to get the refractive index for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  rIndex: double
            refractive index
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_getRefractiveIndexForCompensation(int deviceHandle, int axis, double* rIndex);






/** @brief @IDS_ecu_getTemperatureInDegrees
*
*  Reads out the ECU measured air temperature in degrees Celsius.
*
*  @param  deviceHandle  Handle of device
*  @param  temperature: double
            temperature in degrees C
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_getTemperatureInDegrees(int deviceHandle, double* temperature);






/** @brief @IDS_ecu_setRefractiveIndexCompensationMode
*
*  Sets the refractive index mode.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to set the mode for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  mode: 
            mode can be 0 for direct ECU mode, 1 to take the manual values and calculate the refractive index from this or 2 to directly take the set refrative index
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_ecu_setRefractiveIndexCompensationMode(int deviceHandle, int axis, int mode);






/** @brief @IDS_getLockStatus
*
*  This function returns if the device is locked and if the current client is authorized to use the device.
*
*  @param  deviceHandle  Handle of device
*  @param  locked: locked Is the device locked?
*  @param  authorized: authorized Is the client authorized?
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_getLockStatus(int deviceHandle, bool* locked, bool* authorized);






/** @brief @IDS_grantAccess
*
*  Grants access to a locked device for the requesting IP by checking against the password
*
*  @param  deviceHandle  Handle of device
*  @param  password: string the current password
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_grantAccess(int deviceHandle, const char* password);






/** @brief @IDS_lock
*
*  This function locks the device with a password, so the calling of functions is only possible with this password. The locking IP is automatically added to the devices which can access functions
*
*  @param  deviceHandle  Handle of device
*  @param  password: string the password to be set
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_lock(int deviceHandle, const char* password);






/** @brief @IDS_manual_getHumidityInPercent
*
*  Reads out the manually configured humidity (compensation mode 1).
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to get the humidity for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  humidity: double
            humidity in hPa
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_manual_getHumidityInPercent(int deviceHandle, int axis, double* humidity);






/** @brief @IDS_manual_getPressureInHPa
*
*  Reads out the manually configured Pressure (compensation mode 1).
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to get the pressure for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  pressure: double
            pressure in hPa
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_manual_getPressureInHPa(int deviceHandle, int axis, double* pressure);






/** @brief @IDS_manual_getRefractiveIndex
*
*  Reads out the manually configured value for the refractive index (compensation mode 2).
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to get the mode for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  rindex: double
            refractive index
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_manual_getRefractiveIndex(int deviceHandle, int axis, double* rindex);






/** @brief @IDS_manual_getTemperatureInDegrees
*
*  Reads out the manually configured Temperature (compensation mode 1).
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to set the temperature for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  temperature: double
            temperature in degree celsius
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_manual_getTemperatureInDegrees(int deviceHandle, int axis, double* temperature);






/** @brief @IDS_manual_setHumidityInPercent
*
*  Sets the manually configured Humidity (compensation mode 1). The input range is defined to 0 to 100 % (valid range for the Ciddor Equation).
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to set the humidity for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  humidity: 
            humidity in Percent
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_manual_setHumidityInPercent(int deviceHandle, int axis, double humidity);






/** @brief @IDS_manual_setPressureInHPa
*
*  Sets the manually configured Pressure (compensation mode 1). The input range is defined to 800 to 1200 hPa (valid range for the Ciddor Equation).
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to set the pressure for-
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  pressure: 
            pressure in hPa
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_manual_setPressureInHPa(int deviceHandle, int axis, double pressure);






/** @brief @IDS_manual_setRefractiveIndex
*
*  Sets the refractive index for the direct mode (compensation mode 2). The input range is defined to be greater than 1.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to set the mode for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  rindex: 
            refractive index
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_manual_setRefractiveIndex(int deviceHandle, int axis, double rindex);






/** @brief @IDS_manual_setTemperatureInDegrees
*
*  Sets the manually configured Temperature (compensation mode 1). The input range is defined to -40 to +100 °C (valid range for the Ciddor Equation).
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis to set the temperature for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
*  @param  temperature: 
            temperature in degree celcius
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_manual_setTemperatureInDegrees(int deviceHandle, int axis, double temperature);






/** @brief @IDS_nlc_clearLut
*
*  Deactivates the LUT and removes it from the device
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_clearLut(int deviceHandle, int axis);






/** @brief @IDS_nlc_createLut
*
*  Creates a new LUT for the given axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS where the LUT should be generated
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_createLut(int deviceHandle, int axis);






/** @brief @IDS_nlc_estimateNonlinearities
*
*  Estimates the nonlinearity error for the current device settings without changing or updating any settings.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS of which the nonlinearity error is to be estimated
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_estimateNonlinearities(int deviceHandle, int axis);






/** @brief @IDS_nlc_getDynamicNormalization
*
*  Returns the normalization mode of a specific axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS of which the normalization mode is queried
*  @param  mode: int32
            Normalization Mode

    0    Dynamic normalization

    1    Normalization frozen

    2    Normalization mode determined by target velocity
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_getDynamicNormalization(int deviceHandle, int axis, int* mode);






/** @brief @IDS_nlc_getHistogram
*
*  Returns a histogram of the measured nonlinearity errors obtained from the last call of createLut or estimateNonlinearites.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS
*  @param  histogram: string
            Json dumped histogram array
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_getHistogram(int deviceHandle, int axis, char* histogram, int size0);






/** @brief @IDS_nlc_getLut
*
*  Returns the LUT determined by createLut (which can be applied by setLutApplied).
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS
*  @param  lut: string
            Json dumped LUT array with 512 integers
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_getLut(int deviceHandle, int axis, char* lut, int size0);






/** @brief @IDS_nlc_getLutApplied
*
*  Returns whether a LUT is applied or not for a given axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS of which the LUT apply rule is queried
*  @param  apply: boolean
            True, if LUT is applied on this axis else False
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_getLutApplied(int deviceHandle, int axis, bool* apply);






/** @brief @IDS_nlc_getLutStatus
*
*  Returns if a LUT is available and if warnings or errors occurred during creation.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS of which the status of the LUT should be returned
*  @param  status: boolean
            True, if a LUT exists else False
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_getLutStatus(int deviceHandle, int axis, int* creationWarning, bool* status);






/** @brief @IDS_nlc_getNonlinearityEstimation
*
*  Returns the LUT created by estimateNonlinearities (read-only mode) to compensate the nonlinearity error of the device for the current device settings. If no estimation was created an array of zeros is returned.
*
*  @param  deviceHandle  Handle of device
*  @param  lut: string
            Json dumped LUT array with 512 integers
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_getNonlinearityEstimation(int deviceHandle, char* lut, int size0);






/** @brief @IDS_nlc_getVelocityThresholds
*
*  Returns the threshold velocity (in µm/s) for mode 2 of setDynamicNormalization.
*
*  @param  deviceHandle  Handle of device
*  @param  velocityOn: int32
            Velocity of the target in µm/s when to switch the normalization on (default: 10 µm/s)
*  @param  velocityOff: int32
            Velocity of the target in µm/s when to switch the normalization off (default: 5 µm/s)
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_getVelocityThresholds(int deviceHandle, int* velocityOn, int* velocityOff);






/** @brief @IDS_nlc_setDynamicNormalization
*
*  Sets the normalization mode of a specific axis.
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS of which the normalization mode should be set
*  @param  mode: 
            Normalization Mode
                0    Dynamic normalization (default)
                1    Normalization frozen (for slow target drifts)
                2    Automatic alternation between mode 0 and 1 depending on the target velocity
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_setDynamicNormalization(int deviceHandle, int axis, int mode);






/** @brief @IDS_nlc_setLut
*
*  Uploads a LUT for a specific axis (which can be applied by setLutApplied)
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS
*  @param  lut: 
            Json dumped LUT array with 512 integers
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_setLut(int deviceHandle, int axis, const char* lut);






/** @brief @IDS_nlc_setLutApplied
*
*  Sets the apply rule for the given axis
*
*  @param  deviceHandle  Handle of device
*  @param  axis: 
            Axis [0|1|2] of the IDS of which the apply rule should be set
*  @param  apply: 
            True for applying a LUT, False for disabling a LUT
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_setLutApplied(int deviceHandle, int axis, bool apply);






/** @brief @IDS_nlc_setVelocityThresholds
*
*  Sets the threshold velocity (in µm/s) for mode 2 of setDynamicNormalization. By default, the normalization in mode 2 is frozen for velocities below 5 µm/s and switched to dynamic mode for velocities above 10 µm/s.
*
*  @param  deviceHandle  Handle of device
*  @param  velocityOn: 
            Velocity of the target in µm/s when to switch the normalization on (default: 10 µm/s)
*  @param  velocityOff: 
            Velocity of the target in µm/s when to switch the normalization off (default: 5 µm/s)
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_nlc_setVelocityThresholds(int deviceHandle, int velocityOn, int velocityOff);






/** @brief @IDS_pilotlaser_disable
*
*  Disables the pilot laser.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_pilotlaser_disable(int deviceHandle);






/** @brief @IDS_pilotlaser_enable
*
*  Enables the pilot laser.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_pilotlaser_enable(int deviceHandle);






/** @brief @IDS_pilotlaser_getEnabled
*
*  Reads out whether the pilot laser is enabled or not.
*
*  @param  deviceHandle  Handle of device
*  @param  enable: enable true = enabled; false = disabled
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_pilotlaser_getEnabled(int deviceHandle, bool* enable);






/** @brief @IDS_realtime_AafIsEnabled
*
*  Checks if the anti-aliasing filter is enabled.
*
*  @param  deviceHandle  Handle of device
*  @param  enabled: enabled false: Anti-Aliasing Filter is disabled 
            true: Anti-Aliasing Filter is enabled
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_AafIsEnabled(int deviceHandle, bool* enabled);






/** @brief @IDS_realtime_apply
*
*  Applies new real time settings. Necessary after JSON realtime set commands.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_apply(int deviceHandle);






/** @brief @IDS_realtime_disableTestChannel
*
*  Disables the test channel.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_disableTestChannel(int deviceHandle);






/** @brief @IDS_realtime_discard
*
*  Discards new real time settings. Necessary after JSON set commands in case of failure.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_discard(int deviceHandle);






/** @brief @IDS_realtime_enableTestChannel
*
*  Enables the Test Channel, which can be used for estimating the maximum signal range.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  Test Channel Master Axis
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_enableTestChannel(int deviceHandle, int axis);






/** @brief @IDS_realtime_getAafAttenuation
*
*  Returns the current attenuation at f_nyquist of the anti-aliasing filter.
*
*  @param  deviceHandle  Handle of device
*  @param  attenuation: attenuation [3-30] dB m f_nyquist
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getAafAttenuation(int deviceHandle, int* attenuation);






/** @brief @IDS_realtime_getAafEnabled
*
*  Checks if the anti-aliasing filter is enabled.
*
*  @param  deviceHandle  Handle of device
*  @param  enabled: enabled false - the Anti-Aliasing Filter is disabled 
             true - the Anti-Aliasing Filter is enabled
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getAafEnabled(int deviceHandle, bool* enabled);






/** @brief @IDS_realtime_getAafWindow
*
*  Returns the current filter window of the anti-aliasing filter.
*
*  @param  deviceHandle  Handle of device
*  @param  window: window 0 = Rectangular,
             1 = Cosine,
             2 = Cosine^2,
             3 = Hamming,
             4 = Raised Cosine,
             5 = Automatic
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getAafWindow(int deviceHandle, int* window);






/** @brief @IDS_realtime_getHighPassCutOffFreq
*
*  Reads out the high pass filter number of Linear/Analog output mode.
*
*  @param  deviceHandle  Handle of device
*  @param  value: value N, Linear Analog High Pass Cut-Off freqency is 1600/2^N kHz, with N \\in [1,24]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getHighPassCutOffFreq(int deviceHandle, int* value);






/** @brief @IDS_realtime_getLinearRange
*
*  Reads out the range number of Linear/Analog output mode.
*
*  @param  deviceHandle  Handle of device
*  @param  rangenumber: rangenumber N, Linear Analog Range is +-2^(N+11) pm, with N \\in [0, 34]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getLinearRange(int deviceHandle, int* rangenumber);






/** @brief @IDS_realtime_getPeriodHsslClk
*
*  Reads out the HSSL period clock.
*
*  @param  deviceHandle  Handle of device
*  @param  period: period Period in the Range of [40ns..10200ns]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getPeriodHsslClk(int deviceHandle, int* period);






/** @brief @IDS_realtime_getPeriodHsslGap
*
*  Reads out the HSSL period gap.
*
*  @param  deviceHandle  Handle of device
*  @param  gap: gap Number of clocks
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getPeriodHsslGap(int deviceHandle, int* gap);






/** @brief @IDS_realtime_getPeriodSinCosClk
*
*  Reads out the Sine-Cosine and AquadB period clock.
*
*  @param  deviceHandle  Handle of device
*  @param  period: period 40ns to 10200ns
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getPeriodSinCosClk(int deviceHandle, int* period);






/** @brief @IDS_realtime_getResolutionBissC
*
*  Reads out the BissC resolution.
*
*  @param  deviceHandle  Handle of device
*  @param  resolution: resolution 1pm to 65535pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getResolutionBissC(int deviceHandle, int* resolution);






/** @brief @IDS_realtime_getResolutionHsslHigh
*
*  Reads out the HSSL resolution high bit.
*
*  @param  deviceHandle  Handle of device
*  @param  resolution: resolution Resolution in the Range of [0..46]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getResolutionHsslHigh(int deviceHandle, int* resolution);






/** @brief @IDS_realtime_getResolutionHsslLow
*
*  Reads out the HSSL resolution low bit.#
*
*  @param  deviceHandle  Handle of device
*  @param  resolution: resolution Resolution in the range of [0..46]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getResolutionHsslLow(int deviceHandle, int* resolution);






/** @brief @IDS_realtime_getResolutionSinCos
*
*  Reads out the Sine-Cosine and AquadB resolution.
*
*  @param  deviceHandle  Handle of device
*  @param  resolution: resolution 1pm to 65535pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getResolutionSinCos(int deviceHandle, int* resolution);






/** @brief @IDS_realtime_getRtDistanceMode
*
*  Reads out the distance mode. Depending on the realtime output mode, the mode can 
           be Displacement (returns 1), Absolute Distance (returns 2) or Vibrometry (returns 3).
*
*  @param  deviceHandle  Handle of device
*  @param  linearmode: linearmode 1 = Displacement (Available in HSSL mode and Linear Mode) 
            2 = Absolute Distance (Available in HSSL mode only) 
            3 = Vibrometry (Available in Linear mode)
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getRtDistanceMode(int deviceHandle, int* linearmode);






/** @brief @IDS_realtime_getRtOutMode
*
*  Reads out the current realtime output mode.
*
*  @param  deviceHandle  Handle of device
*  @param  rtOutMode: rtOutMode 0 = HSSL (TTL), 1 = HSSL (LVDS), 2 = AquadB (TTL), 
            3 = AquadB (LVDS), 4 = SinCos (TTL Error Signal), 
            5 = SinCos (LVDS Error Signal), 6 = Linear (TTL), 7 = Linear (LVDS), 
            8 = BiSS-C, 9 = Deactivated
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getRtOutMode(int deviceHandle, int* rtOutMode);






/** @brief @IDS_realtime_getTestChannelEnabled
*
*  Checks if the test channel is enabled
*
*  @param  deviceHandle  Handle of device
*  @param  enabled: enabled true = enabled, false = disabled
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_getTestChannelEnabled(int deviceHandle, bool* enabled);






/** @brief @IDS_realtime_setAaf
*
*  Sets the anti-aliasing filter with assigned filter window.
*
*  @param  deviceHandle  Handle of device
*  @param  enabled:   0 - disables the Anti-Aliasing Filter 
             1 - enables the Anti-Aliasing Filter
*  @param  attenuation:  [3-30] dB m f_nyquist
*  @param  window:  0 = Rectangular,
             1 = Cosine,
             2 = Cosine^2,
             3 = Hamming,
             4 = Raised Cosine,
             5 = Automatic
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setAaf(int deviceHandle, int enabled, int attenuation, int window);






/** @brief @IDS_realtime_setHighPassCutOffFreq
*
*  Sets the high pass filter number of Linear/Analog output mode.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  N, Linear Analog High Pass Cut-Off freqency is 1600/2^N kHz, with N \\in [1,24]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setHighPassCutOffFreq(int deviceHandle, int value);






/** @brief @IDS_realtime_setLinearRange
*
*  Sets the range number of Linear/Analog output mode.
*
*  @param  deviceHandle  Handle of device
*  @param  rangenumber:  N, Linear Analog Range is +-2^(N+11) pm, with N \\in [0, 34]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setLinearRange(int deviceHandle, int rangenumber);






/** @brief @IDS_realtime_setPeriodHsslClk
*
*  Set the HSSL period clock. The value has to be a multiple of 40ns. If not, the value automatically is rounded.
*
*  @param  deviceHandle  Handle of device
*  @param  period:  Period in the Range of [40ns..10200ns]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setPeriodHsslClk(int deviceHandle, int period);






/** @brief @IDS_realtime_setPeriodHsslGap
*
*  Set the HSSL gap.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  Number of clocks
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setPeriodHsslGap(int deviceHandle, int value);






/** @brief @IDS_realtime_setPeriodSinCosClk
*
*  Sets the Sine-Cosine and AquadB period clock. The value has to be a multiple of 40ns. If not, the value automatically is rounded.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  period 40ns to 10200ns
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setPeriodSinCosClk(int deviceHandle, int value);






/** @brief @IDS_realtime_setResolutionBissC
*
*  Sets the BissC resolution.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  resolution 1pm to 65535pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setResolutionBissC(int deviceHandle, int value);






/** @brief @IDS_realtime_setResolutionHsslHigh
*
*  Sets the HSSL resolution high bit.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  Resolution in the Range of [0..46]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setResolutionHsslHigh(int deviceHandle, int value);






/** @brief @IDS_realtime_setResolutionHsslLow
*
*  Sets the HSSL resolution low bit.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  Resolution in the Range of [0..46]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setResolutionHsslLow(int deviceHandle, int value);






/** @brief @IDS_realtime_setResolutionSinCos
*
*  Sets the Sine-Cosine and AquadB resolution.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  resolution 1pm to 65535pm
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setResolutionSinCos(int deviceHandle, int value);






/** @brief @IDS_realtime_setRtDistanceMode
*
*  Sets the distance mode. Depending on the configuration of the IDS the mode can be 
           Displacement (returns 1), Absolute Distance (returns 2) or Vibrometry (returns 3).
*
*  @param  deviceHandle  Handle of device
*  @param  value:  1 = Displacement (HSSL mode and Linear Mode) 
            2 = Absolute Distance (HSSL mode only) 
            3 = Vibrometry (Linear mode)
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setRtDistanceMode(int deviceHandle, int value);






/** @brief @IDS_realtime_setRtOutMode
*
*  Sets the real time output mode.
*
*  @param  deviceHandle  Handle of device
*  @param  value:  rtOutMode 0 = HSSL (TTL), 1 = HSSL (LVDS), 2 = AquadB (TTL), 
            3 = AquadB (LVDS), 4 = SinCos (TTL Error Signal), 
            5 = SinCos (LVDS Error Signal), 6 = Linear (TTL), 7 = Linear (LVDS), 
            8 = BiSS-C, 9 = Deactivated
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_realtime_setRtOutMode(int deviceHandle, int value);






/** @brief @IDS_system_getCurrentMode
*
*  Reads out the current IDS system state.
*
*  @param  deviceHandle  Handle of device
*  @param  mode: mode Values: "system idle", "measurement starting", "measurement running", "optics alignment starting", "optics alignment running", "test channels enabled"
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_getCurrentMode(int deviceHandle, char* mode, int size0);






/** @brief @IDS_system_getDeviceType
*
*  Reads out the IDS device type. For differences between the device types please refer to the IDS User Manual.
*
*  @param  deviceHandle  Handle of device
*  @param  type: type Type of IDS (e.g. "IDS3010")
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_getDeviceType(int deviceHandle, char* type, int size0);






/** @brief @IDS_system_getFeaturesName
*
*  Converts the IDS feature number to its corresponding name.
*
*  @param  deviceHandle  Handle of device
*  @param  featurenumber:  Number of feature
*  @param  names: names The name of the corresponding feature
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_getFeaturesName(int deviceHandle, int featurenumber, char* names, int size0);






/** @brief @IDS_system_getFpgaVersion
*
*  Reads out the IDS FPGA version.
*
*  @param  deviceHandle  Handle of device
*  @param  version: version Version in the form X.Y.Z
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_getFpgaVersion(int deviceHandle, char* version, int size0);






/** @brief @IDS_system_getInitMode
*
*  Returns the Initialization mode.
*
*  @param  deviceHandle  Handle of device
*  @param  mode: mode 0 = High Accuracy Initialization; 1 = Quick Initialization
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_getInitMode(int deviceHandle, int* mode);






/** @brief @IDS_system_getNbrFeaturesActivated
*
*  Reads out the amount of activated features activated on the IDS.
*
*  @param  deviceHandle  Handle of device
*  @param  nbr: nbr Gives the number of activated features.
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_getNbrFeaturesActivated(int deviceHandle, int* nbr);






/** @brief @IDS_system_getSystemError
*
*  Reads out the system error. The function returns an integer number which represents 
           the error. The number can be converted into a string using the errorNumberToString 
           function.
           Use this function to query errors occured while starting and running measurements and alignments.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_getSystemError(int deviceHandle);






/** @brief @IDS_system_resetAxes
*
*  Resets the position value of all measurement axes to zero.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_resetAxes(int deviceHandle);






/** @brief @IDS_system_resetAxis
*
*  Resets the position value of a specific measurement axis to zero.
*
*  @param  deviceHandle  Handle of device
*  @param  axis:  [0|1|2]
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_resetAxis(int deviceHandle, int axis);






/** @brief @IDS_system_resetError
*
*  Resets a measurement error that can have occurred with the aim to continue the interrupted measurement. It is configurable if an additional renormalization process (please refer to the IDS User Manual) should be performed or not.
           
           This function can be used for two concerns:
           1.	FALSE: This function only clears displacement errors (e.g. after a beam interruption) of all three axes, while the displacement measurement is running.
           2.	TRUE: This function can be utilized to normalize the Lissajous-Figure of all three optical axes during the running displacement measurement by sweeping the laser temperature and to clear all displacement errors. This normalization process takes around 14-20 seconds. This function can be used, for example, in two main applications:
           A.	The alignment contrast decreases due to the angular change of the target and/or sensor head without any displacements (see Figure 45). Using this function, the Lissajous-Figure of each measurement axis gets normalized and high-resolution measurements are guaranteed.
           B.	After changing the optical components as, for example, the retro reflector this function can be used to normalize the Lissajous-Figure after completely losing the signal (see Figure 46).
           Attention: Depending on the Boolean input parameter performRenormalisation, it can be decided, if the renormalization process should be executed or skipped. If it is executed, the IDS system needs around 14-20 seconds to get back to the measurement mode. It is also important to comment that the recommended action after an error is to stop and to restart the displacement measurement. Moreover, losing displacement values due to an occurred error the internal absolute position can be different to the real absolute position and this can could result in dynamic movement errors or a wrong ECU compensation during long-term displacement measurements.
*
*  @param  deviceHandle  Handle of device
*  @param  perform:  renormalization
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_resetError(int deviceHandle, bool perform);






/** @brief @IDS_system_setInitMode
*
*  Sets the mode for the initialization procedure that is performed when starting a measurement.
*
*  @param  deviceHandle  Handle of device
*  @param  mode:  0 = High Accuracy Initialization; 1 = Quick Initialization
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_setInitMode(int deviceHandle, int mode);






/** @brief @IDS_system_startMeasurement
*
*  Starts the displacement measurement system state.
            Please query errors during starting and running measurements by system.getSystemError
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_startMeasurement(int deviceHandle);






/** @brief @IDS_system_startOpticsAlignment
*
*  Starts the optical alignment system state.
            Please query errors during starting and running alignments by system.getSystemError
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_startOpticsAlignment(int deviceHandle);






/** @brief @IDS_system_stopMeasurement
*
*  Stops the displacement measurement system state.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_stopMeasurement(int deviceHandle);






/** @brief @IDS_system_stopOpticsAlignment
*
*  Stops the optical alignment system state.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_system_stopOpticsAlignment(int deviceHandle);






/** @brief @IDS_unlock
*
*  This function unlocks the device, so it will not be necessary to execute the grantAccess function to run any function
*
*  @param  deviceHandle  Handle of device
*  @param  password: string the current password
*
*  @return   Result of function
*/
int ATTOCUBE_API IDS_unlock(int deviceHandle, const char* password);






/** @brief @system_about_getInstalledPackages
*
*  Get list of packages installed on the device
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: Comma separated list of packages
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_about_getInstalledPackages(int deviceHandle, char* value_string1, int size0);






/** @brief @system_about_getPackageLicense
*
*  Get the license for a specific package
*
*  @param  deviceHandle  Handle of device
*  @param  pckg:  string: Package name
*  @param  value_string1: string: License for this package
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_about_getPackageLicense(int deviceHandle, const char* pckg, char* value_string1, int size0);






/** @brief @system_apply
*
*  Apply temporary system configuration
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_apply(int deviceHandle);






/** @brief @system_errorNumberToRecommendation
*
*  Get a recommendation for the error code
*
*  @param  deviceHandle  Handle of device
*  @param  language:  integer: Language code
*  @param  errNbr:   interger: Error code to translate
*  @param  value_string1: string: Error recommendation (currently returning an int = 0 until we have recommendations)
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_errorNumberToRecommendation(int deviceHandle, int language, int errNbr, char* value_string1, int size0);






/** @brief @system_errorNumberToString
*
*  Get a description of an error code
*
*  @param  deviceHandle  Handle of device
*  @param  language:  integer: Language code 0 for the error name, 1 for a more user friendly error message
*  @param  errNbr:   interger: Error code to translate
*  @param  value_string1: string: Error description
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_errorNumberToString(int deviceHandle, int language, int errNbr, char* value_string1, int size0);






/** @brief @system_factoryReset
*
*  Turns on the factory reset flag. To perform the factory reset, a reboot is necessary afterwards. All settings will be set to default and the IDS will be configured as DHCP server.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_factoryReset(int deviceHandle);






/** @brief @system_functions_checkAMCinRack
*
*  If AMC is on Rack position 0, use it as DHCP server, else use it as DHCP client
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_functions_checkAMCinRack(int deviceHandle);






/** @brief @system_getDeviceName
*
*  Get the actual device name
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: actual device name
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getDeviceName(int deviceHandle, char* value_string1, int size0);






/** @brief @system_getFirmwareVersion
*
*  Get the firmware version of the system
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: The firmware version
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getFirmwareVersion(int deviceHandle, char* value_string1, int size0);






/** @brief @system_getFluxCode
*
*  Get the flux code of the system
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: flux code
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getFluxCode(int deviceHandle, char* value_string1, int size0);






/** @brief @system_getHostname
*
*  Return device hostname
*
*  @param  deviceHandle  Handle of device
*  @param  available: available
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getHostname(int deviceHandle, char* available, int size0);






/** @brief @system_getMacAddress
*
*  Get the mac address of the system
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: Mac address of the system
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getMacAddress(int deviceHandle, char* value_string1, int size0);






/** @brief @system_getSerialNumber
*
*  Get the serial number of the system
*
*  @param  deviceHandle  Handle of device
*  @param  value_string1: string: Serial number
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_getSerialNumber(int deviceHandle, char* value_string1, int size0);






/** @brief @system_network_apply
*
*  Apply temporary IP configuration and load it
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_apply(int deviceHandle);






/** @brief @system_network_configureWifi
*
*  Change the wifi configuration and applies it
*
*  @param  deviceHandle  Handle of device
*  @param  mode:  0: Access point, 1: Wifi client
*  @param  ssid: 
*  @param  psk:  Pre-shared key
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_configureWifi(int deviceHandle, int mode, const char* ssid, const char* psk);






/** @brief @system_network_discard
*
*  Discard temporary IP configuration
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_discard(int deviceHandle);






/** @brief @system_network_getDefaultGateway
*
*  Get the default gateway of the device
*
*  @param  deviceHandle  Handle of device
*  @param  Default: Default gateway
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getDefaultGateway(int deviceHandle, char* Default, int size0);






/** @brief @system_network_getDnsResolver
*
*  Get the DNS resolver
*
*  @param  deviceHandle  Handle of device
*  @param  priority:  of DNS resolver (Usually: 0 = Default, 1 = Backup)
*  @param  IP: IP address of DNS resolver
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getDnsResolver(int deviceHandle, int priority, char* IP, int size0);






/** @brief @system_network_getEnableDhcpClient
*
*  Get the state of DHCP client
*
*  @param  deviceHandle  Handle of device
*  @param  value_boolean1: boolean: true = DHCP client enable, false = DHCP client disable
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getEnableDhcpClient(int deviceHandle, bool* value_boolean1);






/** @brief @system_network_getEnableDhcpServer
*
*  Get the state of DHCP server
*
*  @param  deviceHandle  Handle of device
*  @param  value_boolean1: boolean: true = DHCP server enable, false = DHCP server disable
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getEnableDhcpServer(int deviceHandle, bool* value_boolean1);






/** @brief @system_network_getIpAddress
*
*  Get the IP address of the device
*
*  @param  deviceHandle  Handle of device
*  @param  IP: IP address as string
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getIpAddress(int deviceHandle, char* IP, int size0);






/** @brief @system_network_getProxyServer
*
*  Get the proxy settings of the devide
*
*  @param  deviceHandle  Handle of device
*  @param  Proxy: Proxy Server String, empty for no proxy
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getProxyServer(int deviceHandle, char* Proxy, int size0);






/** @brief @system_network_getRealIpAddress
*
*  Get the real IP address of the device set to the network interface (br0, eth1 or eth0)
*
*  @param  deviceHandle  Handle of device
*  @param  IP: IP address as string
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getRealIpAddress(int deviceHandle, char* IP, int size0);






/** @brief @system_network_getSubnetMask
*
*  Get the subnet mask of the device
*
*  @param  deviceHandle  Handle of device
*  @param  Subnet: Subnet mask as string
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getSubnetMask(int deviceHandle, char* Subnet, int size0);






/** @brief @system_network_getWifiMode
*
*  Get the operation mode of the wifi adapter
*
*  @param  deviceHandle  Handle of device
*  @param  mode: mode 0: Access point, 1: Wifi client
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getWifiMode(int deviceHandle, int* mode);






/** @brief @system_network_getWifiPassphrase
*
*  Get the the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param  deviceHandle  Handle of device
*  @param  psk: psk Pre-shared key
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getWifiPassphrase(int deviceHandle, char* psk, int size0);






/** @brief @system_network_getWifiPresent
*
*  Returns is a Wifi interface is present
*
*  @param  deviceHandle  Handle of device
*  @param  True: True, if interface is present
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getWifiPresent(int deviceHandle, bool* True);






/** @brief @system_network_getWifiSSID
*
*  Get the the SSID of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param  deviceHandle  Handle of device
*  @param  SSID: SSID
*  @param  size0 maximum size of previous buffer
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_getWifiSSID(int deviceHandle, char* SSID, int size0);






/** @brief @system_network_setDefaultGateway
*
*  Set the default gateway of the device
*
*  @param  deviceHandle  Handle of device
*  @param  gateway:  Default gateway as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setDefaultGateway(int deviceHandle, const char* gateway);






/** @brief @system_network_setDnsResolver
*
*  Set the DNS resolver
*
*  @param  deviceHandle  Handle of device
*  @param  priority:  of DNS resolver (Usually: 0 = Default, 1 = Backup)
*  @param  resolver:  The resolver's IP address as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setDnsResolver(int deviceHandle, int priority, const char* resolver);






/** @brief @system_network_setEnableDhcpClient
*
*  Enable or disable DHCP client
*
*  @param  deviceHandle  Handle of device
*  @param  enable:  boolean: true = enable DHCP client, false = disable DHCP client
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setEnableDhcpClient(int deviceHandle, bool enable);






/** @brief @system_network_setEnableDhcpServer
*
*  Enable or disable DHCP server
*
*  @param  deviceHandle  Handle of device
*  @param  enable:  boolean: true = enable DHCP server, false = disable DHCP server
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setEnableDhcpServer(int deviceHandle, bool enable);






/** @brief @system_network_setIpAddress
*
*  Set the IP address of the device
*
*  @param  deviceHandle  Handle of device
*  @param  address:  IP address as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setIpAddress(int deviceHandle, const char* address);






/** @brief @system_network_setProxyServer
*
*  Set the proxy server of the device
*
*  @param  deviceHandle  Handle of device
*  @param  proxyServer:  Proxy Server Setting as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setProxyServer(int deviceHandle, const char* proxyServer);






/** @brief @system_network_setSubnetMask
*
*  Set the subnet mask of the device
*
*  @param  deviceHandle  Handle of device
*  @param  netmask:  Subnet mask as string
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setSubnetMask(int deviceHandle, const char* netmask);






/** @brief @system_network_setWifiMode
*
*  Change the operation mode of the wifi adapter
*
*  @param  deviceHandle  Handle of device
*  @param  mode:  0: Access point, 1: Wifi client
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setWifiMode(int deviceHandle, int mode);






/** @brief @system_network_setWifiPassphrase
*
*  Change the passphrase of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param  deviceHandle  Handle of device
*  @param  psk:  Pre-shared key
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setWifiPassphrase(int deviceHandle, const char* psk);






/** @brief @system_network_setWifiSSID
*
*  Change the SSID of the network hosted (mode: Access point) or connected to (mode: client)
*
*  @param  deviceHandle  Handle of device
*  @param  ssid: 
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_setWifiSSID(int deviceHandle, const char* ssid);






/** @brief @system_network_verify
*
*  Verify that temporary IP configuration is correct
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_network_verify(int deviceHandle);






/** @brief @system_rebootSystem
*
*  Reboot the system
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_rebootSystem(int deviceHandle);






/** @brief @system_setDeviceName
*
*  Set custom name for the device
*
*  @param  deviceHandle  Handle of device
*  @param  name:  string: device name
*
*  @return   Result of function
*/
int ATTOCUBE_API system_setDeviceName(int deviceHandle, const char* name);






/** @brief @system_setTime
*
*  Set system time manually
*
*  @param  deviceHandle  Handle of device
*  @param  day:  integer: Day (1-31)
*  @param  month:  integer: Day (1-12)
*  @param  year:  integer: Day (eg. 2021)
*  @param  hour:  integer: Day (0-23)
*  @param  minute:  integer: Day (0-59)
*  @param  second:  integer: Day (0-59)
*
*  @return   Result of function
*/
int ATTOCUBE_API system_setTime(int deviceHandle, int day, int month, int year, int hour, int minute, int second);






/** @brief @system_softReset
*
*  Performs a soft reset (Reset without deleting the network settings). Please reboot the device directly afterwards.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_softReset(int deviceHandle);






/** @brief @system_updateTimeFromInternet
*
*  Update system time by querying attocube.com
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_updateTimeFromInternet(int deviceHandle);






/** @brief @system_update_getLicenseUpdateProgress
*
*  Get the progress of running license update
*
*  @param  deviceHandle  Handle of device
*  @param  value_int1: int: progress in percent
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_getLicenseUpdateProgress(int deviceHandle, int* value_int1);






/** @brief @system_update_getSwUpdateProgress
*
*  Get the progress of running update
*
*  @param  deviceHandle  Handle of device
*  @param  value_int1: int: progress in percent
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_getSwUpdateProgress(int deviceHandle, int* value_int1);






/** @brief @system_update_licenseUpdateBase64
*
*  Execute the license update with base64 file uploaded. After execution, a manual reboot is nevessary.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_licenseUpdateBase64(int deviceHandle);






/** @brief @system_update_softwareUpdateBase64
*
*  Execute the update with base64 file uploaded. After completion, a manual reboot is necessary.
*
*  @param  deviceHandle  Handle of device
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_softwareUpdateBase64(int deviceHandle);






/** @brief @system_update_uploadLicenseBase64
*
*  Upload new license file in format base 64
*
*  @param  deviceHandle  Handle of device
*  @param  offset:  int: offset of the data
*  @param  b64Data:  string: base64 data
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_uploadLicenseBase64(int deviceHandle, int offset, const char* b64Data);






/** @brief @system_update_uploadSoftwareImageBase64
*
*  Upload new firmware image in format base 64
*
*  @param  deviceHandle  Handle of device
*  @param  offset:  int: offset of the data
*  @param  b64Data:  string: base64 data
*
*  @return   Result of function
*/
int ATTOCUBE_API system_update_uploadSoftwareImageBase64(int deviceHandle, int offset, const char* b64Data);









#ifdef __cplusplus

}

#endif



#endif // __GENERATEDAPI_H__





