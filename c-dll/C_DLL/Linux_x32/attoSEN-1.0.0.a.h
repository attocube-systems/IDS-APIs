/**
 * Copyright (C) 2020 attocube systems AG
 * Usage is up to a separate agreement
**/

/**
 * @file generatedAPI.h
 * @brief API for use with attocube devices
**/

#ifndef __GENERATEDAPI_H_SEN_1_0_0__
#define __GENERATEDAPI_H_SEN_1_0_0__

#ifndef ATTO_PREFIX
#define ATTO_PREFIX SEN_
#endif

#define ATTO_PREFIX_CONCAT(x,y) x ## y
#define ATTO_PREFIX_EVALUATOR(x,y) ATTO_PREFIX_CONCAT(x,y)
#define ATTO_FUNCTION(function_name) ATTO_PREFIX_EVALUATOR(ATTO_PREFIX, function_name)

#include <stdbool.h>
#include "attocubeJSONCall.h"
#ifdef __cplusplus
extern "C" {
#endif

/** @brief @SEN_grantAccess
*  Grants access to a locked device by checking against the password.
*
*  @param deviceHandle     Handle of device
*  @param password         current password string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_access_grantAccess(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(grantAccess)(int deviceHandle, const char* password) {
    return __SEN_1_0_0_access_grantAccess(deviceHandle, password);
}


/** @brief @SEN_lock
*  Locks the device with a given password. Afterwards, the device functions are only accessible with this password. The computer IP address, which locks the device, is automatically added to the device and doesn't need the password for functions access.
*
*  @param deviceHandle     Handle of device
*  @param password         set password string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_access_lock(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(lock)(int deviceHandle, const char* password) {
    return __SEN_1_0_0_access_lock(deviceHandle, password);
}


/** @brief @SEN_unlock
*  Unlocks the device. Afterwards, the device functions are accessible without any password. For grant access without unlocking the device, please use the grantAccess function.
*
*  @param deviceHandle     Handle of device
*  @param password         current password string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_access_unlock(int deviceHandle, const char* password);

static inline int ATTO_FUNCTION(unlock)(int deviceHandle, const char* password) {
    return __SEN_1_0_0_access_unlock(deviceHandle, password);
}


/** @brief @SEN_getLockStatus
*  Gets the lock status of the device and if the current client is authorized to use the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_Is1        Is the device locked?
*  @param value_Is2        Is the client authorized?
*
*  @return Is the device locked?
*/
int ATTOCUBE_API __SEN_1_0_0_access_getLockStatus(int deviceHandle, bool* value_Is1, bool* value_Is2);

static inline int ATTO_FUNCTION(getLockStatus)(int deviceHandle, bool* value_Is1, bool* value_Is2) {
    return __SEN_1_0_0_access_getLockStatus(deviceHandle, value_Is1, value_Is2);
}


/** @brief @SEN_nlc_analyzeNonlinearities
*  Estimates the nonlinearities for the current measurement without modifying any settings. After applying a LUT, this function can be used to determine the effectiveness of the applied LUT. The error curve as a function of phase can be retrieved using getNonlinearityErrorCurveInPm(). The error list, for example for histogram evaluation, can be retrieved using getNonlinearityErrorListInPm(). If the estimation fails, for example due to an unstable measurement setup, the previously stored estimation results are not updated. In this case, subsequent calls to the corresponding get-functions return the last valid results.
*   
*   This function is only available in the "measurement running" state. While analysis, the device state changes to "measurement starting" (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_analyzeNonlinearities(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(nlc_analyzeNonlinearities)(int deviceHandle, int axis) {
    return __SEN_1_0_0_nlc_analyzeNonlinearities(deviceHandle, axis);
}


/** @brief @SEN_nlc_clearAll
*  Deactivates the active LUT and clears all associated data created by createLut() and analyzeNonlinearities(), including the cached results returned by getLutInPm(), getNonlinearityErrorCurveInPm(), getNonlinearityErrorCurvesInPm(), and getNonlinearityErrorListInPm().
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_clearAll(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(nlc_clearAll)(int deviceHandle, int axis) {
    return __SEN_1_0_0_nlc_clearAll(deviceHandle, axis);
}


/** @brief @SEN_nlc_createLut
*  Estimates the nonlinearities for a specific measurement axis and creates a new LUT based on the result. The initial nonlinearities can be analyzed using getNonlinearityErrorListInPm(). The generated LUT can be applied with setLutApplied() and retrieved with getLutInPm(). After applying a LUT, this function can be called again for further optimization. The newly generated LUT is then combined with the existing LUT. If the estimation fails, for example due to an unstable measurement setup, the previously stored LUT results are not updated. In this case, subsequent calls to the corresponding get-functions return the last valid results.
*   
*   This function is only available in the "measurement running" state. While the LUT is being created, the device state changes to "measurement starting" (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_createLut(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(nlc_createLut)(int deviceHandle, int axis) {
    return __SEN_1_0_0_nlc_createLut(deviceHandle, axis);
}


/** @brief @SEN_nlc_getAnalysisStatus
*  Reads out whether the analysis of nonlinearities was performed or not for a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param warningNo        warning code, can be converted into a string using the errorNumberToString function
*  @param status           true if analysis data is available, else false
*
*  @return warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_getAnalysisStatus(int deviceHandle, int axis, int* warningNo, bool* status);

static inline int ATTO_FUNCTION(nlc_getAnalysisStatus)(int deviceHandle, int axis, int* warningNo, bool* status) {
    return __SEN_1_0_0_nlc_getAnalysisStatus(deviceHandle, axis, warningNo, status);
}


/** @brief @SEN_nlc_getLutApplied
*  Returns whether a LUT is applied or not for a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param apply            true = applied; false = disabled
*
*  @return true = applied; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_getLutApplied(int deviceHandle, int axis, bool* apply);

static inline int ATTO_FUNCTION(nlc_getLutApplied)(int deviceHandle, int axis, bool* apply) {
    return __SEN_1_0_0_nlc_getLutApplied(deviceHandle, axis, apply);
}


/** @brief @SEN_nlc_getLutDuringInit
*  Reads out the current configuration of the LUT creation during the measurement initialization.
*
*  @param deviceHandle     Handle of device
*
*  @param enabled          true for create LUT during measurement initialization, else false
*
*  @return true for create LUT during measurement initialization, else false
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_getLutDuringInit(int deviceHandle, bool* enabled);

static inline int ATTO_FUNCTION(nlc_getLutDuringInit)(int deviceHandle, bool* enabled) {
    return __SEN_1_0_0_nlc_getLutDuringInit(deviceHandle, enabled);
}


/** @brief @SEN_nlc_getLutInPm
*  This function returns the LUT after calling the createLut() function. If no estimation has been performed, the function returns an error.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param lut              JSON-encoded string containing an array of 512 integer values representing the LUT
*  @param size             Maximum size of buffer lut
*
*  @return JSON-encoded string containing an array of 512 integer values representing the LUT
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_getLutInPm(int deviceHandle, int axis, char* lut, int size);

static inline int ATTO_FUNCTION(nlc_getLutInPm)(int deviceHandle, int axis, char* lut, int size) {
    return __SEN_1_0_0_nlc_getLutInPm(deviceHandle, axis, lut, size);
}


/** @brief @SEN_nlc_getLutStatus
*  Reads out whether the LUT is available or not for a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param warningNo        warning code, can be converted into a string using the errorNumberToString function
*  @param status           true if a LUT exists, else false
*
*  @return warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_getLutStatus(int deviceHandle, int axis, int* warningNo, bool* status);

static inline int ATTO_FUNCTION(nlc_getLutStatus)(int deviceHandle, int axis, int* warningNo, bool* status) {
    return __SEN_1_0_0_nlc_getLutStatus(deviceHandle, axis, warningNo, status);
}


/** @brief @SEN_nlc_getNonlinearityErrorCurveInPm
*  Returns a string containing a serialized list of the residual nonlinearities in pm for the current measurement. The returned values represent the median nonlinearity error curve within one interferometric fringe and are based on the most recent successful result of analyzeNonlinearities(). If no estimation has been performed, the function returns an error. The returned values are only updated after a successful call to analyzeNonlinearities().
*   
*   Use createLUT() followed by setLutApplied() for nonlinearity compensation.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param curve            JSON-encoded string containing an array of 512 integer values representing the error curve
*  @param size             Maximum size of buffer curve
*
*  @return JSON-encoded string containing an array of 512 integer values representing the error curve
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_getNonlinearityErrorCurveInPm(int deviceHandle, int axis, char* curve, int size);

static inline int ATTO_FUNCTION(nlc_getNonlinearityErrorCurveInPm)(int deviceHandle, int axis, char* curve, int size) {
    return __SEN_1_0_0_nlc_getNonlinearityErrorCurveInPm(deviceHandle, axis, curve, size);
}


/** @brief @SEN_nlc_getNonlinearityErrorCurvesInPm
*  Returns a string containing a serialized matrix of nonlinearity error curves in pm for the current measurement. The returned values are based on the most recent successful estimation performed by createLut() or analyzeNonlinearities(). Each row represents the nonlinearity error curve of one measured interferometric fringe. If no estimation has been performed, the function returns an error.
*   
*   For the median nonlinearity error curve or static LUT calculated from these individual fringes, use getNonlinearityErrorCurveInPm() or getLutInPm(), respectively.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param curves           JSON-encoded string containing a 2-dimensional array representing multiple error curves
*  @param size             Maximum size of buffer curves
*
*  @return JSON-encoded string containing a 2-dimensional array representing multiple error curves
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_getNonlinearityErrorCurvesInPm(int deviceHandle, int axis, char* curves, int size);

static inline int ATTO_FUNCTION(nlc_getNonlinearityErrorCurvesInPm)(int deviceHandle, int axis, char* curves, int size) {
    return __SEN_1_0_0_nlc_getNonlinearityErrorCurvesInPm(deviceHandle, axis, curves, size);
}


/** @brief @SEN_nlc_getNonlinearityErrorListInPm
*  Returns a string containing a serialized list of the measured nonlinearities in pm for the current measurement. The returned data represents peak-to-peak values of the single fringes based on the most recent successful estimation performed by createLut() or analyzeNonlinearities(). It can be visualized as a histogram to analyze the distribution and magnitude of the residual nonlinearities. If no estimation has been performed, the function returns an error.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param histogram        JSON-encoded string containing a list of the nonlinearity residuals
*  @param size             Maximum size of buffer histogram
*
*  @return JSON-encoded string containing a list of the nonlinearity residuals
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_getNonlinearityErrorListInPm(int deviceHandle, int axis, char* histogram, int size);

static inline int ATTO_FUNCTION(nlc_getNonlinearityErrorListInPm)(int deviceHandle, int axis, char* histogram, int size) {
    return __SEN_1_0_0_nlc_getNonlinearityErrorListInPm(deviceHandle, axis, histogram, size);
}


/** @brief @SEN_nlc_setLutApplied
*  Applies the LUT for a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param apply            true = apply LUT; false = disable LUT
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_setLutApplied(int deviceHandle, int axis, bool apply);

static inline int ATTO_FUNCTION(nlc_setLutApplied)(int deviceHandle, int axis, bool apply) {
    return __SEN_1_0_0_nlc_setLutApplied(deviceHandle, axis, apply);
}


/** @brief @SEN_nlc_setLutDuringInit
*  Enables or disables the creation of the LUT during measurement initialization.
*
*  @param deviceHandle     Handle of device
*  @param enabled          true for create LUT during measurement initialization, else false
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_setLutDuringInit(int deviceHandle, bool enabled);

static inline int ATTO_FUNCTION(nlc_setLutDuringInit)(int deviceHandle, bool enabled) {
    return __SEN_1_0_0_nlc_setLutDuringInit(deviceHandle, enabled);
}


/** @brief @SEN_nlc_setLutInPm
*  Uploads a LUT for a specific measurement axis, which can be applied by the setLutApplied() function.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param lut              JSON-encoded string containing an array of 512 integer values representing the LUT
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_nlc_setLutInPm(int deviceHandle, int axis, const char* lut);

static inline int ATTO_FUNCTION(nlc_setLutInPm)(int deviceHandle, int axis, const char* lut) {
    return __SEN_1_0_0_nlc_setLutInPm(deviceHandle, axis, lut);
}


/** @brief @SEN_about_getInstalledPackages
*  Gets list of packages installed on the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string comma separated list of packages
*  @param size             Maximum size of buffer value_string
*
*  @return string comma separated list of packages
*/
int ATTOCUBE_API __SEN_1_0_0_about_getInstalledPackages(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(about_getInstalledPackages)(int deviceHandle, char* value_string, int size) {
    return __SEN_1_0_0_about_getInstalledPackages(deviceHandle, value_string, size);
}


/** @brief @SEN_about_getPackageLicense
*  Gets the license for a specific package.
*
*  @param deviceHandle     Handle of device
*  @param pckg             package name string
*
*  @param value_string     string license for this package
*  @param size             Maximum size of buffer value_string
*
*  @return string license for this package
*/
int ATTOCUBE_API __SEN_1_0_0_about_getPackageLicense(int deviceHandle, const char* pckg, char* value_string, int size);

static inline int ATTO_FUNCTION(about_getPackageLicense)(int deviceHandle, const char* pckg, char* value_string, int size) {
    return __SEN_1_0_0_about_getPackageLicense(deviceHandle, pckg, value_string, size);
}


/** @brief @SEN_update_getSwUpdateProgress
*  Gets the progress of running update.
*
*  @param deviceHandle     Handle of device
*
*  @param value_progress   progress value in %
*
*  @return progress value in %
*/
int ATTOCUBE_API __SEN_1_0_0_update_getSwUpdateProgress(int deviceHandle, int* value_progress);

static inline int ATTO_FUNCTION(update_getSwUpdateProgress)(int deviceHandle, int* value_progress) {
    return __SEN_1_0_0_update_getSwUpdateProgress(deviceHandle, value_progress);
}


/** @brief @SEN_update_getLicenseUpdateProgress
*  Gets the progress of running license update.
*
*  @param deviceHandle     Handle of device
*
*  @param value_progress   progress value in %
*
*  @return progress value in %
*/
int ATTOCUBE_API __SEN_1_0_0_update_getLicenseUpdateProgress(int deviceHandle, int* value_progress);

static inline int ATTO_FUNCTION(update_getLicenseUpdateProgress)(int deviceHandle, int* value_progress) {
    return __SEN_1_0_0_update_getLicenseUpdateProgress(deviceHandle, value_progress);
}


/** @brief @SEN_update_softwareUpdateBase64
*  Executes the update with base 64 file uploaded.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_update_softwareUpdateBase64(int deviceHandle);

static inline int ATTO_FUNCTION(update_softwareUpdateBase64)(int deviceHandle) {
    return __SEN_1_0_0_update_softwareUpdateBase64(deviceHandle);
}


/** @brief @SEN_update_uploadSoftwareImageBase64
*  Uploads new firmware image in format base 64.
*
*  @param deviceHandle     Handle of device
*  @param offset           offset of the data
*  @param b64Data          base64 data string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_update_uploadSoftwareImageBase64(int deviceHandle, int offset, const char* b64Data);

static inline int ATTO_FUNCTION(update_uploadSoftwareImageBase64)(int deviceHandle, int offset, const char* b64Data) {
    return __SEN_1_0_0_update_uploadSoftwareImageBase64(deviceHandle, offset, b64Data);
}


/** @brief @SEN_update_uploadLicenseBase64
*  Uploads new license file in format base 64.
*
*  @param deviceHandle     Handle of device
*  @param offset           offset of the data
*  @param b64Data          base64 data string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_update_uploadLicenseBase64(int deviceHandle, int offset, const char* b64Data);

static inline int ATTO_FUNCTION(update_uploadLicenseBase64)(int deviceHandle, int offset, const char* b64Data) {
    return __SEN_1_0_0_update_uploadLicenseBase64(deviceHandle, offset, b64Data);
}


/** @brief @SEN_update_licenseUpdateBase64
*  Executes the license update with base64 file uploaded.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_update_licenseUpdateBase64(int deviceHandle);

static inline int ATTO_FUNCTION(update_licenseUpdateBase64)(int deviceHandle) {
    return __SEN_1_0_0_update_licenseUpdateBase64(deviceHandle);
}


/** @brief @SEN_network_getRealIpAddress
*  Gets the real IP address of the device set to the network interface (br0, eth1 or eth0).
*
*  @param deviceHandle     Handle of device
*
*  @param value_IP         IP IP address
*  @param size             Maximum size of buffer value_IP
*
*  @return IP IP address
*/
int ATTOCUBE_API __SEN_1_0_0_network_getRealIpAddress(int deviceHandle, char* value_IP, int size);

static inline int ATTO_FUNCTION(network_getRealIpAddress)(int deviceHandle, char* value_IP, int size) {
    return __SEN_1_0_0_network_getRealIpAddress(deviceHandle, value_IP, size);
}


/** @brief @SEN_network_getIpAddress
*  Gets the IP address of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_IP         IP address as string
*  @param size             Maximum size of buffer value_IP
*
*  @return IP address as string
*/
int ATTOCUBE_API __SEN_1_0_0_network_getIpAddress(int deviceHandle, char* value_IP, int size);

static inline int ATTO_FUNCTION(network_getIpAddress)(int deviceHandle, char* value_IP, int size) {
    return __SEN_1_0_0_network_getIpAddress(deviceHandle, value_IP, size);
}


/** @brief @SEN_network_setIpAddress
*  Sets the IP address of the device.
*
*  @param deviceHandle     Handle of device
*  @param address          IP address as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setIpAddress(int deviceHandle, const char* address);

static inline int ATTO_FUNCTION(network_setIpAddress)(int deviceHandle, const char* address) {
    return __SEN_1_0_0_network_setIpAddress(deviceHandle, address);
}


/** @brief @SEN_network_getSubnetMask
*  Gets the subnet mask of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_netmask    netmask subnet mask as string
*  @param size             Maximum size of buffer value_netmask
*
*  @return netmask subnet mask as string
*/
int ATTOCUBE_API __SEN_1_0_0_network_getSubnetMask(int deviceHandle, char* value_netmask, int size);

static inline int ATTO_FUNCTION(network_getSubnetMask)(int deviceHandle, char* value_netmask, int size) {
    return __SEN_1_0_0_network_getSubnetMask(deviceHandle, value_netmask, size);
}


/** @brief @SEN_network_setSubnetMask
*  Sets the subnet mask of the device.
*
*  @param deviceHandle     Handle of device
*  @param netmask          subnet mask as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setSubnetMask(int deviceHandle, const char* netmask);

static inline int ATTO_FUNCTION(network_setSubnetMask)(int deviceHandle, const char* netmask) {
    return __SEN_1_0_0_network_setSubnetMask(deviceHandle, netmask);
}


/** @brief @SEN_network_getDefaultGateway
*  Gets the default gateway of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_gateway    gateway default gateway as string
*  @param size             Maximum size of buffer value_gateway
*
*  @return gateway default gateway as string
*/
int ATTOCUBE_API __SEN_1_0_0_network_getDefaultGateway(int deviceHandle, char* value_gateway, int size);

static inline int ATTO_FUNCTION(network_getDefaultGateway)(int deviceHandle, char* value_gateway, int size) {
    return __SEN_1_0_0_network_getDefaultGateway(deviceHandle, value_gateway, size);
}


/** @brief @SEN_network_setDefaultGateway
*  Sets the default gateway of the device.
*
*  @param deviceHandle     Handle of device
*  @param gateway          default gateway as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setDefaultGateway(int deviceHandle, const char* gateway);

static inline int ATTO_FUNCTION(network_setDefaultGateway)(int deviceHandle, const char* gateway) {
    return __SEN_1_0_0_network_setDefaultGateway(deviceHandle, gateway);
}


/** @brief @SEN_network_getDnsResolver
*  Gets the DNS resolver.
*
*  @param deviceHandle     Handle of device
*  @param priority         priority of DNS resolver (0 = default; 1 = backup)
*
*  @param value_resolver   resolver IP address of DNS resolver
*  @param size             Maximum size of buffer value_resolver
*
*  @return resolver IP address of DNS resolver
*/
int ATTOCUBE_API __SEN_1_0_0_network_getDnsResolver(int deviceHandle, int priority, char* value_resolver, int size);

static inline int ATTO_FUNCTION(network_getDnsResolver)(int deviceHandle, int priority, char* value_resolver, int size) {
    return __SEN_1_0_0_network_getDnsResolver(deviceHandle, priority, value_resolver, size);
}


/** @brief @SEN_network_setDnsResolver
*  Sets the DNS resolver.
*
*  @param deviceHandle     Handle of device
*  @param priority         priority of DNS resolver (0 = default; 1 = backup)
*  @param resolver         IP address of DNS resolver
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setDnsResolver(int deviceHandle, int priority, const char* resolver);

static inline int ATTO_FUNCTION(network_setDnsResolver)(int deviceHandle, int priority, const char* resolver) {
    return __SEN_1_0_0_network_setDnsResolver(deviceHandle, priority, resolver);
}


/** @brief @SEN_network_getProxyServer
*  Gets the proxy settings of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_proxyServer proxyServer proxy server setting, empty for no proxy
*  @param size             Maximum size of buffer value_proxyServer
*
*  @return proxyServer proxy server setting, empty for no proxy
*/
int ATTOCUBE_API __SEN_1_0_0_network_getProxyServer(int deviceHandle, char* value_proxyServer, int size);

static inline int ATTO_FUNCTION(network_getProxyServer)(int deviceHandle, char* value_proxyServer, int size) {
    return __SEN_1_0_0_network_getProxyServer(deviceHandle, value_proxyServer, size);
}


/** @brief @SEN_network_setProxyServer
*  Sets the proxy server of the device.
*
*  @param deviceHandle     Handle of device
*  @param proxyServer      proxy server setting
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setProxyServer(int deviceHandle, const char* proxyServer);

static inline int ATTO_FUNCTION(network_setProxyServer)(int deviceHandle, const char* proxyServer) {
    return __SEN_1_0_0_network_setProxyServer(deviceHandle, proxyServer);
}


/** @brief @SEN_network_getEnableDhcpServer
*  Gets the status of DHCP server.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled; false = disabled
*
*  @return enabled true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_network_getEnableDhcpServer(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(network_getEnableDhcpServer)(int deviceHandle, bool* value_enabled) {
    return __SEN_1_0_0_network_getEnableDhcpServer(deviceHandle, value_enabled);
}


/** @brief @SEN_network_setEnableDhcpServer
*  Enables or disables DHCP server.
*
*  @param deviceHandle     Handle of device
*  @param enable           true = enable; false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setEnableDhcpServer(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(network_setEnableDhcpServer)(int deviceHandle, bool enable) {
    return __SEN_1_0_0_network_setEnableDhcpServer(deviceHandle, enable);
}


/** @brief @SEN_network_getEnableDhcpClient
*  Gets the status of DHCP client.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled; false = disabled
*
*  @return enabled true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_network_getEnableDhcpClient(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(network_getEnableDhcpClient)(int deviceHandle, bool* value_enabled) {
    return __SEN_1_0_0_network_getEnableDhcpClient(deviceHandle, value_enabled);
}


/** @brief @SEN_network_setEnableDhcpClient
*  Enables or disables DHCP client.
*
*  @param deviceHandle     Handle of device
*  @param enable           true = enable; false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setEnableDhcpClient(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(network_setEnableDhcpClient)(int deviceHandle, bool enable) {
    return __SEN_1_0_0_network_setEnableDhcpClient(deviceHandle, enable);
}


/** @brief @SEN_network_apply
*  Applies the temporary IP configuration and loads it.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_apply(int deviceHandle);

static inline int ATTO_FUNCTION(network_apply)(int deviceHandle) {
    return __SEN_1_0_0_network_apply(deviceHandle);
}


/** @brief @SEN_network_verify
*  Verifies if the temporary IP configuration is correct.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_verify(int deviceHandle);

static inline int ATTO_FUNCTION(network_verify)(int deviceHandle) {
    return __SEN_1_0_0_network_verify(deviceHandle);
}


/** @brief @SEN_network_discard
*  Discards the temporary IP configuration.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_discard(int deviceHandle);

static inline int ATTO_FUNCTION(network_discard)(int deviceHandle) {
    return __SEN_1_0_0_network_discard(deviceHandle);
}


/** @brief @SEN_network_getWifiPresent
*  Checks if a WiFi interface is present.
*
*  @param deviceHandle     Handle of device
*
*  @param value_present    present true if the interface is present, else false
*
*  @return present true if the interface is present, else false
*/
int ATTOCUBE_API __SEN_1_0_0_network_getWifiPresent(int deviceHandle, bool* value_present);

static inline int ATTO_FUNCTION(network_getWifiPresent)(int deviceHandle, bool* value_present) {
    return __SEN_1_0_0_network_getWifiPresent(deviceHandle, value_present);
}


/** @brief @SEN_network_setWifiMode
*  Changes the operation mode of the WiFi adapter.
*
*  @param deviceHandle     Handle of device
*  @param mode             0 = access point; 1 = WiFi client
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setWifiMode(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(network_setWifiMode)(int deviceHandle, int mode) {
    return __SEN_1_0_0_network_setWifiMode(deviceHandle, mode);
}


/** @brief @SEN_network_getWifiMode
*  Gets the operation mode of the WiFi adapter.
*
*  @param deviceHandle     Handle of device
*
*  @param value_mode       mode 0 = access point; 1 = WiFi client
*
*  @return mode 0 = access point; 1 = WiFi client
*/
int ATTOCUBE_API __SEN_1_0_0_network_getWifiMode(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(network_getWifiMode)(int deviceHandle, int* value_mode) {
    return __SEN_1_0_0_network_getWifiMode(deviceHandle, value_mode);
}


/** @brief @SEN_network_setWifiSSID
*  Changes the SSID of the network hosted (mode: access point) or connected to (mode: client).
*
*  @param deviceHandle     Handle of device
*  @param SSID             SSID string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setWifiSSID(int deviceHandle, const char* SSID);

static inline int ATTO_FUNCTION(network_setWifiSSID)(int deviceHandle, const char* SSID) {
    return __SEN_1_0_0_network_setWifiSSID(deviceHandle, SSID);
}


/** @brief @SEN_network_getWifiSSID
*  Gets the SSID of the network hosted (mode: access point) or connected to (mode: client).
*
*  @param deviceHandle     Handle of device
*
*  @param value_SSID       SSID SSID string
*  @param size             Maximum size of buffer value_SSID
*
*  @return SSID SSID string
*/
int ATTOCUBE_API __SEN_1_0_0_network_getWifiSSID(int deviceHandle, char* value_SSID, int size);

static inline int ATTO_FUNCTION(network_getWifiSSID)(int deviceHandle, char* value_SSID, int size) {
    return __SEN_1_0_0_network_getWifiSSID(deviceHandle, value_SSID, size);
}


/** @brief @SEN_network_setWifiPassphrase
*  Changes the passphrase of the network hosted (mode: access point) or connected to (mode: client).
*
*  @param deviceHandle     Handle of device
*  @param psk              pre-shared key
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_setWifiPassphrase(int deviceHandle, const char* psk);

static inline int ATTO_FUNCTION(network_setWifiPassphrase)(int deviceHandle, const char* psk) {
    return __SEN_1_0_0_network_setWifiPassphrase(deviceHandle, psk);
}


/** @brief @SEN_network_getWifiPassphrase
*  Gets the passphrase of the network hosted (mode: Access point) or connected to (mode: client).
*
*  @param deviceHandle     Handle of device
*
*  @param value_psk        psk pre-shared key
*  @param size             Maximum size of buffer value_psk
*
*  @return psk pre-shared key
*/
int ATTOCUBE_API __SEN_1_0_0_network_getWifiPassphrase(int deviceHandle, char* value_psk, int size);

static inline int ATTO_FUNCTION(network_getWifiPassphrase)(int deviceHandle, char* value_psk, int size) {
    return __SEN_1_0_0_network_getWifiPassphrase(deviceHandle, value_psk, size);
}


/** @brief @SEN_network_configureWifi
*  Changes the WiFi configuration and applies it.
*
*  @param deviceHandle     Handle of device
*  @param mode             0 = access point; 1 = WiFi client
*  @param SSID             SSID string
*  @param psk              pre-shared key
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_network_configureWifi(int deviceHandle, int mode, const char* SSID, const char* psk);

static inline int ATTO_FUNCTION(network_configureWifi)(int deviceHandle, int mode, const char* SSID, const char* psk) {
    return __SEN_1_0_0_network_configureWifi(deviceHandle, mode, SSID, psk);
}


/** @brief @SEN_setDeviceName
*  Sets custom name for the device.
*
*  @param deviceHandle     Handle of device
*  @param name             device name
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_setDeviceName(int deviceHandle, const char* name);

static inline int ATTO_FUNCTION(setDeviceName)(int deviceHandle, const char* name) {
    return __SEN_1_0_0_system_service_setDeviceName(deviceHandle, name);
}


/** @brief @SEN_getDeviceName
*  Gets the current device name.
*
*  @param deviceHandle     Handle of device
*
*  @param value_name       name current device name
*  @param size             Maximum size of buffer value_name
*
*  @return name current device name
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_getDeviceName(int deviceHandle, char* value_name, int size);

static inline int ATTO_FUNCTION(getDeviceName)(int deviceHandle, char* value_name, int size) {
    return __SEN_1_0_0_system_service_getDeviceName(deviceHandle, value_name, size);
}


/** @brief @SEN_rebootSystem
*  Reboots the device.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_rebootSystem(int deviceHandle);

static inline int ATTO_FUNCTION(rebootSystem)(int deviceHandle) {
    return __SEN_1_0_0_system_service_rebootSystem(deviceHandle);
}


/** @brief @SEN_factoryReset
*  Turns on the factory reset flag.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_factoryReset(int deviceHandle);

static inline int ATTO_FUNCTION(factoryReset)(int deviceHandle) {
    return __SEN_1_0_0_system_service_factoryReset(deviceHandle);
}


/** @brief @SEN_softReset
*  Performs a soft reset (factory reset without deleting the network settings).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_softReset(int deviceHandle);

static inline int ATTO_FUNCTION(softReset)(int deviceHandle) {
    return __SEN_1_0_0_system_service_softReset(deviceHandle);
}


/** @brief @SEN_errorNumberToString
*  Gets a description of an error code.
*
*  @param deviceHandle     Handle of device
*  @param language         integer: Language code 0 for the error name, 1 for a more user-friendly error message
*  @param errNbr           error code to translate
*
*  @param value_message    message error description
*  @param size             Maximum size of buffer value_message
*
*  @return message error description
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_errorNumberToString(int deviceHandle, int language, int errNbr, char* value_message, int size);

static inline int ATTO_FUNCTION(errorNumberToString)(int deviceHandle, int language, int errNbr, char* value_message, int size) {
    return __SEN_1_0_0_system_service_errorNumberToString(deviceHandle, language, errNbr, value_message, size);
}


/** @brief @SEN_errorNumberToRecommendation
*  Gets a recommendation for the error code.
*
*  @param deviceHandle     Handle of device
*  @param language         integer: Language code
*  @param errNbr           error code to translate
*
*  @param value_string     string: error recommendation (currently returning an int = 0 until we have recommendations)
*  @param size             Maximum size of buffer value_string
*
*  @return string: error recommendation (currently returning an int = 0 until we have recommendations)
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_errorNumberToRecommendation(int deviceHandle, int language, int errNbr, char* value_string, int size);

static inline int ATTO_FUNCTION(errorNumberToRecommendation)(int deviceHandle, int language, int errNbr, char* value_string, int size) {
    return __SEN_1_0_0_system_service_errorNumberToRecommendation(deviceHandle, language, errNbr, value_string, size);
}


/** @brief @SEN_getFirmwareVersion
*  Gets the firmware version of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_FWversion  FWversion firmware version
*  @param size             Maximum size of buffer value_FWversion
*
*  @return FWversion firmware version
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_getFirmwareVersion(int deviceHandle, char* value_FWversion, int size);

static inline int ATTO_FUNCTION(getFirmwareVersion)(int deviceHandle, char* value_FWversion, int size) {
    return __SEN_1_0_0_system_service_getFirmwareVersion(deviceHandle, value_FWversion, size);
}


/** @brief @SEN_getHardwareInfo
*  Retrieves the hardware information of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param hardware_info_string hardware_info_string
*  @param size             Maximum size of buffer hardware_info_string
*
*  @return hardware_info_string
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_getHardwareInfo(int deviceHandle, char* hardware_info_string, int size);

static inline int ATTO_FUNCTION(getHardwareInfo)(int deviceHandle, char* hardware_info_string, int size) {
    return __SEN_1_0_0_system_service_getHardwareInfo(deviceHandle, hardware_info_string, size);
}


/** @brief @SEN_getHostname
*  Returns the device hostname.
*
*  @param deviceHandle     Handle of device
*
*  @param value_name       name hostname
*  @param size             Maximum size of buffer value_name
*
*  @return name hostname
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_getHostname(int deviceHandle, char* value_name, int size);

static inline int ATTO_FUNCTION(getHostname)(int deviceHandle, char* value_name, int size) {
    return __SEN_1_0_0_system_service_getHostname(deviceHandle, value_name, size);
}


/** @brief @SEN_getMacAddress
*  Gets the mac address of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_mac        mac mac address
*  @param size             Maximum size of buffer value_mac
*
*  @return mac mac address
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_getMacAddress(int deviceHandle, char* value_mac, int size);

static inline int ATTO_FUNCTION(getMacAddress)(int deviceHandle, char* value_mac, int size) {
    return __SEN_1_0_0_system_service_getMacAddress(deviceHandle, value_mac, size);
}


/** @brief @SEN_getSerialNumber
*  Gets the serial number of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_SN         SN serial number
*  @param size             Maximum size of buffer value_SN
*
*  @return SN serial number
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_getSerialNumber(int deviceHandle, char* value_SN, int size);

static inline int ATTO_FUNCTION(getSerialNumber)(int deviceHandle, char* value_SN, int size) {
    return __SEN_1_0_0_system_service_getSerialNumber(deviceHandle, value_SN, size);
}


/** @brief @SEN_getFluxCode
*  Gets the flux code of the system.
*
*  @param deviceHandle     Handle of device
*
*  @param value_code       code flux code
*  @param size             Maximum size of buffer value_code
*
*  @return code flux code
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_getFluxCode(int deviceHandle, char* value_code, int size);

static inline int ATTO_FUNCTION(getFluxCode)(int deviceHandle, char* value_code, int size) {
    return __SEN_1_0_0_system_service_getFluxCode(deviceHandle, value_code, size);
}


/** @brief @SEN_updateTimeFromInternet
*  Updates system time by querying attocube.com.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_updateTimeFromInternet(int deviceHandle);

static inline int ATTO_FUNCTION(updateTimeFromInternet)(int deviceHandle) {
    return __SEN_1_0_0_system_service_updateTimeFromInternet(deviceHandle);
}


/** @brief @SEN_setTime
*  Sets system time manually.
*
*  @param deviceHandle     Handle of device
*  @param day              value from 1 to 31
*  @param month            value from 1 to 12
*  @param year             value (e.g. 2021)
*  @param hour             value from 0 to 23
*  @param minute           value from 0 to 59
*  @param second           value from 0 to 59
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_service_setTime(int deviceHandle, int day, int month, int year, int hour, int minute, int second);

static inline int ATTO_FUNCTION(setTime)(int deviceHandle, int day, int month, int year, int hour, int minute, int second) {
    return __SEN_1_0_0_system_service_setTime(deviceHandle, day, month, year, hour, minute, second);
}


/** @brief @SEN_manual_getHumidityInPercent
*  Reads out the manually configured humidity for compensation mode 1.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*
*  @param humidity         value in percent
*
*  @return value in percent
*/
int ATTOCUBE_API __SEN_1_0_0_manual_getHumidityInPercent(int deviceHandle, int axis, double* humidity);

static inline int ATTO_FUNCTION(manual_getHumidityInPercent)(int deviceHandle, int axis, double* humidity) {
    return __SEN_1_0_0_manual_getHumidityInPercent(deviceHandle, axis, humidity);
}


/** @brief @SEN_manual_getPressureInHPa
*  Reads out the manually configured air pressure for compensation mode 1.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*
*  @param pressure         value in hPa
*
*  @return value in hPa
*/
int ATTOCUBE_API __SEN_1_0_0_manual_getPressureInHPa(int deviceHandle, int axis, double* pressure);

static inline int ATTO_FUNCTION(manual_getPressureInHPa)(int deviceHandle, int axis, double* pressure) {
    return __SEN_1_0_0_manual_getPressureInHPa(deviceHandle, axis, pressure);
}


/** @brief @SEN_manual_getRefractiveIndex
*  Reads out the manually configured refractive index for compensation mode 2.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*
*  @param rindex           refractive index
*
*  @return refractive index
*/
int ATTOCUBE_API __SEN_1_0_0_manual_getRefractiveIndex(int deviceHandle, int axis, double* rindex);

static inline int ATTO_FUNCTION(manual_getRefractiveIndex)(int deviceHandle, int axis, double* rindex) {
    return __SEN_1_0_0_manual_getRefractiveIndex(deviceHandle, axis, rindex);
}


/** @brief @SEN_manual_getTemperatureInDegrees
*  Reads out the manually configured temperature for compensation mode 1.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*
*  @param temperature      value in degrees Celsius
*
*  @return value in degrees Celsius
*/
int ATTOCUBE_API __SEN_1_0_0_manual_getTemperatureInDegrees(int deviceHandle, int axis, double* temperature);

static inline int ATTO_FUNCTION(manual_getTemperatureInDegrees)(int deviceHandle, int axis, double* temperature) {
    return __SEN_1_0_0_manual_getTemperatureInDegrees(deviceHandle, axis, temperature);
}


/** @brief @SEN_manual_setHumidityInPercent
*  Sets the manually configured humidity for compensation mode 1. The input range is defined to 0 to 100 % (valid range for the Ciddor Equation).
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*  @param humidity         value from 0 % to 100 %
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_manual_setHumidityInPercent(int deviceHandle, int axis, double humidity);

static inline int ATTO_FUNCTION(manual_setHumidityInPercent)(int deviceHandle, int axis, double humidity) {
    return __SEN_1_0_0_manual_setHumidityInPercent(deviceHandle, axis, humidity);
}


/** @brief @SEN_manual_setPressureInHPa
*  Sets the manually configured air pressure for compensation mode 1. The input range is defined to 800 to 1200 hPa (valid range for the Ciddor Equation).
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*  @param pressure         value from 800 hPa to 1200 hPa
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_manual_setPressureInHPa(int deviceHandle, int axis, double pressure);

static inline int ATTO_FUNCTION(manual_setPressureInHPa)(int deviceHandle, int axis, double pressure) {
    return __SEN_1_0_0_manual_setPressureInHPa(deviceHandle, axis, pressure);
}


/** @brief @SEN_manual_setRefractiveIndex
*  Sets the manually configured refractive index for the compensation mode 2. The input range is defined to be greater than 1.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*  @param rindex           refractive index
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_manual_setRefractiveIndex(int deviceHandle, int axis, double rindex);

static inline int ATTO_FUNCTION(manual_setRefractiveIndex)(int deviceHandle, int axis, double rindex) {
    return __SEN_1_0_0_manual_setRefractiveIndex(deviceHandle, axis, rindex);
}


/** @brief @SEN_manual_setTemperatureInDegrees
*  Sets the manually configured temperature for compensation mode 1. The input range is defined to -40 to +100 °C (valid range for the Ciddor Equation).
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*  @param temperature      value from -40 °C to +100 °C
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_manual_setTemperatureInDegrees(int deviceHandle, int axis, double temperature);

static inline int ATTO_FUNCTION(manual_setTemperatureInDegrees)(int deviceHandle, int axis, double temperature) {
    return __SEN_1_0_0_manual_setTemperatureInDegrees(deviceHandle, axis, temperature);
}


/** @brief @SEN_ecu_disable
*  Disables the ECU interface.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_disable(int deviceHandle);

static inline int ATTO_FUNCTION(ecu_disable)(int deviceHandle) {
    return __SEN_1_0_0_ecu_disable(deviceHandle);
}


/** @brief @SEN_ecu_enable
*  Enables the ECU interface.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_enable(int deviceHandle);

static inline int ATTO_FUNCTION(ecu_enable)(int deviceHandle) {
    return __SEN_1_0_0_ecu_enable(deviceHandle);
}


/** @brief @SEN_ecu_getConnected
*  Reads out whether the ECU interface is physically connected or not.
*
*  @param deviceHandle     Handle of device
*
*  @param connected        true = connected; false = disconnected
*
*  @return true = connected; false = disconnected
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_getConnected(int deviceHandle, bool* connected);

static inline int ATTO_FUNCTION(ecu_getConnected)(int deviceHandle, bool* connected) {
    return __SEN_1_0_0_ecu_getConnected(deviceHandle, connected);
}


/** @brief @SEN_ecu_getEnabled
*  Reads out whether the ECU interface is enabled or not. Enabling the ECU interface is crucial for working with the ECU.
*
*  @param deviceHandle     Handle of device
*
*  @param enabled          true = enabled; false = disabled
*
*  @return true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_getEnabled(int deviceHandle, bool* enabled);

static inline int ATTO_FUNCTION(ecu_getEnabled)(int deviceHandle, bool* enabled) {
    return __SEN_1_0_0_ecu_getEnabled(deviceHandle, enabled);
}


/** @brief @SEN_ecu_getHumidityInPercent
*  Reads out the ECU measured air humidity in percent.
*
*  @param deviceHandle     Handle of device
*
*  @param humidity         value in percent
*
*  @return value in percent
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_getHumidityInPercent(int deviceHandle, double* humidity);

static inline int ATTO_FUNCTION(ecu_getHumidityInPercent)(int deviceHandle, double* humidity) {
    return __SEN_1_0_0_ecu_getHumidityInPercent(deviceHandle, humidity);
}


/** @brief @SEN_ecu_getPressureInHPa
*  Reads out the ECU measured air pressure in hPa.
*
*  @param deviceHandle     Handle of device
*
*  @param pressure         value in hPa
*
*  @return value in hPa
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_getPressureInHPa(int deviceHandle, double* pressure);

static inline int ATTO_FUNCTION(ecu_getPressureInHPa)(int deviceHandle, double* pressure) {
    return __SEN_1_0_0_ecu_getPressureInHPa(deviceHandle, pressure);
}


/** @brief @SEN_ecu_getRefractiveIndex
*  Reads out the ECU estimated refractive index from the current ECU values. To get the refractive index for other compensation modes, please refer to the getRefractiveIndexForCompensation function.
*
*  @param deviceHandle     Handle of device
*
*  @param rIndex           refractive index
*
*  @return refractive index
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_getRefractiveIndex(int deviceHandle, double* rIndex);

static inline int ATTO_FUNCTION(ecu_getRefractiveIndex)(int deviceHandle, double* rIndex) {
    return __SEN_1_0_0_ecu_getRefractiveIndex(deviceHandle, rIndex);
}


/** @brief @SEN_ecu_getRefractiveIndexCompensationMode
*  Reads out the compensation mode which is currently used for the environmental compensation.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*
*  @param mode             0 = direct ECU mode 
1 = uses refractive index calculated from the manually set values
2 = uses manually set refrative index
*
*  @return 0 = direct ECU mode 
1 = uses refractive index calculated from the manually set values
2 = uses manually set refrative index
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_getRefractiveIndexCompensationMode(int deviceHandle, int axis, int* mode);

static inline int ATTO_FUNCTION(ecu_getRefractiveIndexCompensationMode)(int deviceHandle, int axis, int* mode) {
    return __SEN_1_0_0_ecu_getRefractiveIndexCompensationMode(deviceHandle, axis, mode);
}


/** @brief @SEN_ecu_getRefractiveIndexForCompensation
*  Reads out the refractive index used according to the current environmental compensation mode for a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*
*  @param rIndex           refractive index
*
*  @return refractive index
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_getRefractiveIndexForCompensation(int deviceHandle, int axis, double* rIndex);

static inline int ATTO_FUNCTION(ecu_getRefractiveIndexForCompensation)(int deviceHandle, int axis, double* rIndex) {
    return __SEN_1_0_0_ecu_getRefractiveIndexForCompensation(deviceHandle, axis, rIndex);
}


/** @brief @SEN_ecu_getTemperatureInDegrees
*  Reads out the ECU measured air temperature in degrees Celsius.
*
*  @param deviceHandle     Handle of device
*
*  @param temperature      value in degrees Celsius
*
*  @return value in degrees Celsius
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_getTemperatureInDegrees(int deviceHandle, double* temperature);

static inline int ATTO_FUNCTION(ecu_getTemperatureInDegrees)(int deviceHandle, double* temperature) {
    return __SEN_1_0_0_ecu_getTemperatureInDegrees(deviceHandle, temperature);
}


/** @brief @SEN_ecu_setRefractiveIndexCompensationMode
*  Sets the refractive index compensation mode.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
*  @param mode             0 = direct ECU mode 
1 = uses refractive index calculated from the manually set values
2 = uses manually set refrative index
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_ecu_setRefractiveIndexCompensationMode(int deviceHandle, int axis, int mode);

static inline int ATTO_FUNCTION(ecu_setRefractiveIndexCompensationMode)(int deviceHandle, int axis, int mode) {
    return __SEN_1_0_0_ecu_setRefractiveIndexCompensationMode(deviceHandle, axis, mode);
}


/** @brief @SEN_adjustment_getContrastInPermille
*  This function can be used to monitor the alignment contrast (peak-to-peak of the basic interference signal amplitude) and the baseline (its offset) during alignment mode.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_warningNo  warningNo warning code, can be converted into a string using the errorNumberToString function
*  @param value_contrast   contrast contrast of the base band signal in permille
*  @param value_baseline   baseline offset of the contrast measurement in permille
*  @param value_mixcontrast mixcontrast lower contrast measurement when measuring a mixed contrast (indicated by error code)
*
*  @return warningNo warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_adjustment_getContrastInPermille(int deviceHandle, int axis, int* value_warningNo, int* value_contrast, int* value_baseline, int* value_mixcontrast);

static inline int ATTO_FUNCTION(adjustment_getContrastInPermille)(int deviceHandle, int axis, int* value_warningNo, int* value_contrast, int* value_baseline, int* value_mixcontrast) {
    return __SEN_1_0_0_adjustment_getContrastInPermille(deviceHandle, axis, value_warningNo, value_contrast, value_baseline, value_mixcontrast);
}


/** @brief @SEN_adjustment_getAdjustmentEnabled
*  This function can be used to see if the adjustment is running.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled; false = disabled
*
*  @return enabled true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_adjustment_getAdjustmentEnabled(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(adjustment_getAdjustmentEnabled)(int deviceHandle, bool* value_enabled) {
    return __SEN_1_0_0_adjustment_getAdjustmentEnabled(deviceHandle, value_enabled);
}


/** @brief @SEN_axis_getPassMode
*  Reads out the current pass mode.
*
*  @param deviceHandle     Handle of device
*
*  @param value_mode       mode 0 = single; pass 1 = dual pass
*
*  @return mode 0 = single; pass 1 = dual pass
*/
int ATTOCUBE_API __SEN_1_0_0_axis_getPassMode(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(axis_getPassMode)(int deviceHandle, int* value_mode) {
    return __SEN_1_0_0_axis_getPassMode(deviceHandle, value_mode);
}


/** @brief @SEN_axis_setPassMode
*  Sets the desired pass mode.
*
*  @param deviceHandle     Handle of device
*  @param mode             0 = single pass; 1 = dual pass
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_axis_setPassMode(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(axis_setPassMode)(int deviceHandle, int mode) {
    return __SEN_1_0_0_axis_setPassMode(deviceHandle, mode);
}


/** @brief @SEN_axis_getMasterAxis
*  Returns the master axis (for more information, please refer to the IDS User Manual).
*
*  @param deviceHandle     Handle of device
*
*  @param value_axis       axis [0|1|2]
*
*  @return axis [0|1|2]
*/
int ATTOCUBE_API __SEN_1_0_0_axis_getMasterAxis(int deviceHandle, int* value_axis);

static inline int ATTO_FUNCTION(axis_getMasterAxis)(int deviceHandle, int* value_axis) {
    return __SEN_1_0_0_axis_getMasterAxis(deviceHandle, value_axis);
}


/** @brief @SEN_axis_setMasterAxis
*  Sets the master axis (for more information, please refer to the IDS User Manual).
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_axis_setMasterAxis(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(axis_setMasterAxis)(int deviceHandle, int axis) {
    return __SEN_1_0_0_axis_setMasterAxis(deviceHandle, axis);
}


/** @brief @SEN_axis_apply
*  Applies new axis settings.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_axis_apply(int deviceHandle);

static inline int ATTO_FUNCTION(axis_apply)(int deviceHandle) {
    return __SEN_1_0_0_axis_apply(deviceHandle);
}


/** @brief @SEN_axis_setAutoMasterAxis
*  Enables the automatic configuration of the master axis during measurement initialization.
*
*  @param deviceHandle     Handle of device
*  @param automatic        true = automatic; false = manual
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_axis_setAutoMasterAxis(int deviceHandle, bool automatic);

static inline int ATTO_FUNCTION(axis_setAutoMasterAxis)(int deviceHandle, bool automatic) {
    return __SEN_1_0_0_axis_setAutoMasterAxis(deviceHandle, automatic);
}


/** @brief @SEN_axis_getAutoMasterAxis
*  Gets status of the automatic configuration of the master axis.
*
*  @param deviceHandle     Handle of device
*
*  @param value_automatic  automatic true = automatic; false = manual (default: true)
*
*  @return automatic true = automatic; false = manual (default: true)
*/
int ATTOCUBE_API __SEN_1_0_0_axis_getAutoMasterAxis(int deviceHandle, bool* value_automatic);

static inline int ATTO_FUNCTION(axis_getAutoMasterAxis)(int deviceHandle, bool* value_automatic) {
    return __SEN_1_0_0_axis_getAutoMasterAxis(deviceHandle, value_automatic);
}


/** @brief @SEN_axis_getSupportedAxes
*  Gets supported IDS axes for application.
*
*  @param deviceHandle     Handle of device
*
*  @param value_supportedAxis1 supportedAxis1 true = supported; false = unsupported
*  @param value_supportedAxis2 supportedAxis2 true = supported; false = unsupported
*  @param value_supportedAxis3 supportedAxis3 true = supported; false = unsupported
*
*  @return supportedAxis1 true = supported; false = unsupported
*/
int ATTOCUBE_API __SEN_1_0_0_axis_getSupportedAxes(int deviceHandle, bool* value_supportedAxis1, bool* value_supportedAxis2, bool* value_supportedAxis3);

static inline int ATTO_FUNCTION(axis_getSupportedAxes)(int deviceHandle, bool* value_supportedAxis1, bool* value_supportedAxis2, bool* value_supportedAxis3) {
    return __SEN_1_0_0_axis_getSupportedAxes(deviceHandle, value_supportedAxis1, value_supportedAxis2, value_supportedAxis3);
}


/** @brief @SEN_axis_discard
*  Discards new axis settings.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_axis_discard(int deviceHandle);

static inline int ATTO_FUNCTION(axis_discard)(int deviceHandle) {
    return __SEN_1_0_0_axis_discard(deviceHandle);
}


/** @brief @SEN_displacement_getMeasurementEnabled
*  This function can be used to see if the measurement is running.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled; false = disabled
*
*  @return enabled true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getMeasurementEnabled(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(displacement_getMeasurementEnabled)(int deviceHandle, bool* value_enabled) {
    return __SEN_1_0_0_displacement_getMeasurementEnabled(deviceHandle, value_enabled);
}


/** @brief @SEN_displacement_getAverageN
*  Reads out the averaging (lowpass) parameter N.
*
*  @param deviceHandle     Handle of device
*
*  @param value_averageN   averageN value from 0 to 24
*
*  @return averageN value from 0 to 24
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getAverageN(int deviceHandle, int* value_averageN);

static inline int ATTO_FUNCTION(displacement_getAverageN)(int deviceHandle, int* value_averageN) {
    return __SEN_1_0_0_displacement_getAverageN(deviceHandle, value_averageN);
}


/** @brief @SEN_displacement_setAverageN
*  Sets the averaging (lowpass) parameter N.
*
*  @param deviceHandle     Handle of device
*  @param averageN         value from 0 to 24
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_setAverageN(int deviceHandle, int averageN);

static inline int ATTO_FUNCTION(displacement_setAverageN)(int deviceHandle, int averageN) {
    return __SEN_1_0_0_displacement_setAverageN(deviceHandle, averageN);
}


/** @brief @SEN_displacement_getAxisSignalQuality
*  This function can be used to monitor the signal contrast (peak-to-peak of the basic interference signal amplitude) and the baseline (its offset) during a running measurement.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_warningNo  warningNo warning code, can be converted into a string using the errorNumberToString function
*  @param value_contrast   contrast contrast of the base band signal in permille
*  @param value_baseline   baseline offset of the contrast measurement in permille
*
*  @return warningNo warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getAxisSignalQuality(int deviceHandle, int axis, int* value_warningNo, int* value_contrast, int* value_baseline);

static inline int ATTO_FUNCTION(displacement_getAxisSignalQuality)(int deviceHandle, int axis, int* value_warningNo, int* value_contrast, int* value_baseline) {
    return __SEN_1_0_0_displacement_getAxisSignalQuality(deviceHandle, axis, value_warningNo, value_contrast, value_baseline);
}


/** @brief @SEN_displacement_getReferencePosition
*  Reads out the reference position value of the specific measurement axis./nThe reference position information is estimated at the measurement initialization procedure or on reset position.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_warningNo  warningNo warning code, can be converted into a string using the errorNumberToString function
*  @param value_position   position reference position of the axis in pm
*
*  @return warningNo warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getReferencePosition(int deviceHandle, int axis, int* value_warningNo, double* value_position);

static inline int ATTO_FUNCTION(displacement_getReferencePosition)(int deviceHandle, int axis, int* value_warningNo, double* value_position) {
    return __SEN_1_0_0_displacement_getReferencePosition(deviceHandle, axis, value_warningNo, value_position);
}


/** @brief @SEN_displacement_getReferencePositions
*  Reads out the reference position value of all three measurement axes.
*
*  @param deviceHandle     Handle of device
*
*  @param value_warningNo  warningNo warning code, can be converted into a string using the errorNumberToString function
*  @param value_position1  position0 reference position of the axis 0 in pm
*  @param value_position2  position1 reference position of the axis 1 in pm
*  @param value_position3  position2 reference position of the axis 2 in pm
*
*  @return warningNo warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getReferencePositions(int deviceHandle, int* value_warningNo, double* value_position1, double* value_position2, double* value_position3);

static inline int ATTO_FUNCTION(displacement_getReferencePositions)(int deviceHandle, int* value_warningNo, double* value_position1, double* value_position2, double* value_position3) {
    return __SEN_1_0_0_displacement_getReferencePositions(deviceHandle, value_warningNo, value_position1, value_position2, value_position3);
}


/** @brief @SEN_displacement_getAbsolutePosition
*  This function outputs the sum of the static absolute position register value and the continuously updated displacement register value for a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_warningNo  warningNo warning code, can be converted into a string using the errorNumberToString function
*  @param value_position   position absolute position of the axis in pm
*
*  @return warningNo warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getAbsolutePosition(int deviceHandle, int axis, int* value_warningNo, double* value_position);

static inline int ATTO_FUNCTION(displacement_getAbsolutePosition)(int deviceHandle, int axis, int* value_warningNo, double* value_position) {
    return __SEN_1_0_0_displacement_getAbsolutePosition(deviceHandle, axis, value_warningNo, value_position);
}


/** @brief @SEN_displacement_getAbsolutePositions
*  This function outputs the sum of the static absolute position register value and the continuously updated displacement register value for all three measurement axes.
*
*  @param deviceHandle     Handle of device
*
*  @param value_warningNo  warningNo warning code, can be converted into a string using the errorNumberToString function
*  @param value_position1  position0 absolute position of the axis 0 in pm
*  @param value_position2  position1 absolute position of the axis 1 in pm
*  @param value_position3  position2 absolute position of the axis 2 in pm
*
*  @return warningNo warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getAbsolutePositions(int deviceHandle, int* value_warningNo, double* value_position1, double* value_position2, double* value_position3);

static inline int ATTO_FUNCTION(displacement_getAbsolutePositions)(int deviceHandle, int* value_warningNo, double* value_position1, double* value_position2, double* value_position3) {
    return __SEN_1_0_0_displacement_getAbsolutePositions(deviceHandle, value_warningNo, value_position1, value_position2, value_position3);
}


/** @brief @SEN_displacement_getAxisDisplacement
*  Reads out the displacement value of a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_warningNo  warningNo warning code, can be converted into a string using the errorNumberToString function
*  @param value_displacement displacement displacement of the axis in pm
*
*  @return warningNo warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getAxisDisplacement(int deviceHandle, int axis, int* value_warningNo, double* value_displacement);

static inline int ATTO_FUNCTION(displacement_getAxisDisplacement)(int deviceHandle, int axis, int* value_warningNo, double* value_displacement) {
    return __SEN_1_0_0_displacement_getAxisDisplacement(deviceHandle, axis, value_warningNo, value_displacement);
}


/** @brief @SEN_displacement_getAxesDisplacement
*  Reads out the displacement values of all three measurement axes.
*
*  @param deviceHandle     Handle of device
*
*  @param value_warningNo  warningNo warning code, can be converted into a string using the errorNumberToString function
*  @param value_displacement1 displacement0 displacement of the axis 0 in pm
*  @param value_displacement2 displacement1 displacement of the axis 1 in pm
*  @param value_displacement3 displacement2 displacement of the axis 2 in pm
*
*  @return warningNo warning code, can be converted into a string using the errorNumberToString function
*/
int ATTOCUBE_API __SEN_1_0_0_displacement_getAxesDisplacement(int deviceHandle, int* value_warningNo, double* value_displacement1, double* value_displacement2, double* value_displacement3);

static inline int ATTO_FUNCTION(displacement_getAxesDisplacement)(int deviceHandle, int* value_warningNo, double* value_displacement1, double* value_displacement2, double* value_displacement3) {
    return __SEN_1_0_0_displacement_getAxesDisplacement(deviceHandle, value_warningNo, value_displacement1, value_displacement2, value_displacement3);
}


/** @brief @SEN_pilotlaser_enable
*  Enables the pilot laser.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_pilotlaser_enable(int deviceHandle);

static inline int ATTO_FUNCTION(pilotlaser_enable)(int deviceHandle) {
    return __SEN_1_0_0_pilotlaser_enable(deviceHandle);
}


/** @brief @SEN_pilotlaser_disable
*  Disables the pilot laser.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_pilotlaser_disable(int deviceHandle);

static inline int ATTO_FUNCTION(pilotlaser_disable)(int deviceHandle) {
    return __SEN_1_0_0_pilotlaser_disable(deviceHandle);
}


/** @brief @SEN_pilotlaser_getEnabled
*  Reads out whether the pilot laser is enabled or not.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled; false = disabled
*
*  @return enabled true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_pilotlaser_getEnabled(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(pilotlaser_getEnabled)(int deviceHandle, bool* value_enabled) {
    return __SEN_1_0_0_pilotlaser_getEnabled(deviceHandle, value_enabled);
}


/** @brief @SEN_realtime_getRtOutMode
*  Reads out the current real-time output mode.
*
*  @param deviceHandle     Handle of device
*
*  @param value_rtOutMode  rtOutMode 0 = HSSL (LVTTL), 1 = HSSL (LVDS), 2 = AquadB (LVTTL),/n3 = AquadB (LVDS), 4 = Sin/Cos (LVTTL error signal),/n5 = Sin/Cos (LVDS error signal), 6 = Linear (LVTTL error signal), 7 = Linear (LVDS error signal),/n8 = BiSS-C, 9 = Deactivated
*
*  @return rtOutMode 0 = HSSL (LVTTL), 1 = HSSL (LVDS), 2 = AquadB (LVTTL),/n3 = AquadB (LVDS), 4 = Sin/Cos (LVTTL error signal),/n5 = Sin/Cos (LVDS error signal), 6 = Linear (LVTTL error signal), 7 = Linear (LVDS error signal),/n8 = BiSS-C, 9 = Deactivated
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getRtOutMode(int deviceHandle, int* value_rtOutMode);

static inline int ATTO_FUNCTION(realtime_getRtOutMode)(int deviceHandle, int* value_rtOutMode) {
    return __SEN_1_0_0_realtime_getRtOutMode(deviceHandle, value_rtOutMode);
}


/** @brief @SEN_realtime_setRtOutMode
*  Sets the real-time output mode.
*
*  @param deviceHandle     Handle of device
*  @param rtOutMode        0 = HSSL (LVTTL), 1 = HSSL (LVDS), 2 = AquadB (LVTTL),/n3 = AquadB (LVDS), 4 = Sin/Cos (LVTTL error signal),/n5 = Sin/Cos (LVDS error signal), 6 = Linear (LVTTL error signal), 7 = Linear (LVDS error signal),/n8 = BiSS-C, 9 = Deactivated
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setRtOutMode(int deviceHandle, int rtOutMode);

static inline int ATTO_FUNCTION(realtime_setRtOutMode)(int deviceHandle, int rtOutMode) {
    return __SEN_1_0_0_realtime_setRtOutMode(deviceHandle, rtOutMode);
}


/** @brief @SEN_realtime_getRtDistanceMode
*  Reads out the distance mode.
*
*  @param deviceHandle     Handle of device
*
*  @param value_mode       mode 1 = Displacement (all modes)/n2 = Absolute Distance (HSSL mode and BiSS C mode)/n3 = Vibrometry (Linear mode only)
*
*  @return mode 1 = Displacement (all modes)/n2 = Absolute Distance (HSSL mode and BiSS C mode)/n3 = Vibrometry (Linear mode only)
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getRtDistanceMode(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(realtime_getRtDistanceMode)(int deviceHandle, int* value_mode) {
    return __SEN_1_0_0_realtime_getRtDistanceMode(deviceHandle, value_mode);
}


/** @brief @SEN_realtime_setRtDistanceMode
*  Sets the distance mode.
*
*  @param deviceHandle     Handle of device
*  @param mode             1 = Displacement (all modes)/n2 = Absolute Distance (HSSL mode and BiSS C mode)/n3 = Vibrometry (Linear mode only)
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setRtDistanceMode(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(realtime_setRtDistanceMode)(int deviceHandle, int mode) {
    return __SEN_1_0_0_realtime_setRtDistanceMode(deviceHandle, mode);
}


/** @brief @SEN_realtime_getResolutionBissC
*  Reads out the BiSS C resolution.
*
*  @param deviceHandle     Handle of device
*
*  @param value_resolution resolution value from 0 to 16
*
*  @return resolution value from 0 to 16
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getResolutionBissC(int deviceHandle, int* value_resolution);

static inline int ATTO_FUNCTION(realtime_getResolutionBissC)(int deviceHandle, int* value_resolution) {
    return __SEN_1_0_0_realtime_getResolutionBissC(deviceHandle, value_resolution);
}


/** @brief @SEN_realtime_setResolutionBissC
*  Sets the BiSS C resolution.
*
*  @param deviceHandle     Handle of device
*  @param resolution       value from 0 to 16
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setResolutionBissC(int deviceHandle, int resolution);

static inline int ATTO_FUNCTION(realtime_setResolutionBissC)(int deviceHandle, int resolution) {
    return __SEN_1_0_0_realtime_setResolutionBissC(deviceHandle, resolution);
}


/** @brief @SEN_realtime_getResolutionHsslLow
*  Reads out the HSSL resolution low bit.
*
*  @param deviceHandle     Handle of device
*
*  @param value_resolution resolution value from 0 to 46
*
*  @return resolution value from 0 to 46
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getResolutionHsslLow(int deviceHandle, int* value_resolution);

static inline int ATTO_FUNCTION(realtime_getResolutionHsslLow)(int deviceHandle, int* value_resolution) {
    return __SEN_1_0_0_realtime_getResolutionHsslLow(deviceHandle, value_resolution);
}


/** @brief @SEN_realtime_setResolutionHsslLow
*  Sets the HSSL resolution low bit.
*
*  @param deviceHandle     Handle of device
*  @param resolution       value from 0 to 46
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setResolutionHsslLow(int deviceHandle, int resolution);

static inline int ATTO_FUNCTION(realtime_setResolutionHsslLow)(int deviceHandle, int resolution) {
    return __SEN_1_0_0_realtime_setResolutionHsslLow(deviceHandle, resolution);
}


/** @brief @SEN_realtime_getResolutionHsslHigh
*  Reads out the HSSL resolution high bit.
*
*  @param deviceHandle     Handle of device
*
*  @param value_resolution resolution value from 1 to 47
*
*  @return resolution value from 1 to 47
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getResolutionHsslHigh(int deviceHandle, int* value_resolution);

static inline int ATTO_FUNCTION(realtime_getResolutionHsslHigh)(int deviceHandle, int* value_resolution) {
    return __SEN_1_0_0_realtime_getResolutionHsslHigh(deviceHandle, value_resolution);
}


/** @brief @SEN_realtime_setResolutionHsslHigh
*  Sets the HSSL resolution high bit.
*
*  @param deviceHandle     Handle of device
*  @param resolution       value from 1 to 47
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setResolutionHsslHigh(int deviceHandle, int resolution);

static inline int ATTO_FUNCTION(realtime_setResolutionHsslHigh)(int deviceHandle, int resolution) {
    return __SEN_1_0_0_realtime_setResolutionHsslHigh(deviceHandle, resolution);
}


/** @brief @SEN_realtime_getLinearRange
*  Reads out the range number N of Linear analog output mode.
*
*  @param deviceHandle     Handle of device
*
*  @param value_rangenumber rangenumber value from 0 to 34
*
*  @return rangenumber value from 0 to 34
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getLinearRange(int deviceHandle, int* value_rangenumber);

static inline int ATTO_FUNCTION(realtime_getLinearRange)(int deviceHandle, int* value_rangenumber) {
    return __SEN_1_0_0_realtime_getLinearRange(deviceHandle, value_rangenumber);
}


/** @brief @SEN_realtime_setLinearRange
*  Sets the range number of Linear analog output mode.
*
*  @param deviceHandle     Handle of device
*  @param rangenumber      value from 0 to 34
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setLinearRange(int deviceHandle, int rangenumber);

static inline int ATTO_FUNCTION(realtime_setLinearRange)(int deviceHandle, int rangenumber) {
    return __SEN_1_0_0_realtime_setLinearRange(deviceHandle, rangenumber);
}


/** @brief @SEN_realtime_getPeriodHsslClk
*  Reads out the HSSL period clock.
*
*  @param deviceHandle     Handle of device
*
*  @param value_period     period value from 40 ns to 10200 ns
*
*  @return period value from 40 ns to 10200 ns
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getPeriodHsslClk(int deviceHandle, int* value_period);

static inline int ATTO_FUNCTION(realtime_getPeriodHsslClk)(int deviceHandle, int* value_period) {
    return __SEN_1_0_0_realtime_getPeriodHsslClk(deviceHandle, value_period);
}


/** @brief @SEN_realtime_setPeriodHsslClk
*  Set the HSSL period clock.
*
*  @param deviceHandle     Handle of device
*  @param period           value from 40 ns to 10200 ns
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setPeriodHsslClk(int deviceHandle, int period);

static inline int ATTO_FUNCTION(realtime_setPeriodHsslClk)(int deviceHandle, int period) {
    return __SEN_1_0_0_realtime_setPeriodHsslClk(deviceHandle, period);
}


/** @brief @SEN_realtime_getPeriodHsslGap
*  Reads out the HSSL period gap as number of clocks.
*
*  @param deviceHandle     Handle of device
*
*  @param value_gap        gap value from 1 to 255
*
*  @return gap value from 1 to 255
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getPeriodHsslGap(int deviceHandle, int* value_gap);

static inline int ATTO_FUNCTION(realtime_getPeriodHsslGap)(int deviceHandle, int* value_gap) {
    return __SEN_1_0_0_realtime_getPeriodHsslGap(deviceHandle, value_gap);
}


/** @brief @SEN_realtime_setPeriodHsslGap
*  Set the HSSL period gap as number of clocks.
*
*  @param deviceHandle     Handle of device
*  @param gap              value from 1 to 255
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setPeriodHsslGap(int deviceHandle, int gap);

static inline int ATTO_FUNCTION(realtime_setPeriodHsslGap)(int deviceHandle, int gap) {
    return __SEN_1_0_0_realtime_setPeriodHsslGap(deviceHandle, gap);
}


/** @brief @SEN_realtime_getPeriodSinCosClk
*  Reads out the Sin/Cos and AquadB period clock.
*
*  @param deviceHandle     Handle of device
*
*  @param value_period     period value from 40 ns to 10200 ns
*
*  @return period value from 40 ns to 10200 ns
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getPeriodSinCosClk(int deviceHandle, int* value_period);

static inline int ATTO_FUNCTION(realtime_getPeriodSinCosClk)(int deviceHandle, int* value_period) {
    return __SEN_1_0_0_realtime_getPeriodSinCosClk(deviceHandle, value_period);
}


/** @brief @SEN_realtime_setPeriodSinCosClk
*  Sets the Sin/Cos and AquadB period clock.
*
*  @param deviceHandle     Handle of device
*  @param period           value from 40 ns to 10200 ns
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setPeriodSinCosClk(int deviceHandle, int period);

static inline int ATTO_FUNCTION(realtime_setPeriodSinCosClk)(int deviceHandle, int period) {
    return __SEN_1_0_0_realtime_setPeriodSinCosClk(deviceHandle, period);
}


/** @brief @SEN_realtime_getResolutionSinCos
*  Reads out the Sin/Cos and AquadB resolution.
*
*  @param deviceHandle     Handle of device
*
*  @param value_resolution resolution value from 1 pm to 65535 pm
*
*  @return resolution value from 1 pm to 65535 pm
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getResolutionSinCos(int deviceHandle, int* value_resolution);

static inline int ATTO_FUNCTION(realtime_getResolutionSinCos)(int deviceHandle, int* value_resolution) {
    return __SEN_1_0_0_realtime_getResolutionSinCos(deviceHandle, value_resolution);
}


/** @brief @SEN_realtime_setResolutionSinCos
*  Sets the Sin/Cos and AquadB resolution.
*
*  @param deviceHandle     Handle of device
*  @param resolution       value from 1 pm to 65535 pm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setResolutionSinCos(int deviceHandle, int resolution);

static inline int ATTO_FUNCTION(realtime_setResolutionSinCos)(int deviceHandle, int resolution) {
    return __SEN_1_0_0_realtime_setResolutionSinCos(deviceHandle, resolution);
}


/** @brief @SEN_realtime_getHighPassCutOffFreq
*  Reads out the high pass filter number of Linear analog output mode.
*
*  @param deviceHandle     Handle of device
*
*  @param value_filternumber filternumber value from 1 to 24
*
*  @return filternumber value from 1 to 24
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getHighPassCutOffFreq(int deviceHandle, int* value_filternumber);

static inline int ATTO_FUNCTION(realtime_getHighPassCutOffFreq)(int deviceHandle, int* value_filternumber) {
    return __SEN_1_0_0_realtime_getHighPassCutOffFreq(deviceHandle, value_filternumber);
}


/** @brief @SEN_realtime_setHighPassCutOffFreq
*  Sets the high pass filter number of Linear analog output mode.
*
*  @param deviceHandle     Handle of device
*  @param filternumber     value from 1 to 24
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setHighPassCutOffFreq(int deviceHandle, int filternumber);

static inline int ATTO_FUNCTION(realtime_setHighPassCutOffFreq)(int deviceHandle, int filternumber) {
    return __SEN_1_0_0_realtime_setHighPassCutOffFreq(deviceHandle, filternumber);
}


/** @brief @SEN_realtime_setAaf
*  Sets the anti-aliasing filter with assigned filter window.
*
*  @param deviceHandle     Handle of device
*  @param enable           true = enable; false = disable
*  @param attenuation      value from 3 dB to 30 dB
*  @param window           0 = Rectangular,/n1 = Cosine,/n2 = Cosine^2,/n3 = Hamming,/n4 = Raised Cosine
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setAaf(int deviceHandle, bool enable, int attenuation, int window);

static inline int ATTO_FUNCTION(realtime_setAaf)(int deviceHandle, bool enable, int attenuation, int window) {
    return __SEN_1_0_0_realtime_setAaf(deviceHandle, enable, attenuation, window);
}


/** @brief @SEN_realtime_getAafAttenuation
*  Returns the current attenuation of the anti-aliasing filter.
*
*  @param deviceHandle     Handle of device
*
*  @param value_attenuation attenuation value from 3 dB to 30 dB (default: 15 dB)
*
*  @return attenuation value from 3 dB to 30 dB (default: 15 dB)
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getAafAttenuation(int deviceHandle, int* value_attenuation);

static inline int ATTO_FUNCTION(realtime_getAafAttenuation)(int deviceHandle, int* value_attenuation) {
    return __SEN_1_0_0_realtime_getAafAttenuation(deviceHandle, value_attenuation);
}


/** @brief @SEN_realtime_getAafWindow
*  Returns the current filter window of the anti-aliasing filter.
*
*  @param deviceHandle     Handle of device
*
*  @param value_window     window 0 = Rectangular,/n1 = Cosine,/n2 = Cosine^2,/n3 = Hamming,/n4 = Raised Cosine (default)
*
*  @return window 0 = Rectangular,/n1 = Cosine,/n2 = Cosine^2,/n3 = Hamming,/n4 = Raised Cosine (default)
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getAafWindow(int deviceHandle, int* value_window);

static inline int ATTO_FUNCTION(realtime_getAafWindow)(int deviceHandle, int* value_window) {
    return __SEN_1_0_0_realtime_getAafWindow(deviceHandle, value_window);
}


/** @brief @SEN_realtime_getAafEnabled
*  Checks if the anti-aliasing filter is enabled.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled; false = disabled
*
*  @return enabled true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getAafEnabled(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(realtime_getAafEnabled)(int deviceHandle, bool* value_enabled) {
    return __SEN_1_0_0_realtime_getAafEnabled(deviceHandle, value_enabled);
}


/** @brief @SEN_realtime_enableRtAxis
*  Enables the real-time output of the specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param enabled          true = enable; false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_enableRtAxis(int deviceHandle, int axis, bool enabled);

static inline int ATTO_FUNCTION(realtime_enableRtAxis)(int deviceHandle, int axis, bool enabled) {
    return __SEN_1_0_0_realtime_enableRtAxis(deviceHandle, axis, enabled);
}


/** @brief @SEN_realtime_getRtAxisEnabled
*  Checks if the real-time output of the specific measurement axis is enabled.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param value_enabled    enabled true = enabled; false = disabled
*
*  @return enabled true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getRtAxisEnabled(int deviceHandle, int axis, bool* value_enabled);

static inline int ATTO_FUNCTION(realtime_getRtAxisEnabled)(int deviceHandle, int axis, bool* value_enabled) {
    return __SEN_1_0_0_realtime_getRtAxisEnabled(deviceHandle, axis, value_enabled);
}


/** @brief @SEN_realtime_apply
*  Applies new real-time settings.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_apply(int deviceHandle);

static inline int ATTO_FUNCTION(realtime_apply)(int deviceHandle) {
    return __SEN_1_0_0_realtime_apply(deviceHandle);
}


/** @brief @SEN_realtime_discard
*  Discards new real-time settings.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_discard(int deviceHandle);

static inline int ATTO_FUNCTION(realtime_discard)(int deviceHandle) {
    return __SEN_1_0_0_realtime_discard(deviceHandle);
}


/** @brief @SEN_realtime_enableTestChannel
*  Enables the test channel on measurement axis 0, which can be used for estimating the maximum signal range./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_enableTestChannel(int deviceHandle);

static inline int ATTO_FUNCTION(realtime_enableTestChannel)(int deviceHandle) {
    return __SEN_1_0_0_realtime_enableTestChannel(deviceHandle);
}


/** @brief @SEN_realtime_disableTestChannel
*  Disables the test channel.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_disableTestChannel(int deviceHandle);

static inline int ATTO_FUNCTION(realtime_disableTestChannel)(int deviceHandle) {
    return __SEN_1_0_0_realtime_disableTestChannel(deviceHandle);
}


/** @brief @SEN_realtime_getTestChannelEnabled
*  Checks if the test channels are enabled.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled; false = disabled
*
*  @return enabled true = enabled; false = disabled
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getTestChannelEnabled(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(realtime_getTestChannelEnabled)(int deviceHandle, bool* value_enabled) {
    return __SEN_1_0_0_realtime_getTestChannelEnabled(deviceHandle, value_enabled);
}


/** @brief @SEN_realtime_getInvertedErrorSignal
*  Checks if the error signal is inverted.
*
*  @param deviceHandle     Handle of device
*
*  @param value_inverted   inverted true = inverted; false = non-inverted
*
*  @return inverted true = inverted; false = non-inverted
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_getInvertedErrorSignal(int deviceHandle, bool* value_inverted);

static inline int ATTO_FUNCTION(realtime_getInvertedErrorSignal)(int deviceHandle, bool* value_inverted) {
    return __SEN_1_0_0_realtime_getInvertedErrorSignal(deviceHandle, value_inverted);
}


/** @brief @SEN_realtime_setInvertedErrorSignal
*  Inverts the error signal.
*
*  @param deviceHandle     Handle of device
*  @param inverted         true = inverted; false = non-inverted
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_realtime_setInvertedErrorSignal(int deviceHandle, int inverted);

static inline int ATTO_FUNCTION(realtime_setInvertedErrorSignal)(int deviceHandle, int inverted) {
    return __SEN_1_0_0_realtime_setInvertedErrorSignal(deviceHandle, inverted);
}


/** @brief @SEN_system_stopMeasurement
*  Stops the measurement system state.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_stopMeasurement(int deviceHandle);

static inline int ATTO_FUNCTION(system_stopMeasurement)(int deviceHandle) {
    return __SEN_1_0_0_system_stopMeasurement(deviceHandle);
}


/** @brief @SEN_system_startMeasurement
*  Starts the measurement system state./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function)
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_startMeasurement(int deviceHandle);

static inline int ATTO_FUNCTION(system_startMeasurement)(int deviceHandle) {
    return __SEN_1_0_0_system_startMeasurement(deviceHandle);
}


/** @brief @SEN_system_restartMeasurement
*  Restarts the absolute measurement system state./nThis function is only available in the "measurement running" state (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_restartMeasurement(int deviceHandle);

static inline int ATTO_FUNCTION(system_restartMeasurement)(int deviceHandle) {
    return __SEN_1_0_0_system_restartMeasurement(deviceHandle);
}


/** @brief @SEN_system_getAutoRestart
*  Gets the current configuration of the automatic measurement restart after reboot.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled; false = disabled (default: true)
*
*  @return enabled true = enabled; false = disabled (default: true)
*/
int ATTOCUBE_API __SEN_1_0_0_system_getAutoRestart(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(system_getAutoRestart)(int deviceHandle, bool* value_enabled) {
    return __SEN_1_0_0_system_getAutoRestart(deviceHandle, value_enabled);
}


/** @brief @SEN_system_setAutoRestart
*  Enables or disables the automatic measurement restart after reboot.
*
*  @param deviceHandle     Handle of device
*  @param enable           true = enable; false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_setAutoRestart(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(system_setAutoRestart)(int deviceHandle, bool enable) {
    return __SEN_1_0_0_system_setAutoRestart(deviceHandle, enable);
}


/** @brief @SEN_system_startOpticsAlignment
*  Starts the optical alignment system state./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_startOpticsAlignment(int deviceHandle);

static inline int ATTO_FUNCTION(system_startOpticsAlignment)(int deviceHandle) {
    return __SEN_1_0_0_system_startOpticsAlignment(deviceHandle);
}


/** @brief @SEN_system_stopOpticsAlignment
*  Stops the optical alignment system state./nThis function is only available in the "optics alignment running" state (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_stopOpticsAlignment(int deviceHandle);

static inline int ATTO_FUNCTION(system_stopOpticsAlignment)(int deviceHandle) {
    return __SEN_1_0_0_system_stopOpticsAlignment(deviceHandle);
}


/** @brief @SEN_system_resetAxes
*  Resets the displacement value of all measurement axes to zero.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_resetAxes(int deviceHandle);

static inline int ATTO_FUNCTION(system_resetAxes)(int deviceHandle) {
    return __SEN_1_0_0_system_resetAxes(deviceHandle);
}


/** @brief @SEN_system_resetAxis
*  Resets the displacement value of a specific measurement axis to zero.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_resetAxis(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(system_resetAxis)(int deviceHandle, int axis) {
    return __SEN_1_0_0_system_resetAxis(deviceHandle, axis);
}


/** @brief @SEN_system_resetError
*  Resets a measurement error that has been raised with the aim to continue the interrupted measurement./nIt is configurable if an additional renormalization process (please refer to the IDS User Manual) should be performed or not./n
  This function can be used in two cases:/n
 	1.
*
*  @param deviceHandle     Handle of device
*  @param performRenormalization true = enable; false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_resetError(int deviceHandle, bool performRenormalization);

static inline int ATTO_FUNCTION(system_resetError)(int deviceHandle, bool performRenormalization) {
    return __SEN_1_0_0_system_resetError(deviceHandle, performRenormalization);
}


/** @brief @SEN_system_getCurrentMode
*  Reads out the current device system state.
*
*  @param deviceHandle     Handle of device
*
*  @param value_mode       mode "system idle", "measurement starting", "measurement running", "measurement restarting",/n"optics alignment starting", "optics alignment running", "test channels enabled"
*  @param size             Maximum size of buffer value_mode
*
*  @return mode "system idle", "measurement starting", "measurement running", "measurement restarting",/n"optics alignment starting", "optics alignment running", "test channels enabled"
*/
int ATTOCUBE_API __SEN_1_0_0_system_getCurrentMode(int deviceHandle, char* value_mode, int size);

static inline int ATTO_FUNCTION(system_getCurrentMode)(int deviceHandle, char* value_mode, int size) {
    return __SEN_1_0_0_system_getCurrentMode(deviceHandle, value_mode, size);
}


/** @brief @SEN_system_getFpgaVersion
*  Reads out the device FPGA version.
*
*  @param deviceHandle     Handle of device
*
*  @param value_version    version version in the form X.Y.Z
*  @param size             Maximum size of buffer value_version
*
*  @return version version in the form X.Y.Z
*/
int ATTOCUBE_API __SEN_1_0_0_system_getFpgaVersion(int deviceHandle, char* value_version, int size);

static inline int ATTO_FUNCTION(system_getFpgaVersion)(int deviceHandle, char* value_version, int size) {
    return __SEN_1_0_0_system_getFpgaVersion(deviceHandle, value_version, size);
}


/** @brief @SEN_system_getDeviceType
*  Reads out the device type.
*
*  @param deviceHandle     Handle of device
*
*  @param value_type       type type of the device (e.g. "IDS3010")
*  @param size             Maximum size of buffer value_type
*
*  @return type type of the device (e.g. "IDS3010")
*/
int ATTOCUBE_API __SEN_1_0_0_system_getDeviceType(int deviceHandle, char* value_type, int size);

static inline int ATTO_FUNCTION(system_getDeviceType)(int deviceHandle, char* value_type, int size) {
    return __SEN_1_0_0_system_getDeviceType(deviceHandle, value_type, size);
}


/** @brief @SEN_system_getSystemError
*  Reads out the system error.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_getSystemError(int deviceHandle);

static inline int ATTO_FUNCTION(system_getSystemError)(int deviceHandle) {
    return __SEN_1_0_0_system_getSystemError(deviceHandle);
}


/** @brief @SEN_system_getNbrFeaturesActivated
*  Reads out the number of the activated features on the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_nbr        nbr the number of activated features
*
*  @return nbr the number of activated features
*/
int ATTOCUBE_API __SEN_1_0_0_system_getNbrFeaturesActivated(int deviceHandle, int* value_nbr);

static inline int ATTO_FUNCTION(system_getNbrFeaturesActivated)(int deviceHandle, int* value_nbr) {
    return __SEN_1_0_0_system_getNbrFeaturesActivated(deviceHandle, value_nbr);
}


/** @brief @SEN_system_getFeaturesName
*  Converts the device feature number to its corresponding name.
*
*  @param deviceHandle     Handle of device
*  @param featurenumber    number of features
*
*  @param value_names      names name of the corresponding feature
*  @param size             Maximum size of buffer value_names
*
*  @return names name of the corresponding feature
*/
int ATTOCUBE_API __SEN_1_0_0_system_getFeaturesName(int deviceHandle, int featurenumber, char* value_names, int size);

static inline int ATTO_FUNCTION(system_getFeaturesName)(int deviceHandle, int featurenumber, char* value_names, int size) {
    return __SEN_1_0_0_system_getFeaturesName(deviceHandle, featurenumber, value_names, size);
}


/** @brief @SEN_system_setOptimizeParametersDuringInit
*  Enables or disables the parameter optimization used for the automatic system compensation.
*
*  @param deviceHandle     Handle of device
*  @param enableFineTuning true = enable; false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_setOptimizeParametersDuringInit(int deviceHandle, bool enableFineTuning);

static inline int ATTO_FUNCTION(system_setOptimizeParametersDuringInit)(int deviceHandle, bool enableFineTuning) {
    return __SEN_1_0_0_system_setOptimizeParametersDuringInit(deviceHandle, enableFineTuning);
}


/** @brief @SEN_system_getOptimizeParametersDuringInit
*  Reads out the current parameter optimization configuration used for the automatic system compensation.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enableFineTuning enableFineTuning true = enable; false = disable
*
*  @return enableFineTuning true = enable; false = disable
*/
int ATTOCUBE_API __SEN_1_0_0_system_getOptimizeParametersDuringInit(int deviceHandle, bool* value_enableFineTuning);

static inline int ATTO_FUNCTION(system_getOptimizeParametersDuringInit)(int deviceHandle, bool* value_enableFineTuning) {
    return __SEN_1_0_0_system_getOptimizeParametersDuringInit(deviceHandle, value_enableFineTuning);
}


/** @brief @SEN_system_getInitMode
*  Returns the initialization mode.
*
*  @param deviceHandle     Handle of device
*
*  @param value_mode       mode 0 = High Accuracy Initialization; 1 = Quick Initialization (default: 0)
*
*  @return mode 0 = High Accuracy Initialization; 1 = Quick Initialization (default: 0)
*/
int ATTOCUBE_API __SEN_1_0_0_system_getInitMode(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(system_getInitMode)(int deviceHandle, int* value_mode) {
    return __SEN_1_0_0_system_getInitMode(deviceHandle, value_mode);
}


/** @brief @SEN_system_setInitMode
*  Sets the mode for the initialization procedure that is performed when starting a measurement.
*
*  @param deviceHandle     Handle of device
*  @param mode             0 = High Accuracy Initialization; 1 = Quick Initialization
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_setInitMode(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(system_setInitMode)(int deviceHandle, int mode) {
    return __SEN_1_0_0_system_setInitMode(deviceHandle, mode);
}


/** @brief @SEN_system_setErrorParameterSet
*  Sets the error parameter set.
*
*  @param deviceHandle     Handle of device
*  @param setnumber        1 = default mode: standard beam interruption detection (less sensitive)/n2 = strict mode: more sensitive beam interruption detection; improves responsiveness but may increase false positives
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API __SEN_1_0_0_system_setErrorParameterSet(int deviceHandle, int setnumber);

static inline int ATTO_FUNCTION(system_setErrorParameterSet)(int deviceHandle, int setnumber) {
    return __SEN_1_0_0_system_setErrorParameterSet(deviceHandle, setnumber);
}


/** @brief @SEN_system_getErrorParameterSet
*  Gets the applied error parameter set.
*
*  @param deviceHandle     Handle of device
*
*  @param value_setnumber  setnumber 1 = New defaults from 2.0.0: more senstive beam interrupt detection/n2 = Old defaults till 1.9.3: less senstive beam interrupt detection (legacy version)
*
*  @return setnumber 1 = New defaults from 2.0.0: more senstive beam interrupt detection/n2 = Old defaults till 1.9.3: less senstive beam interrupt detection (legacy version)
*/
int ATTOCUBE_API __SEN_1_0_0_system_getErrorParameterSet(int deviceHandle, int* value_setnumber);

static inline int ATTO_FUNCTION(system_getErrorParameterSet)(int deviceHandle, int* value_setnumber) {
    return __SEN_1_0_0_system_getErrorParameterSet(deviceHandle, value_setnumber);
}


#ifdef __cplusplus
}
#endif
#undef ATTO_PREFIX
#endif // __GENERATEDAPI_H_SEN_1_0_0__