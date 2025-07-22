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
#define ATTO_PREFIX SEN_1_0_0_
#endif

#define ATTO_PREFIX_CONCAT(x,y) x ## y
#define ATTO_PREFIX_EVALUATOR(x,y) ATTO_PREFIX_CONCAT(x,y)
#define ATTO_FUNCTION(function_name) ATTO_PREFIX_EVALUATOR(ATTO_PREFIX, function_name)

#include <stdbool.h>
#include "attocubeJSONCall.h"
#ifdef __cplusplus
extern "C" {
#endif

/** @brief @system_about_getInstalledPackages
*  Get list of packages installed on the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_string     string: comma separated list of packages
*  @param size             Maximum size of buffer value_string
*
*  @return string: comma separated list of packages
*/
int ATTOCUBE_API system_about_getInstalledPackages_SEN_1_0_0(int deviceHandle, char* value_string, int size);

static inline int ATTO_FUNCTION(system_about_getInstalledPackages)(int deviceHandle, char* value_string, int size) {
    return system_about_getInstalledPackages_SEN_1_0_0(deviceHandle, value_string, size);
}


/** @brief @system_about_getPackageLicense
*  Get the license for a specific package.
*
*  @param deviceHandle     Handle of device
*  @param pckg             string: Package name
*
*  @param value_string     string: license for this package
*  @param size             Maximum size of buffer value_string
*
*  @return string: license for this package
*/
int ATTOCUBE_API system_about_getPackageLicense_SEN_1_0_0(int deviceHandle, const char* pckg, char* value_string, int size);

static inline int ATTO_FUNCTION(system_about_getPackageLicense)(int deviceHandle, const char* pckg, char* value_string, int size) {
    return system_about_getPackageLicense_SEN_1_0_0(deviceHandle, pckg, value_string, size);
}


/** @brief @system_update_getSwUpdateProgress
*  Gets the progress of running update.
*
*  @param deviceHandle     Handle of device
*
*  @param value_progress   progress value in %
*
*  @return progress value in %
*/
int ATTOCUBE_API system_update_getSwUpdateProgress_SEN_1_0_0(int deviceHandle, int* value_progress);

static inline int ATTO_FUNCTION(system_update_getSwUpdateProgress)(int deviceHandle, int* value_progress) {
    return system_update_getSwUpdateProgress_SEN_1_0_0(deviceHandle, value_progress);
}


/** @brief @system_update_getLicenseUpdateProgress
*  Gets the progress of running license update.
*
*  @param deviceHandle     Handle of device
*
*  @param value_progress   progress value in %
*
*  @return progress value in %
*/
int ATTOCUBE_API system_update_getLicenseUpdateProgress_SEN_1_0_0(int deviceHandle, int* value_progress);

static inline int ATTO_FUNCTION(system_update_getLicenseUpdateProgress)(int deviceHandle, int* value_progress) {
    return system_update_getLicenseUpdateProgress_SEN_1_0_0(deviceHandle, value_progress);
}


/** @brief @system_update_softwareUpdateBase64
*  Executes the update with base 64 file uploaded.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_softwareUpdateBase64_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_update_softwareUpdateBase64)(int deviceHandle) {
    return system_update_softwareUpdateBase64_SEN_1_0_0(deviceHandle);
}


/** @brief @system_update_uploadSoftwareImageBase64
*  Uploads new firmware image in format base 64.
*
*  @param deviceHandle     Handle of device
*  @param offset           offset of the data
*  @param b64Data          base64 data string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_uploadSoftwareImageBase64_SEN_1_0_0(int deviceHandle, int offset, const char* b64Data);

static inline int ATTO_FUNCTION(system_update_uploadSoftwareImageBase64)(int deviceHandle, int offset, const char* b64Data) {
    return system_update_uploadSoftwareImageBase64_SEN_1_0_0(deviceHandle, offset, b64Data);
}


/** @brief @system_update_uploadLicenseBase64
*  Uploads new license file in format base 64.
*
*  @param deviceHandle     Handle of device
*  @param offset           offset of the data
*  @param b64Data          base64 data string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_uploadLicenseBase64_SEN_1_0_0(int deviceHandle, int offset, const char* b64Data);

static inline int ATTO_FUNCTION(system_update_uploadLicenseBase64)(int deviceHandle, int offset, const char* b64Data) {
    return system_update_uploadLicenseBase64_SEN_1_0_0(deviceHandle, offset, b64Data);
}


/** @brief @system_update_licenseUpdateBase64
*  Executes the license update with base64 file uploaded.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_update_licenseUpdateBase64_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_update_licenseUpdateBase64)(int deviceHandle) {
    return system_update_licenseUpdateBase64_SEN_1_0_0(deviceHandle);
}


/** @brief @system_network_getRealIpAddress
*  Gets the real IP address of the device set to the network interface (br0, eth1 or eth0).
*
*  @param deviceHandle     Handle of device
*
*  @param value_IP         IP IP address
*  @param size             Maximum size of buffer value_IP
*
*  @return IP IP address
*/
int ATTOCUBE_API system_network_getRealIpAddress_SEN_1_0_0(int deviceHandle, char* value_IP, int size);

static inline int ATTO_FUNCTION(system_network_getRealIpAddress)(int deviceHandle, char* value_IP, int size) {
    return system_network_getRealIpAddress_SEN_1_0_0(deviceHandle, value_IP, size);
}


/** @brief @system_network_getIpAddress
*  Gets the IP address of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_IP         IP address as string
*  @param size             Maximum size of buffer value_IP
*
*  @return IP address as string
*/
int ATTOCUBE_API system_network_getIpAddress_SEN_1_0_0(int deviceHandle, char* value_IP, int size);

static inline int ATTO_FUNCTION(system_network_getIpAddress)(int deviceHandle, char* value_IP, int size) {
    return system_network_getIpAddress_SEN_1_0_0(deviceHandle, value_IP, size);
}


/** @brief @system_network_setIpAddress
*  Sets the IP address of the device.
*
*  @param deviceHandle     Handle of device
*  @param address          IP address as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setIpAddress_SEN_1_0_0(int deviceHandle, const char* address);

static inline int ATTO_FUNCTION(system_network_setIpAddress)(int deviceHandle, const char* address) {
    return system_network_setIpAddress_SEN_1_0_0(deviceHandle, address);
}


/** @brief @system_network_getSubnetMask
*  Gets the subnet mask of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_Subnet     Subnet mask as string
*  @param size             Maximum size of buffer value_Subnet
*
*  @return Subnet mask as string
*/
int ATTOCUBE_API system_network_getSubnetMask_SEN_1_0_0(int deviceHandle, char* value_Subnet, int size);

static inline int ATTO_FUNCTION(system_network_getSubnetMask)(int deviceHandle, char* value_Subnet, int size) {
    return system_network_getSubnetMask_SEN_1_0_0(deviceHandle, value_Subnet, size);
}


/** @brief @system_network_setSubnetMask
*  Sets the subnet mask of the device.
*
*  @param deviceHandle     Handle of device
*  @param netmask          subnet mask as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setSubnetMask_SEN_1_0_0(int deviceHandle, const char* netmask);

static inline int ATTO_FUNCTION(system_network_setSubnetMask)(int deviceHandle, const char* netmask) {
    return system_network_setSubnetMask_SEN_1_0_0(deviceHandle, netmask);
}


/** @brief @system_network_getDefaultGateway
*  Gets the default gateway of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_Default    Default gateway
*  @param size             Maximum size of buffer value_Default
*
*  @return Default gateway
*/
int ATTOCUBE_API system_network_getDefaultGateway_SEN_1_0_0(int deviceHandle, char* value_Default, int size);

static inline int ATTO_FUNCTION(system_network_getDefaultGateway)(int deviceHandle, char* value_Default, int size) {
    return system_network_getDefaultGateway_SEN_1_0_0(deviceHandle, value_Default, size);
}


/** @brief @system_network_setDefaultGateway
*  Sets the default gateway of the device.
*
*  @param deviceHandle     Handle of device
*  @param gateway          Default gateway as string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setDefaultGateway_SEN_1_0_0(int deviceHandle, const char* gateway);

static inline int ATTO_FUNCTION(system_network_setDefaultGateway)(int deviceHandle, const char* gateway) {
    return system_network_setDefaultGateway_SEN_1_0_0(deviceHandle, gateway);
}


/** @brief @system_network_getDnsResolver
*  Gets the DNS resolver.
*
*  @param deviceHandle     Handle of device
*  @param priority         priority of DNS resolver (0 = default, 1 = backup)
*
*  @param value_resolver   resolver IP address of DNS resolver
*  @param size             Maximum size of buffer value_resolver
*
*  @return resolver IP address of DNS resolver
*/
int ATTOCUBE_API system_network_getDnsResolver_SEN_1_0_0(int deviceHandle, int priority, char* value_resolver, int size);

static inline int ATTO_FUNCTION(system_network_getDnsResolver)(int deviceHandle, int priority, char* value_resolver, int size) {
    return system_network_getDnsResolver_SEN_1_0_0(deviceHandle, priority, value_resolver, size);
}


/** @brief @system_network_setDnsResolver
*  Sets the DNS resolver.
*
*  @param deviceHandle     Handle of device
*  @param priority         priority of DNS resolver (0 = default, 1 = backup)
*  @param resolver         IP address of DNS resolver
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setDnsResolver_SEN_1_0_0(int deviceHandle, int priority, const char* resolver);

static inline int ATTO_FUNCTION(system_network_setDnsResolver)(int deviceHandle, int priority, const char* resolver) {
    return system_network_setDnsResolver_SEN_1_0_0(deviceHandle, priority, resolver);
}


/** @brief @system_network_getProxyServer
*  Gets the proxy settings of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_proxyServer proxyServer proxy server setting, empty for no proxy
*  @param size             Maximum size of buffer value_proxyServer
*
*  @return proxyServer proxy server setting, empty for no proxy
*/
int ATTOCUBE_API system_network_getProxyServer_SEN_1_0_0(int deviceHandle, char* value_proxyServer, int size);

static inline int ATTO_FUNCTION(system_network_getProxyServer)(int deviceHandle, char* value_proxyServer, int size) {
    return system_network_getProxyServer_SEN_1_0_0(deviceHandle, value_proxyServer, size);
}


/** @brief @system_network_setProxyServer
*  Sets the proxy server of the device.
*
*  @param deviceHandle     Handle of device
*  @param proxyServer      proxy server setting
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setProxyServer_SEN_1_0_0(int deviceHandle, const char* proxyServer);

static inline int ATTO_FUNCTION(system_network_setProxyServer)(int deviceHandle, const char* proxyServer) {
    return system_network_setProxyServer_SEN_1_0_0(deviceHandle, proxyServer);
}


/** @brief @system_network_getEnableDhcpServer
*  Gets the status of DHCP server.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled, false = disabled
*
*  @return enabled true = enabled, false = disabled
*/
int ATTOCUBE_API system_network_getEnableDhcpServer_SEN_1_0_0(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(system_network_getEnableDhcpServer)(int deviceHandle, bool* value_enabled) {
    return system_network_getEnableDhcpServer_SEN_1_0_0(deviceHandle, value_enabled);
}


/** @brief @system_network_setEnableDhcpServer
*  Enables or disables DHCP server.
*
*  @param deviceHandle     Handle of device
*  @param enable           true = enable, false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setEnableDhcpServer_SEN_1_0_0(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(system_network_setEnableDhcpServer)(int deviceHandle, bool enable) {
    return system_network_setEnableDhcpServer_SEN_1_0_0(deviceHandle, enable);
}


/** @brief @system_network_getEnableDhcpClient
*  Gets the status of DHCP client.
*
*  @param deviceHandle     Handle of device
*
*  @param value_enabled    enabled true = enabled, false = disabled
*
*  @return enabled true = enabled, false = disabled
*/
int ATTOCUBE_API system_network_getEnableDhcpClient_SEN_1_0_0(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(system_network_getEnableDhcpClient)(int deviceHandle, bool* value_enabled) {
    return system_network_getEnableDhcpClient_SEN_1_0_0(deviceHandle, value_enabled);
}


/** @brief @system_network_setEnableDhcpClient
*  Enables or disables DHCP client.
*
*  @param deviceHandle     Handle of device
*  @param enable           true = enable, false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setEnableDhcpClient_SEN_1_0_0(int deviceHandle, bool enable);

static inline int ATTO_FUNCTION(system_network_setEnableDhcpClient)(int deviceHandle, bool enable) {
    return system_network_setEnableDhcpClient_SEN_1_0_0(deviceHandle, enable);
}


/** @brief @system_network_apply
*  Applies the temporary IP configuration and loads it.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_apply_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_apply)(int deviceHandle) {
    return system_network_apply_SEN_1_0_0(deviceHandle);
}


/** @brief @system_network_verify
*  Verifies if the temporary IP configuration is correct.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_verify_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_verify)(int deviceHandle) {
    return system_network_verify_SEN_1_0_0(deviceHandle);
}


/** @brief @system_network_discard
*  Discards the temporary IP configuration.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_discard_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_network_discard)(int deviceHandle) {
    return system_network_discard_SEN_1_0_0(deviceHandle);
}


/** @brief @system_network_getWifiPresent
*  Checks if a WiFi interface is present.
*
*  @param deviceHandle     Handle of device
*
*  @param value_present    present true if the interface is present, else false
*
*  @return present true if the interface is present, else false
*/
int ATTOCUBE_API system_network_getWifiPresent_SEN_1_0_0(int deviceHandle, bool* value_present);

static inline int ATTO_FUNCTION(system_network_getWifiPresent)(int deviceHandle, bool* value_present) {
    return system_network_getWifiPresent_SEN_1_0_0(deviceHandle, value_present);
}


/** @brief @system_network_setWifiMode
*  Changes the operation mode of the WiFi adapter.
*
*  @param deviceHandle     Handle of device
*  @param mode             0 = access point; 1 = WiFi client
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiMode_SEN_1_0_0(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(system_network_setWifiMode)(int deviceHandle, int mode) {
    return system_network_setWifiMode_SEN_1_0_0(deviceHandle, mode);
}


/** @brief @system_network_getWifiMode
*  Gets the operation mode of the WiFi adapter.
*
*  @param deviceHandle     Handle of device
*
*  @param value_mode       mode 0 = access point; 1 = WiFi client
*
*  @return mode 0 = access point; 1 = WiFi client
*/
int ATTOCUBE_API system_network_getWifiMode_SEN_1_0_0(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(system_network_getWifiMode)(int deviceHandle, int* value_mode) {
    return system_network_getWifiMode_SEN_1_0_0(deviceHandle, value_mode);
}


/** @brief @system_network_setWifiSSID
*  Changes the SSID of the network hosted (mode: access point) or connected to (mode: client).
*
*  @param deviceHandle     Handle of device
*  @param SSID             SSID string
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiSSID_SEN_1_0_0(int deviceHandle, const char* SSID);

static inline int ATTO_FUNCTION(system_network_setWifiSSID)(int deviceHandle, const char* SSID) {
    return system_network_setWifiSSID_SEN_1_0_0(deviceHandle, SSID);
}


/** @brief @system_network_getWifiSSID
*  Gets the SSID of the network hosted (mode: access point) or connected to (mode: client).
*
*  @param deviceHandle     Handle of device
*
*  @param value_SSID       SSID SSID string
*  @param size             Maximum size of buffer value_SSID
*
*  @return SSID SSID string
*/
int ATTOCUBE_API system_network_getWifiSSID_SEN_1_0_0(int deviceHandle, char* value_SSID, int size);

static inline int ATTO_FUNCTION(system_network_getWifiSSID)(int deviceHandle, char* value_SSID, int size) {
    return system_network_getWifiSSID_SEN_1_0_0(deviceHandle, value_SSID, size);
}


/** @brief @system_network_setWifiPassphrase
*  Changes the passphrase of the network hosted (mode: access point) or connected to (mode: client).
*
*  @param deviceHandle     Handle of device
*  @param psk              pre-shared key
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_setWifiPassphrase_SEN_1_0_0(int deviceHandle, const char* psk);

static inline int ATTO_FUNCTION(system_network_setWifiPassphrase)(int deviceHandle, const char* psk) {
    return system_network_setWifiPassphrase_SEN_1_0_0(deviceHandle, psk);
}


/** @brief @system_network_getWifiPassphrase
*  Gets the passphrase of the network hosted (mode: Access point) or connected to (mode: client).
*
*  @param deviceHandle     Handle of device
*
*  @param value_psk        psk pre-shared key
*  @param size             Maximum size of buffer value_psk
*
*  @return psk pre-shared key
*/
int ATTOCUBE_API system_network_getWifiPassphrase_SEN_1_0_0(int deviceHandle, char* value_psk, int size);

static inline int ATTO_FUNCTION(system_network_getWifiPassphrase)(int deviceHandle, char* value_psk, int size) {
    return system_network_getWifiPassphrase_SEN_1_0_0(deviceHandle, value_psk, size);
}


/** @brief @system_network_configureWifi
*  Changes the WiFi configuration and applies it.
*
*  @param deviceHandle     Handle of device
*  @param mode             0 = access point; 1: WiFi client
*  @param SSID             SSID string
*  @param psk              pre-shared key
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_network_configureWifi_SEN_1_0_0(int deviceHandle, int mode, const char* SSID, const char* psk);

static inline int ATTO_FUNCTION(system_network_configureWifi)(int deviceHandle, int mode, const char* SSID, const char* psk) {
    return system_network_configureWifi_SEN_1_0_0(deviceHandle, mode, SSID, psk);
}


/** @brief @system_setDeviceName
*  Sets custom name for the device.
*
*  @param deviceHandle     Handle of device
*  @param name             device name
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_setDeviceName_SEN_1_0_0(int deviceHandle, const char* name);

static inline int ATTO_FUNCTION(system_setDeviceName)(int deviceHandle, const char* name) {
    return system_setDeviceName_SEN_1_0_0(deviceHandle, name);
}


/** @brief @system_getDeviceName
*  Gets the current device name.
*
*  @param deviceHandle     Handle of device
*
*  @param value_name       name current device name
*  @param size             Maximum size of buffer value_name
*
*  @return name current device name
*/
int ATTOCUBE_API system_getDeviceName_SEN_1_0_0(int deviceHandle, char* value_name, int size);

static inline int ATTO_FUNCTION(system_getDeviceName)(int deviceHandle, char* value_name, int size) {
    return system_getDeviceName_SEN_1_0_0(deviceHandle, value_name, size);
}


/** @brief @system_rebootSystem
*  Reboots the device.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_rebootSystem_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_rebootSystem)(int deviceHandle) {
    return system_rebootSystem_SEN_1_0_0(deviceHandle);
}


/** @brief @system_factoryReset
*  Turns on the factory reset flag.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_factoryReset_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_factoryReset)(int deviceHandle) {
    return system_factoryReset_SEN_1_0_0(deviceHandle);
}


/** @brief @system_softReset
*  Performs a soft reset (factory reset without deleting the network settings).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_softReset_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_softReset)(int deviceHandle) {
    return system_softReset_SEN_1_0_0(deviceHandle);
}


/** @brief @system_errorNumberToString
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
int ATTOCUBE_API system_errorNumberToString_SEN_1_0_0(int deviceHandle, int language, int errNbr, char* value_message, int size);

static inline int ATTO_FUNCTION(system_errorNumberToString)(int deviceHandle, int language, int errNbr, char* value_message, int size) {
    return system_errorNumberToString_SEN_1_0_0(deviceHandle, language, errNbr, value_message, size);
}


/** @brief @system_errorNumberToRecommendation
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
int ATTOCUBE_API system_errorNumberToRecommendation_SEN_1_0_0(int deviceHandle, int language, int errNbr, char* value_string, int size);

static inline int ATTO_FUNCTION(system_errorNumberToRecommendation)(int deviceHandle, int language, int errNbr, char* value_string, int size) {
    return system_errorNumberToRecommendation_SEN_1_0_0(deviceHandle, language, errNbr, value_string, size);
}


/** @brief @system_getFirmwareVersion
*  Gets the firmware version of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_FWversion  FWversion firmware version
*  @param size             Maximum size of buffer value_FWversion
*
*  @return FWversion firmware version
*/
int ATTOCUBE_API system_getFirmwareVersion_SEN_1_0_0(int deviceHandle, char* value_FWversion, int size);

static inline int ATTO_FUNCTION(system_getFirmwareVersion)(int deviceHandle, char* value_FWversion, int size) {
    return system_getFirmwareVersion_SEN_1_0_0(deviceHandle, value_FWversion, size);
}


/** @brief @system_getHostname
*  Returns the device hostname.
*
*  @param deviceHandle     Handle of device
*
*  @param value_name       name hostname
*  @param size             Maximum size of buffer value_name
*
*  @return name hostname
*/
int ATTOCUBE_API system_getHostname_SEN_1_0_0(int deviceHandle, char* value_name, int size);

static inline int ATTO_FUNCTION(system_getHostname)(int deviceHandle, char* value_name, int size) {
    return system_getHostname_SEN_1_0_0(deviceHandle, value_name, size);
}


/** @brief @system_getMacAddress
*  Gets the mac address of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_mac        mac mac address
*  @param size             Maximum size of buffer value_mac
*
*  @return mac mac address
*/
int ATTOCUBE_API system_getMacAddress_SEN_1_0_0(int deviceHandle, char* value_mac, int size);

static inline int ATTO_FUNCTION(system_getMacAddress)(int deviceHandle, char* value_mac, int size) {
    return system_getMacAddress_SEN_1_0_0(deviceHandle, value_mac, size);
}


/** @brief @system_getSerialNumber
*  Gets the serial number of the device.
*
*  @param deviceHandle     Handle of device
*
*  @param value_SN         SN serial number
*  @param size             Maximum size of buffer value_SN
*
*  @return SN serial number
*/
int ATTOCUBE_API system_getSerialNumber_SEN_1_0_0(int deviceHandle, char* value_SN, int size);

static inline int ATTO_FUNCTION(system_getSerialNumber)(int deviceHandle, char* value_SN, int size) {
    return system_getSerialNumber_SEN_1_0_0(deviceHandle, value_SN, size);
}


/** @brief @system_getFluxCode
*  Gets the flux code of the system.
*
*  @param deviceHandle     Handle of device
*
*  @param value_code       code flux code
*  @param size             Maximum size of buffer value_code
*
*  @return code flux code
*/
int ATTOCUBE_API system_getFluxCode_SEN_1_0_0(int deviceHandle, char* value_code, int size);

static inline int ATTO_FUNCTION(system_getFluxCode)(int deviceHandle, char* value_code, int size) {
    return system_getFluxCode_SEN_1_0_0(deviceHandle, value_code, size);
}


/** @brief @system_updateTimeFromInternet
*  Updates system time by querying attocube.com.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API system_updateTimeFromInternet_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(system_updateTimeFromInternet)(int deviceHandle) {
    return system_updateTimeFromInternet_SEN_1_0_0(deviceHandle);
}


/** @brief @system_setTime
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
int ATTOCUBE_API system_setTime_SEN_1_0_0(int deviceHandle, int day, int month, int year, int hour, int minute, int second);

static inline int ATTO_FUNCTION(system_setTime)(int deviceHandle, int day, int month, int year, int hour, int minute, int second) {
    return system_setTime_SEN_1_0_0(deviceHandle, day, month, year, hour, minute, second);
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
int ATTOCUBE_API SEN_adjustment_getContrastInPermille_SEN_1_0_0(int deviceHandle, int axis, int* value_warningNo, int* value_contrast, int* value_baseline, int* value_mixcontrast);

static inline int ATTO_FUNCTION(SEN_adjustment_getContrastInPermille)(int deviceHandle, int axis, int* value_warningNo, int* value_contrast, int* value_baseline, int* value_mixcontrast) {
    return SEN_adjustment_getContrastInPermille_SEN_1_0_0(deviceHandle, axis, value_warningNo, value_contrast, value_baseline, value_mixcontrast);
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
int ATTOCUBE_API SEN_adjustment_getAdjustmentEnabled_SEN_1_0_0(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(SEN_adjustment_getAdjustmentEnabled)(int deviceHandle, bool* value_enabled) {
    return SEN_adjustment_getAdjustmentEnabled_SEN_1_0_0(deviceHandle, value_enabled);
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
int ATTOCUBE_API SEN_axis_getPassMode_SEN_1_0_0(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(SEN_axis_getPassMode)(int deviceHandle, int* value_mode) {
    return SEN_axis_getPassMode_SEN_1_0_0(deviceHandle, value_mode);
}


/** @brief @SEN_axis_setPassMode
*  Sets the desired pass mode.
*
*  @param deviceHandle     Handle of device
*  @param mode             0 = single pass; 1 = dual pass
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_axis_setPassMode_SEN_1_0_0(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(SEN_axis_setPassMode)(int deviceHandle, int mode) {
    return SEN_axis_setPassMode_SEN_1_0_0(deviceHandle, mode);
}


/** @brief @SEN_axis_getMasterAxis
*  Returns the master axis (for more information, please refer to the device user manual).
*
*  @param deviceHandle     Handle of device
*
*  @param value_axis       axis [0|1|2]
*
*  @return axis [0|1|2]
*/
int ATTOCUBE_API SEN_axis_getMasterAxis_SEN_1_0_0(int deviceHandle, int* value_axis);

static inline int ATTO_FUNCTION(SEN_axis_getMasterAxis)(int deviceHandle, int* value_axis) {
    return SEN_axis_getMasterAxis_SEN_1_0_0(deviceHandle, value_axis);
}


/** @brief @SEN_axis_setMasterAxis
*  Sets the master axis (for more information, please refer to the device user manual).
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_axis_setMasterAxis_SEN_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(SEN_axis_setMasterAxis)(int deviceHandle, int axis) {
    return SEN_axis_setMasterAxis_SEN_1_0_0(deviceHandle, axis);
}


/** @brief @SEN_axis_apply
*  Applies new axis settings.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_axis_apply_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_axis_apply)(int deviceHandle) {
    return SEN_axis_apply_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_axis_setAutoMasterAxis
*  Enables the automatic configuration of the master axis during measurement initialization.
*
*  @param deviceHandle     Handle of device
*  @param automatic        true = automatic; false = manual
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_axis_setAutoMasterAxis_SEN_1_0_0(int deviceHandle, bool automatic);

static inline int ATTO_FUNCTION(SEN_axis_setAutoMasterAxis)(int deviceHandle, bool automatic) {
    return SEN_axis_setAutoMasterAxis_SEN_1_0_0(deviceHandle, automatic);
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
int ATTOCUBE_API SEN_axis_getAutoMasterAxis_SEN_1_0_0(int deviceHandle, bool* value_automatic);

static inline int ATTO_FUNCTION(SEN_axis_getAutoMasterAxis)(int deviceHandle, bool* value_automatic) {
    return SEN_axis_getAutoMasterAxis_SEN_1_0_0(deviceHandle, value_automatic);
}


/** @brief @SEN_axis_discard
*  Discards new axis settings.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_axis_discard_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_axis_discard)(int deviceHandle) {
    return SEN_axis_discard_SEN_1_0_0(deviceHandle);
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
int ATTOCUBE_API SEN_displacement_getMeasurementEnabled_SEN_1_0_0(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(SEN_displacement_getMeasurementEnabled)(int deviceHandle, bool* value_enabled) {
    return SEN_displacement_getMeasurementEnabled_SEN_1_0_0(deviceHandle, value_enabled);
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
int ATTOCUBE_API SEN_displacement_getAverageN_SEN_1_0_0(int deviceHandle, int* value_averageN);

static inline int ATTO_FUNCTION(SEN_displacement_getAverageN)(int deviceHandle, int* value_averageN) {
    return SEN_displacement_getAverageN_SEN_1_0_0(deviceHandle, value_averageN);
}


/** @brief @SEN_displacement_setAverageN
*  Sets the averaging (lowpass) parameter N.
*
*  @param deviceHandle     Handle of device
*  @param averageN         value from 0 to 24
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_displacement_setAverageN_SEN_1_0_0(int deviceHandle, int averageN);

static inline int ATTO_FUNCTION(SEN_displacement_setAverageN)(int deviceHandle, int averageN) {
    return SEN_displacement_setAverageN_SEN_1_0_0(deviceHandle, averageN);
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
int ATTOCUBE_API SEN_displacement_getAxisSignalQuality_SEN_1_0_0(int deviceHandle, int axis, int* value_warningNo, int* value_contrast, int* value_baseline);

static inline int ATTO_FUNCTION(SEN_displacement_getAxisSignalQuality)(int deviceHandle, int axis, int* value_warningNo, int* value_contrast, int* value_baseline) {
    return SEN_displacement_getAxisSignalQuality_SEN_1_0_0(deviceHandle, axis, value_warningNo, value_contrast, value_baseline);
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
int ATTOCUBE_API SEN_displacement_getReferencePosition_SEN_1_0_0(int deviceHandle, int axis, int* value_warningNo, double* value_position);

static inline int ATTO_FUNCTION(SEN_displacement_getReferencePosition)(int deviceHandle, int axis, int* value_warningNo, double* value_position) {
    return SEN_displacement_getReferencePosition_SEN_1_0_0(deviceHandle, axis, value_warningNo, value_position);
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
int ATTOCUBE_API SEN_displacement_getReferencePositions_SEN_1_0_0(int deviceHandle, int* value_warningNo, double* value_position1, double* value_position2, double* value_position3);

static inline int ATTO_FUNCTION(SEN_displacement_getReferencePositions)(int deviceHandle, int* value_warningNo, double* value_position1, double* value_position2, double* value_position3) {
    return SEN_displacement_getReferencePositions_SEN_1_0_0(deviceHandle, value_warningNo, value_position1, value_position2, value_position3);
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
int ATTOCUBE_API SEN_displacement_getAbsolutePosition_SEN_1_0_0(int deviceHandle, int axis, int* value_warningNo, double* value_position);

static inline int ATTO_FUNCTION(SEN_displacement_getAbsolutePosition)(int deviceHandle, int axis, int* value_warningNo, double* value_position) {
    return SEN_displacement_getAbsolutePosition_SEN_1_0_0(deviceHandle, axis, value_warningNo, value_position);
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
int ATTOCUBE_API SEN_displacement_getAbsolutePositions_SEN_1_0_0(int deviceHandle, int* value_warningNo, double* value_position1, double* value_position2, double* value_position3);

static inline int ATTO_FUNCTION(SEN_displacement_getAbsolutePositions)(int deviceHandle, int* value_warningNo, double* value_position1, double* value_position2, double* value_position3) {
    return SEN_displacement_getAbsolutePositions_SEN_1_0_0(deviceHandle, value_warningNo, value_position1, value_position2, value_position3);
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
int ATTOCUBE_API SEN_displacement_getAxisDisplacement_SEN_1_0_0(int deviceHandle, int axis, int* value_warningNo, double* value_displacement);

static inline int ATTO_FUNCTION(SEN_displacement_getAxisDisplacement)(int deviceHandle, int axis, int* value_warningNo, double* value_displacement) {
    return SEN_displacement_getAxisDisplacement_SEN_1_0_0(deviceHandle, axis, value_warningNo, value_displacement);
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
int ATTOCUBE_API SEN_displacement_getAxesDisplacement_SEN_1_0_0(int deviceHandle, int* value_warningNo, double* value_displacement1, double* value_displacement2, double* value_displacement3);

static inline int ATTO_FUNCTION(SEN_displacement_getAxesDisplacement)(int deviceHandle, int* value_warningNo, double* value_displacement1, double* value_displacement2, double* value_displacement3) {
    return SEN_displacement_getAxesDisplacement_SEN_1_0_0(deviceHandle, value_warningNo, value_displacement1, value_displacement2, value_displacement3);
}


/** @brief @SEN_pilotlaser_enable
*  Enables the pilot laser.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_pilotlaser_enable_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_pilotlaser_enable)(int deviceHandle) {
    return SEN_pilotlaser_enable_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_pilotlaser_disable
*  Disables the pilot laser.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_pilotlaser_disable_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_pilotlaser_disable)(int deviceHandle) {
    return SEN_pilotlaser_disable_SEN_1_0_0(deviceHandle);
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
int ATTOCUBE_API SEN_pilotlaser_getEnabled_SEN_1_0_0(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(SEN_pilotlaser_getEnabled)(int deviceHandle, bool* value_enabled) {
    return SEN_pilotlaser_getEnabled_SEN_1_0_0(deviceHandle, value_enabled);
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
int ATTOCUBE_API SEN_realtime_getRtOutMode_SEN_1_0_0(int deviceHandle, int* value_rtOutMode);

static inline int ATTO_FUNCTION(SEN_realtime_getRtOutMode)(int deviceHandle, int* value_rtOutMode) {
    return SEN_realtime_getRtOutMode_SEN_1_0_0(deviceHandle, value_rtOutMode);
}


/** @brief @SEN_realtime_setRtOutMode
*  Sets the real-time output mode.
*
*  @param deviceHandle     Handle of device
*  @param rtOutMode        0 = HSSL (LVTTL), 1 = HSSL (LVDS), 2 = AquadB (LVTTL),/n3 = AquadB (LVDS), 4 = Sin/Cos (LVTTL error signal),/n5 = Sin/Cos (LVDS error signal), 6 = Linear (LVTTL error signal), 7 = Linear (LVDS error signal),/n8 = BiSS-C, 9 = Deactivated
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setRtOutMode_SEN_1_0_0(int deviceHandle, int rtOutMode);

static inline int ATTO_FUNCTION(SEN_realtime_setRtOutMode)(int deviceHandle, int rtOutMode) {
    return SEN_realtime_setRtOutMode_SEN_1_0_0(deviceHandle, rtOutMode);
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
int ATTOCUBE_API SEN_realtime_getRtDistanceMode_SEN_1_0_0(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(SEN_realtime_getRtDistanceMode)(int deviceHandle, int* value_mode) {
    return SEN_realtime_getRtDistanceMode_SEN_1_0_0(deviceHandle, value_mode);
}


/** @brief @SEN_realtime_setRtDistanceMode
*  Sets the distance mode.
*
*  @param deviceHandle     Handle of device
*  @param mode             1 = Displacement (all modes)/n2 = Absolute Distance (HSSL mode and BiSS C mode)/n3 = Vibrometry (Linear mode only)
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setRtDistanceMode_SEN_1_0_0(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(SEN_realtime_setRtDistanceMode)(int deviceHandle, int mode) {
    return SEN_realtime_setRtDistanceMode_SEN_1_0_0(deviceHandle, mode);
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
int ATTOCUBE_API SEN_realtime_getResolutionBissC_SEN_1_0_0(int deviceHandle, int* value_resolution);

static inline int ATTO_FUNCTION(SEN_realtime_getResolutionBissC)(int deviceHandle, int* value_resolution) {
    return SEN_realtime_getResolutionBissC_SEN_1_0_0(deviceHandle, value_resolution);
}


/** @brief @SEN_realtime_setResolutionBissC
*  Sets the BiSS C resolution.
*
*  @param deviceHandle     Handle of device
*  @param resolution       value from 0 to 16
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setResolutionBissC_SEN_1_0_0(int deviceHandle, int resolution);

static inline int ATTO_FUNCTION(SEN_realtime_setResolutionBissC)(int deviceHandle, int resolution) {
    return SEN_realtime_setResolutionBissC_SEN_1_0_0(deviceHandle, resolution);
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
int ATTOCUBE_API SEN_realtime_getResolutionHsslLow_SEN_1_0_0(int deviceHandle, int* value_resolution);

static inline int ATTO_FUNCTION(SEN_realtime_getResolutionHsslLow)(int deviceHandle, int* value_resolution) {
    return SEN_realtime_getResolutionHsslLow_SEN_1_0_0(deviceHandle, value_resolution);
}


/** @brief @SEN_realtime_setResolutionHsslLow
*  Sets the HSSL resolution low bit.
*
*  @param deviceHandle     Handle of device
*  @param resolution       value from 0 to 46
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setResolutionHsslLow_SEN_1_0_0(int deviceHandle, int resolution);

static inline int ATTO_FUNCTION(SEN_realtime_setResolutionHsslLow)(int deviceHandle, int resolution) {
    return SEN_realtime_setResolutionHsslLow_SEN_1_0_0(deviceHandle, resolution);
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
int ATTOCUBE_API SEN_realtime_getResolutionHsslHigh_SEN_1_0_0(int deviceHandle, int* value_resolution);

static inline int ATTO_FUNCTION(SEN_realtime_getResolutionHsslHigh)(int deviceHandle, int* value_resolution) {
    return SEN_realtime_getResolutionHsslHigh_SEN_1_0_0(deviceHandle, value_resolution);
}


/** @brief @SEN_realtime_setResolutionHsslHigh
*  Sets the HSSL resolution high bit.
*
*  @param deviceHandle     Handle of device
*  @param resolution       value from 1 to 47
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setResolutionHsslHigh_SEN_1_0_0(int deviceHandle, int resolution);

static inline int ATTO_FUNCTION(SEN_realtime_setResolutionHsslHigh)(int deviceHandle, int resolution) {
    return SEN_realtime_setResolutionHsslHigh_SEN_1_0_0(deviceHandle, resolution);
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
int ATTOCUBE_API SEN_realtime_getLinearRange_SEN_1_0_0(int deviceHandle, int* value_rangenumber);

static inline int ATTO_FUNCTION(SEN_realtime_getLinearRange)(int deviceHandle, int* value_rangenumber) {
    return SEN_realtime_getLinearRange_SEN_1_0_0(deviceHandle, value_rangenumber);
}


/** @brief @SEN_realtime_setLinearRange
*  Sets the range number of Linear analog output mode.
*
*  @param deviceHandle     Handle of device
*  @param rangenumber      value from 0 to 34
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setLinearRange_SEN_1_0_0(int deviceHandle, int rangenumber);

static inline int ATTO_FUNCTION(SEN_realtime_setLinearRange)(int deviceHandle, int rangenumber) {
    return SEN_realtime_setLinearRange_SEN_1_0_0(deviceHandle, rangenumber);
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
int ATTOCUBE_API SEN_realtime_getPeriodHsslClk_SEN_1_0_0(int deviceHandle, int* value_period);

static inline int ATTO_FUNCTION(SEN_realtime_getPeriodHsslClk)(int deviceHandle, int* value_period) {
    return SEN_realtime_getPeriodHsslClk_SEN_1_0_0(deviceHandle, value_period);
}


/** @brief @SEN_realtime_setPeriodHsslClk
*  Set the HSSL period clock.
*
*  @param deviceHandle     Handle of device
*  @param period           value from 40 ns to 10200 ns
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setPeriodHsslClk_SEN_1_0_0(int deviceHandle, int period);

static inline int ATTO_FUNCTION(SEN_realtime_setPeriodHsslClk)(int deviceHandle, int period) {
    return SEN_realtime_setPeriodHsslClk_SEN_1_0_0(deviceHandle, period);
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
int ATTOCUBE_API SEN_realtime_getPeriodHsslGap_SEN_1_0_0(int deviceHandle, int* value_gap);

static inline int ATTO_FUNCTION(SEN_realtime_getPeriodHsslGap)(int deviceHandle, int* value_gap) {
    return SEN_realtime_getPeriodHsslGap_SEN_1_0_0(deviceHandle, value_gap);
}


/** @brief @SEN_realtime_setPeriodHsslGap
*  Set the HSSL period gap as number of clocks.
*
*  @param deviceHandle     Handle of device
*  @param gap              value from 1 to 255
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setPeriodHsslGap_SEN_1_0_0(int deviceHandle, int gap);

static inline int ATTO_FUNCTION(SEN_realtime_setPeriodHsslGap)(int deviceHandle, int gap) {
    return SEN_realtime_setPeriodHsslGap_SEN_1_0_0(deviceHandle, gap);
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
int ATTOCUBE_API SEN_realtime_getPeriodSinCosClk_SEN_1_0_0(int deviceHandle, int* value_period);

static inline int ATTO_FUNCTION(SEN_realtime_getPeriodSinCosClk)(int deviceHandle, int* value_period) {
    return SEN_realtime_getPeriodSinCosClk_SEN_1_0_0(deviceHandle, value_period);
}


/** @brief @SEN_realtime_setPeriodSinCosClk
*  Sets the Sin/Cos and AquadB period clock.
*
*  @param deviceHandle     Handle of device
*  @param period           value from 40 ns to 10200 ns
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setPeriodSinCosClk_SEN_1_0_0(int deviceHandle, int period);

static inline int ATTO_FUNCTION(SEN_realtime_setPeriodSinCosClk)(int deviceHandle, int period) {
    return SEN_realtime_setPeriodSinCosClk_SEN_1_0_0(deviceHandle, period);
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
int ATTOCUBE_API SEN_realtime_getResolutionSinCos_SEN_1_0_0(int deviceHandle, int* value_resolution);

static inline int ATTO_FUNCTION(SEN_realtime_getResolutionSinCos)(int deviceHandle, int* value_resolution) {
    return SEN_realtime_getResolutionSinCos_SEN_1_0_0(deviceHandle, value_resolution);
}


/** @brief @SEN_realtime_setResolutionSinCos
*  Sets the Sin/Cos and AquadB resolution.
*
*  @param deviceHandle     Handle of device
*  @param resolution       value from 1 pm to 65535 pm
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setResolutionSinCos_SEN_1_0_0(int deviceHandle, int resolution);

static inline int ATTO_FUNCTION(SEN_realtime_setResolutionSinCos)(int deviceHandle, int resolution) {
    return SEN_realtime_setResolutionSinCos_SEN_1_0_0(deviceHandle, resolution);
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
int ATTOCUBE_API SEN_realtime_getHighPassCutOffFreq_SEN_1_0_0(int deviceHandle, int* value_filternumber);

static inline int ATTO_FUNCTION(SEN_realtime_getHighPassCutOffFreq)(int deviceHandle, int* value_filternumber) {
    return SEN_realtime_getHighPassCutOffFreq_SEN_1_0_0(deviceHandle, value_filternumber);
}


/** @brief @SEN_realtime_setHighPassCutOffFreq
*  Sets the high pass filter number of Linear analog output mode.
*
*  @param deviceHandle     Handle of device
*  @param filternumber     value from 1 to 24
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_setHighPassCutOffFreq_SEN_1_0_0(int deviceHandle, int filternumber);

static inline int ATTO_FUNCTION(SEN_realtime_setHighPassCutOffFreq)(int deviceHandle, int filternumber) {
    return SEN_realtime_setHighPassCutOffFreq_SEN_1_0_0(deviceHandle, filternumber);
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
int ATTOCUBE_API SEN_realtime_setAaf_SEN_1_0_0(int deviceHandle, bool enable, int attenuation, int window);

static inline int ATTO_FUNCTION(SEN_realtime_setAaf)(int deviceHandle, bool enable, int attenuation, int window) {
    return SEN_realtime_setAaf_SEN_1_0_0(deviceHandle, enable, attenuation, window);
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
int ATTOCUBE_API SEN_realtime_getAafAttenuation_SEN_1_0_0(int deviceHandle, int* value_attenuation);

static inline int ATTO_FUNCTION(SEN_realtime_getAafAttenuation)(int deviceHandle, int* value_attenuation) {
    return SEN_realtime_getAafAttenuation_SEN_1_0_0(deviceHandle, value_attenuation);
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
int ATTOCUBE_API SEN_realtime_getAafWindow_SEN_1_0_0(int deviceHandle, int* value_window);

static inline int ATTO_FUNCTION(SEN_realtime_getAafWindow)(int deviceHandle, int* value_window) {
    return SEN_realtime_getAafWindow_SEN_1_0_0(deviceHandle, value_window);
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
int ATTOCUBE_API SEN_realtime_getAafEnabled_SEN_1_0_0(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(SEN_realtime_getAafEnabled)(int deviceHandle, bool* value_enabled) {
    return SEN_realtime_getAafEnabled_SEN_1_0_0(deviceHandle, value_enabled);
}


/** @brief @SEN_realtime_apply
*  Applies new real-time settings.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_apply_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_realtime_apply)(int deviceHandle) {
    return SEN_realtime_apply_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_realtime_discard
*  Discards new real-time settings.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_discard_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_realtime_discard)(int deviceHandle) {
    return SEN_realtime_discard_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_realtime_enableTestChannel
*  Enables the test channel on measurement axis 0, which can be used for estimating the maximum signal range./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_enableTestChannel_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_realtime_enableTestChannel)(int deviceHandle) {
    return SEN_realtime_enableTestChannel_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_realtime_disableTestChannel
*  Disables the test channel.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_realtime_disableTestChannel_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_realtime_disableTestChannel)(int deviceHandle) {
    return SEN_realtime_disableTestChannel_SEN_1_0_0(deviceHandle);
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
int ATTOCUBE_API SEN_realtime_getTestChannelEnabled_SEN_1_0_0(int deviceHandle, bool* value_enabled);

static inline int ATTO_FUNCTION(SEN_realtime_getTestChannelEnabled)(int deviceHandle, bool* value_enabled) {
    return SEN_realtime_getTestChannelEnabled_SEN_1_0_0(deviceHandle, value_enabled);
}


/** @brief @SEN_system_stopMeasurement
*  Stops the measurement system state.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_stopMeasurement_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_system_stopMeasurement)(int deviceHandle) {
    return SEN_system_stopMeasurement_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_system_startMeasurement
*  Starts the measurement system state./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function)
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_startMeasurement_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_system_startMeasurement)(int deviceHandle) {
    return SEN_system_startMeasurement_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_system_restartMeasurement
*  Restarts the absolute measurement system state./nThis function is only available in the "measurement running" state (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_restartMeasurement_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_system_restartMeasurement)(int deviceHandle) {
    return SEN_system_restartMeasurement_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_system_startOpticsAlignment
*  Starts the optical alignment system state./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_startOpticsAlignment_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_system_startOpticsAlignment)(int deviceHandle) {
    return SEN_system_startOpticsAlignment_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_system_stopOpticsAlignment
*  Stops the optical alignment system state./nThis function is only available in the "optics alignment running" state (please refer to the getCurrentMode function).
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_stopOpticsAlignment_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_system_stopOpticsAlignment)(int deviceHandle) {
    return SEN_system_stopOpticsAlignment_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_system_resetAxes
*  Resets the displacement value of all measurement axes to zero.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_resetAxes_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_system_resetAxes)(int deviceHandle) {
    return SEN_system_resetAxes_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_system_resetAxis
*  Resets the displacement value of a specific measurement axis to zero.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_resetAxis_SEN_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(SEN_system_resetAxis)(int deviceHandle, int axis) {
    return SEN_system_resetAxis_SEN_1_0_0(deviceHandle, axis);
}


/** @brief @SEN_system_resetError
*  Resets a measurement error that has been raised with the aim to continue the interrupted measurement./nIt is configurable if an additional renormalization process (please refer to the device user manual) should be performed or not./n/n
  This function can be used in two cases:/n
 	1.
*
*  @param deviceHandle     Handle of device
*  @param performRenormalization true = enable; false = disable
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_resetError_SEN_1_0_0(int deviceHandle, bool performRenormalization);

static inline int ATTO_FUNCTION(SEN_system_resetError)(int deviceHandle, bool performRenormalization) {
    return SEN_system_resetError_SEN_1_0_0(deviceHandle, performRenormalization);
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
int ATTOCUBE_API SEN_system_getCurrentMode_SEN_1_0_0(int deviceHandle, char* value_mode, int size);

static inline int ATTO_FUNCTION(SEN_system_getCurrentMode)(int deviceHandle, char* value_mode, int size) {
    return SEN_system_getCurrentMode_SEN_1_0_0(deviceHandle, value_mode, size);
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
int ATTOCUBE_API SEN_system_getFpgaVersion_SEN_1_0_0(int deviceHandle, char* value_version, int size);

static inline int ATTO_FUNCTION(SEN_system_getFpgaVersion)(int deviceHandle, char* value_version, int size) {
    return SEN_system_getFpgaVersion_SEN_1_0_0(deviceHandle, value_version, size);
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
int ATTOCUBE_API SEN_system_getDeviceType_SEN_1_0_0(int deviceHandle, char* value_type, int size);

static inline int ATTO_FUNCTION(SEN_system_getDeviceType)(int deviceHandle, char* value_type, int size) {
    return SEN_system_getDeviceType_SEN_1_0_0(deviceHandle, value_type, size);
}


/** @brief @SEN_system_getSystemError
*  Reads out the system error.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_getSystemError_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_system_getSystemError)(int deviceHandle) {
    return SEN_system_getSystemError_SEN_1_0_0(deviceHandle);
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
int ATTOCUBE_API SEN_system_getNbrFeaturesActivated_SEN_1_0_0(int deviceHandle, int* value_nbr);

static inline int ATTO_FUNCTION(SEN_system_getNbrFeaturesActivated)(int deviceHandle, int* value_nbr) {
    return SEN_system_getNbrFeaturesActivated_SEN_1_0_0(deviceHandle, value_nbr);
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
int ATTOCUBE_API SEN_system_getFeaturesName_SEN_1_0_0(int deviceHandle, int featurenumber, char* value_names, int size);

static inline int ATTO_FUNCTION(SEN_system_getFeaturesName)(int deviceHandle, int featurenumber, char* value_names, int size) {
    return SEN_system_getFeaturesName_SEN_1_0_0(deviceHandle, featurenumber, value_names, size);
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
int ATTOCUBE_API SEN_system_getInitMode_SEN_1_0_0(int deviceHandle, int* value_mode);

static inline int ATTO_FUNCTION(SEN_system_getInitMode)(int deviceHandle, int* value_mode) {
    return SEN_system_getInitMode_SEN_1_0_0(deviceHandle, value_mode);
}


/** @brief @SEN_system_setInitMode
*  Sets the mode for the initialization procedure that is performed when starting a measurement.
*
*  @param deviceHandle     Handle of device
*  @param mode             0 = High Accuracy Initialization; 1 = Quick Initialization
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_system_setInitMode_SEN_1_0_0(int deviceHandle, int mode);

static inline int ATTO_FUNCTION(SEN_system_setInitMode)(int deviceHandle, int mode) {
    return SEN_system_setInitMode_SEN_1_0_0(deviceHandle, mode);
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
int ATTOCUBE_API SEN_manual_getHumidityInPercent_SEN_1_0_0(int deviceHandle, int axis, double* humidity);

static inline int ATTO_FUNCTION(SEN_manual_getHumidityInPercent)(int deviceHandle, int axis, double* humidity) {
    return SEN_manual_getHumidityInPercent_SEN_1_0_0(deviceHandle, axis, humidity);
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
int ATTOCUBE_API SEN_manual_getPressureInHPa_SEN_1_0_0(int deviceHandle, int axis, double* pressure);

static inline int ATTO_FUNCTION(SEN_manual_getPressureInHPa)(int deviceHandle, int axis, double* pressure) {
    return SEN_manual_getPressureInHPa_SEN_1_0_0(deviceHandle, axis, pressure);
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
int ATTOCUBE_API SEN_manual_getRefractiveIndex_SEN_1_0_0(int deviceHandle, int axis, double* rindex);

static inline int ATTO_FUNCTION(SEN_manual_getRefractiveIndex)(int deviceHandle, int axis, double* rindex) {
    return SEN_manual_getRefractiveIndex_SEN_1_0_0(deviceHandle, axis, rindex);
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
int ATTOCUBE_API SEN_manual_getTemperatureInDegrees_SEN_1_0_0(int deviceHandle, int axis, double* temperature);

static inline int ATTO_FUNCTION(SEN_manual_getTemperatureInDegrees)(int deviceHandle, int axis, double* temperature) {
    return SEN_manual_getTemperatureInDegrees_SEN_1_0_0(deviceHandle, axis, temperature);
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
int ATTOCUBE_API SEN_manual_setHumidityInPercent_SEN_1_0_0(int deviceHandle, int axis, double humidity);

static inline int ATTO_FUNCTION(SEN_manual_setHumidityInPercent)(int deviceHandle, int axis, double humidity) {
    return SEN_manual_setHumidityInPercent_SEN_1_0_0(deviceHandle, axis, humidity);
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
int ATTOCUBE_API SEN_manual_setPressureInHPa_SEN_1_0_0(int deviceHandle, int axis, double pressure);

static inline int ATTO_FUNCTION(SEN_manual_setPressureInHPa)(int deviceHandle, int axis, double pressure) {
    return SEN_manual_setPressureInHPa_SEN_1_0_0(deviceHandle, axis, pressure);
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
int ATTOCUBE_API SEN_manual_setRefractiveIndex_SEN_1_0_0(int deviceHandle, int axis, double rindex);

static inline int ATTO_FUNCTION(SEN_manual_setRefractiveIndex)(int deviceHandle, int axis, double rindex) {
    return SEN_manual_setRefractiveIndex_SEN_1_0_0(deviceHandle, axis, rindex);
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
int ATTOCUBE_API SEN_manual_setTemperatureInDegrees_SEN_1_0_0(int deviceHandle, int axis, double temperature);

static inline int ATTO_FUNCTION(SEN_manual_setTemperatureInDegrees)(int deviceHandle, int axis, double temperature) {
    return SEN_manual_setTemperatureInDegrees_SEN_1_0_0(deviceHandle, axis, temperature);
}


/** @brief @SEN_ecu_disable
*  Disables the ECU interface.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_ecu_disable_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_ecu_disable)(int deviceHandle) {
    return SEN_ecu_disable_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_ecu_enable
*  Enables the ECU interface.
*
*  @param deviceHandle     Handle of device
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_ecu_enable_SEN_1_0_0(int deviceHandle);

static inline int ATTO_FUNCTION(SEN_ecu_enable)(int deviceHandle) {
    return SEN_ecu_enable_SEN_1_0_0(deviceHandle);
}


/** @brief @SEN_ecu_getConnected
*  Reads out whether the ECU interface is physically connected or not. Checking if the ECU is connected can only be done on an enabled ECU interface.
*
*  @param deviceHandle     Handle of device
*
*  @param connected        true = connected; false = disconnected
*
*  @return true = connected; false = disconnected
*/
int ATTOCUBE_API SEN_ecu_getConnected_SEN_1_0_0(int deviceHandle, bool* connected);

static inline int ATTO_FUNCTION(SEN_ecu_getConnected)(int deviceHandle, bool* connected) {
    return SEN_ecu_getConnected_SEN_1_0_0(deviceHandle, connected);
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
int ATTOCUBE_API SEN_ecu_getEnabled_SEN_1_0_0(int deviceHandle, bool* enabled);

static inline int ATTO_FUNCTION(SEN_ecu_getEnabled)(int deviceHandle, bool* enabled) {
    return SEN_ecu_getEnabled_SEN_1_0_0(deviceHandle, enabled);
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
int ATTOCUBE_API SEN_ecu_getHumidityInPercent_SEN_1_0_0(int deviceHandle, double* humidity);

static inline int ATTO_FUNCTION(SEN_ecu_getHumidityInPercent)(int deviceHandle, double* humidity) {
    return SEN_ecu_getHumidityInPercent_SEN_1_0_0(deviceHandle, humidity);
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
int ATTOCUBE_API SEN_ecu_getPressureInHPa_SEN_1_0_0(int deviceHandle, double* pressure);

static inline int ATTO_FUNCTION(SEN_ecu_getPressureInHPa)(int deviceHandle, double* pressure) {
    return SEN_ecu_getPressureInHPa_SEN_1_0_0(deviceHandle, pressure);
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
int ATTOCUBE_API SEN_ecu_getRefractiveIndex_SEN_1_0_0(int deviceHandle, double* rIndex);

static inline int ATTO_FUNCTION(SEN_ecu_getRefractiveIndex)(int deviceHandle, double* rIndex) {
    return SEN_ecu_getRefractiveIndex_SEN_1_0_0(deviceHandle, rIndex);
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
int ATTOCUBE_API SEN_ecu_getRefractiveIndexCompensationMode_SEN_1_0_0(int deviceHandle, int axis, int* mode);

static inline int ATTO_FUNCTION(SEN_ecu_getRefractiveIndexCompensationMode)(int deviceHandle, int axis, int* mode) {
    return SEN_ecu_getRefractiveIndexCompensationMode_SEN_1_0_0(deviceHandle, axis, mode);
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
int ATTOCUBE_API SEN_ecu_getRefractiveIndexForCompensation_SEN_1_0_0(int deviceHandle, int axis, double* rIndex);

static inline int ATTO_FUNCTION(SEN_ecu_getRefractiveIndexForCompensation)(int deviceHandle, int axis, double* rIndex) {
    return SEN_ecu_getRefractiveIndexForCompensation_SEN_1_0_0(deviceHandle, axis, rIndex);
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
int ATTOCUBE_API SEN_ecu_getTemperatureInDegrees_SEN_1_0_0(int deviceHandle, double* temperature);

static inline int ATTO_FUNCTION(SEN_ecu_getTemperatureInDegrees)(int deviceHandle, double* temperature) {
    return SEN_ecu_getTemperatureInDegrees_SEN_1_0_0(deviceHandle, temperature);
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
int ATTOCUBE_API SEN_ecu_setRefractiveIndexCompensationMode_SEN_1_0_0(int deviceHandle, int axis, int mode);

static inline int ATTO_FUNCTION(SEN_ecu_setRefractiveIndexCompensationMode)(int deviceHandle, int axis, int mode) {
    return SEN_ecu_setRefractiveIndexCompensationMode_SEN_1_0_0(deviceHandle, axis, mode);
}


/** @brief @SEN_nlc_clearLut
*  Deactivates the LUT and removes it from the device for a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_nlc_clearLut_SEN_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(SEN_nlc_clearLut)(int deviceHandle, int axis) {
    return SEN_nlc_clearLut_SEN_1_0_0(deviceHandle, axis);
}


/** @brief @SEN_nlc_createLut
*  Creates a new LUT for a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_nlc_createLut_SEN_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(SEN_nlc_createLut)(int deviceHandle, int axis) {
    return SEN_nlc_createLut_SEN_1_0_0(deviceHandle, axis);
}


/** @brief @SEN_nlc_estimateNonlinearities
*  Estimates the nonlinearity error for the current device settings without changing or updating any settings.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_nlc_estimateNonlinearities_SEN_1_0_0(int deviceHandle, int axis);

static inline int ATTO_FUNCTION(SEN_nlc_estimateNonlinearities)(int deviceHandle, int axis) {
    return SEN_nlc_estimateNonlinearities_SEN_1_0_0(deviceHandle, axis);
}


/** @brief @SEN_nlc_getDynamicNormalization
*  Returns the normalization mode of a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param mode             0 = dynamic normalization (default)
1 = normalization frozen (for slow target drifts)
2 = normalization mode determined by target velocity
*
*  @return 0 = dynamic normalization (default)
1 = normalization frozen (for slow target drifts)
2 = normalization mode determined by target velocity
*/
int ATTOCUBE_API SEN_nlc_getDynamicNormalization_SEN_1_0_0(int deviceHandle, int axis, int* mode);

static inline int ATTO_FUNCTION(SEN_nlc_getDynamicNormalization)(int deviceHandle, int axis, int* mode) {
    return SEN_nlc_getDynamicNormalization_SEN_1_0_0(deviceHandle, axis, mode);
}


/** @brief @SEN_nlc_getHistogram
*  Returns a histogram of the measured nonlinearity errors obtained from the last call of the createLut or estimateNonlinearites functions.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param histogram        histogram array
*  @param size             Maximum size of buffer histogram
*
*  @return histogram array
*/
int ATTOCUBE_API SEN_nlc_getHistogram_SEN_1_0_0(int deviceHandle, int axis, char* histogram, int size);

static inline int ATTO_FUNCTION(SEN_nlc_getHistogram)(int deviceHandle, int axis, char* histogram, int size) {
    return SEN_nlc_getHistogram_SEN_1_0_0(deviceHandle, axis, histogram, size);
}


/** @brief @SEN_nlc_getLut
*  Returns the LUT determined by the createLut function, which can be applied by the setLutApplied function.
*   
*   Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param lut              LUT array with 512 integers
*  @param size             Maximum size of buffer lut
*
*  @return LUT array with 512 integers
*/
int ATTOCUBE_API SEN_nlc_getLut_SEN_1_0_0(int deviceHandle, int axis, char* lut, int size);

static inline int ATTO_FUNCTION(SEN_nlc_getLut)(int deviceHandle, int axis, char* lut, int size) {
    return SEN_nlc_getLut_SEN_1_0_0(deviceHandle, axis, lut, size);
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
int ATTOCUBE_API SEN_nlc_getLutApplied_SEN_1_0_0(int deviceHandle, int axis, bool* apply);

static inline int ATTO_FUNCTION(SEN_nlc_getLutApplied)(int deviceHandle, int axis, bool* apply) {
    return SEN_nlc_getLutApplied_SEN_1_0_0(deviceHandle, axis, apply);
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
int ATTOCUBE_API SEN_nlc_getLutStatus_SEN_1_0_0(int deviceHandle, int axis, int* warningNo, bool* status);

static inline int ATTO_FUNCTION(SEN_nlc_getLutStatus)(int deviceHandle, int axis, int* warningNo, bool* status) {
    return SEN_nlc_getLutStatus_SEN_1_0_0(deviceHandle, axis, warningNo, status);
}


/** @brief @SEN_nlc_getNonlinearityEstimation
*  Returns the LUT created by the estimateNonlinearities function (read-only mode) to compensate the nonlinearity error of the device for the current device settings. If no estimation was created an array of zeros is returned.
*   
*   Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).
*
*  @param deviceHandle     Handle of device
*
*  @param lut              LUT array with 512 integers
*  @param size             Maximum size of buffer lut
*
*  @return LUT array with 512 integers
*/
int ATTOCUBE_API SEN_nlc_getNonlinearityEstimation_SEN_1_0_0(int deviceHandle, char* lut, int size);

static inline int ATTO_FUNCTION(SEN_nlc_getNonlinearityEstimation)(int deviceHandle, char* lut, int size) {
    return SEN_nlc_getNonlinearityEstimation_SEN_1_0_0(deviceHandle, lut, size);
}


/** @brief @SEN_nlc_getRawLut
*  Returns the raw LUT created by the createLut or estimateNonlinearites functions.
*   
*   Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).
*           For debugging only.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*
*  @param raw_lut          Json dumped lut array
*  @param size             Maximum size of buffer raw_lut
*
*  @return Json dumped lut array
*/
int ATTOCUBE_API SEN_nlc_getRawLut_SEN_1_0_0(int deviceHandle, int axis, char* raw_lut, int size);

static inline int ATTO_FUNCTION(SEN_nlc_getRawLut)(int deviceHandle, int axis, char* raw_lut, int size) {
    return SEN_nlc_getRawLut_SEN_1_0_0(deviceHandle, axis, raw_lut, size);
}


/** @brief @SEN_nlc_getVelocityThresholds
*  Returns the threshold velocities for mode 2 of the setDynamicNormalization function.
*
*  @param deviceHandle     Handle of device
*
*  @param velocityOn       target velocity in µm/s (default: 10 µm/s)
*  @param velocityOff      target velocity in µm/s (default: 5 µm/s)
*
*  @return target velocity in µm/s (default: 10 µm/s)
*/
int ATTOCUBE_API SEN_nlc_getVelocityThresholds_SEN_1_0_0(int deviceHandle, int* velocityOn, int* velocityOff);

static inline int ATTO_FUNCTION(SEN_nlc_getVelocityThresholds)(int deviceHandle, int* velocityOn, int* velocityOff) {
    return SEN_nlc_getVelocityThresholds_SEN_1_0_0(deviceHandle, velocityOn, velocityOff);
}


/** @brief @SEN_nlc_setDynamicNormalization
*  Sets the normalization mode of a specific measurement axis.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param mode             0 = dynamic normalization 
1 = normalization frozen (for slow target drifts)
2 = automatic alternation between mode 0 and 1 depending on the target velocity
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_nlc_setDynamicNormalization_SEN_1_0_0(int deviceHandle, int axis, int mode);

static inline int ATTO_FUNCTION(SEN_nlc_setDynamicNormalization)(int deviceHandle, int axis, int mode) {
    return SEN_nlc_setDynamicNormalization_SEN_1_0_0(deviceHandle, axis, mode);
}


/** @brief @SEN_nlc_setLut
*  Uploads a LUT for a specific measurement axis, which can be applied by the setLutApplied function.
*
*  @param deviceHandle     Handle of device
*  @param axis             [0|1|2]
*  @param lut              LUT array with 512 integers
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_nlc_setLut_SEN_1_0_0(int deviceHandle, int axis, const char* lut);

static inline int ATTO_FUNCTION(SEN_nlc_setLut)(int deviceHandle, int axis, const char* lut) {
    return SEN_nlc_setLut_SEN_1_0_0(deviceHandle, axis, lut);
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
int ATTOCUBE_API SEN_nlc_setLutApplied_SEN_1_0_0(int deviceHandle, int axis, bool apply);

static inline int ATTO_FUNCTION(SEN_nlc_setLutApplied)(int deviceHandle, int axis, bool apply) {
    return SEN_nlc_setLutApplied_SEN_1_0_0(deviceHandle, axis, apply);
}


/** @brief @SEN_nlc_setVelocityThresholds
*  Sets the threshold velocities for mode 2 of the setDynamicNormalization function. By default, the normalization in mode 2 is frozen for velocities below 5 µm/s and switches to dynamic mode for velocities above 10 µm/s.
*
*  @param deviceHandle     Handle of device
*  @param velocityOn       target velocity in µm/s (default: 10 µm/s)
*  @param velocityOff      target velocity in µm/s (default: 5 µm/s)
*
*  @return Error number if one occurred, 0 in case of no error
*/
int ATTOCUBE_API SEN_nlc_setVelocityThresholds_SEN_1_0_0(int deviceHandle, int velocityOn, int velocityOff);

static inline int ATTO_FUNCTION(SEN_nlc_setVelocityThresholds)(int deviceHandle, int velocityOn, int velocityOff) {
    return SEN_nlc_setVelocityThresholds_SEN_1_0_0(deviceHandle, velocityOn, velocityOff);
}


#ifdef __cplusplus
}
#endif
#undef ATTO_PREFIX
#endif // __GENERATEDAPI_H_SEN_1_0_0__