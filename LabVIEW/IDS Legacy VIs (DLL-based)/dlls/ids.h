
#ifndef IDS_H
#define IDS_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#define IDS_DLL __declspec(dllexport)
#elif defined(UNIX)
#define IDS_DLL
#else
#define IDS_DLL __declspec(dllimport)
#endif

#include <stdint.h>
#include <stdbool.h>

#define GENERIC_ERROR -1
#define ALREADY_CONNECTED_ERROR -3
#define NOT_CONNECTED_ERROR -4
#define BAD_IP_ADDRESS -5
#define CONNECTION_TIMEOUT -6
#define NO_DEVICE_FOUND_ERR -7
#define LOCAL_FILE_ERROR 2056
#define	ERR_LICENSE_FILE_NOT_FOUND 2114
#define RT_OUT_MODE_HSSL_TTL 0
#define RT_OUT_MODE_HSSL_LVDS 1
#define RT_OUT_MODE_AQUADB_TTL 2
#define RT_OUT_MODE_AQUADB_LVDS 3
#define RT_OUT_MODE_SINCOS_TTL 4
#define RT_OUT_MODE_SINCOS_LVDS 5


/** \brief : Connect to IDS at adresse "ipAddress", on port "port"
 *
 * \param[in] ipAddress : null terminated string containing ipv4 address of the IDS
 * \param[in] port : tcp port on which IDS software runs
 *
 * \return : 0 if success,
 *           PARAM_ERROR if ipAddress is not a correct ipv4 address
 *           GENERIC_ERROR if another error occured
 */
int IDS_DLL IDS_Connect(char* ipAddress, int port, int* deviceHandle);

/** \brief : Disconnect from IDS
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_Disconnect(int deviceHandle);

/** \brief : Retrieve version number of this dll
 *
 * \param[out] version : buffer where the version string will bet stored (30 bytes MIN)
 */
void IDS_DLL IDS_GetDllVersion(char* version);

/** @brief get lock status
*
*  get information weither the device is locked or not and if access is authorized
*
*  \param[out]  locked: indicates if the device is locked
*  \param[out]  authorized: indicates if access is granted for this dll
*
*  \return   Result of function
*/
int IDS_DLL IDS_getLockStatus(int deviceHandle, bool* locked, bool* authorized);


/** @brief lock device with password
*
*  lock the device so that it will only be possible to call functions by knowing the password
*
*  \param[in]  password: null-terminated string
*
*  \return   Result of function
*/
int IDS_DLL IDS_lock(int deviceHandle, char* password);

/** @brief request access to a locked device
*
*  \param[in]  password: null-terminated string
*
*  \return   Result of function
*/
int IDS_DLL IDS_grantAccess(int deviceHandle, char* password);


/** @brief unlock the device
*
*  unlock the device so that it will be available to all clients
*
*  \return   Result of function
*/
int IDS_DLL IDS_unlock(int deviceHandle);

//System (Update/reset)

/** \brief : set IP settings of IDS
*
* \param[in] ipaddress : Desired IP address of the IDS
* \param[in] subnetmask : Corresponding subnet mask of the network
* \param[in] defaultgateway : To the IP address related default gateway
* \param[in] setmode :
* 0 = Set input IP address, input subnet mask and input default
gateway
* 1 = Set DHCP mode
* 2 = Set Client mode
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_system_setIpSettings(int deviceHandle, const char *ipaddress, const char *subnetmask, const char *defaultgateway, uint32_t	setmode);

/** \brief : retrieve IpAddress of the IDS
 *
 * \param[out] addr : pointer to minimum 16-bytes buffer where the address will
 *                    be stored as a null-terminated string
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_getIpAddress(int deviceHandle, char *addr);


/** \brief : retrieve subnet mask of the IDS
 *
 * \param[out] mask : pointer to minimum 16-bytes buffer where the mask will
 *                    be stored as a null-terminated string
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_getSubnetMask(int deviceHandle, char * mask);


/** \brief : retrieve default gateway of the IDS
 *
 * \param[out] addr : pointer to minimum 16-bytes buffer where the gateway will
 *                    be stored as a null-terminated string
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_getGateway(int deviceHandle, char * gateway);

/** \brief : perform a reset to factory settings of the IDS
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_factoryReset(int deviceHandle);


/** \brief : Update the system to a newer firmware
*
* \param[in] filePath : Path the update image file
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*           others hardware related error codes that must be converted with
*           IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_system_firmwareUpdate(int deviceHandle, char* filePath);

/** \brief : Get the progress in percentage of update procedure
*
* \param[out] progress : progress in %, 100 indicates update is finished
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*           others hardware related error codes that must be converted with
*           IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_system_getFirmwareUpdateProgress(int deviceHandle, int * progress);

/** \brief : Clear displacment errors (e.g. beam interrupt), while measurement is running.
 *
 * \param[in] performRenormalization : Indicates if a additional renormalization has to be done 
                                       in case of beam interruption or signal loss
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           other hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_resetError(int deviceHandle, bool performRenormalization);


/** \brief : perform a reboot of the IDS
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_rebootSystem(int deviceHandle);

/** \brief : retrieve the firmware version of the IDS
 *
 * \param[out] version : buffer of minimum 16 bytes where the version number will be
 *                       stored as a nul-terminated string
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_getFirmwareVersion(int deviceHandle, char * version);

/** \brief : retrieve the fpga version of the IDS
 *
 * \param[out] version : buffer of minimum 16 bytes where the version number will be
 *                       stored as a nul-terminated string
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_getFpgaVersion(int deviceHandle, char * version);

/** \brief : get the string corresponding to an errorNumber
 *
 * \param[in] language : value corresponding to language in which the error should return
 * \param[in] errorNumber : number of error to convert to string
 * \param[out] error : buffer in which the error string will be stored
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_errorNumberToString (int deviceHandle, const uint32_t language, const int32_t errorNumber, char * error);

/** \brief : get the recommendation corresponding to an errorNumber
 *
 * \param[in] language : value corresponding to language in which the error should return
 * \param[in] errorNumber : number of error to convert to string
 * \param[out] error : buffer in which the error string will be stored
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 */
int IDS_DLL IDS_system_errorNumberToRecommendation (int deviceHandle, const uint32_t language, const int32_t errorNumber, char * error);

/** \brief : retrieve deviceName of the IDS
*
* \param[out] name : Allocated buffer where the name will be stored
*                    as null-terminated string
*
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*/
int IDS_DLL IDS_system_getDeviceName(int deviceHandle, char *name);


/** \brief : set deviceName of the IDS
*
* \param[in] name : friendly name given to the device
*
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*/
int IDS_DLL IDS_system_setDeviceName(int deviceHandle, const char *name);


/** \brief : retrieve serial number of the IDS
*
* \param[out] sn : Allocated buffer where the serial number will be stored
*                    as null-terminated string.  9 bytes min
*
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*/
int IDS_DLL IDS_system_getSerialNumber(int deviceHandle, char *sn);

/** \brief : retrieve device type of the IDS
*
* \param[out] type : Allocated buffer where the device type will be stored
*                    as null-terminated string.
*
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*/
int IDS_DLL IDS_system_getDeviceType(int deviceHandle, char *type);

/** \brief : retrieve mac address of the IDS
*
* \param[out] mac : Allocated buffer where the mac address will be stored
*                    as null-terminated string. min lenght : 18
*
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*/
int IDS_DLL IDS_system_getMacAddress(int deviceHandle, char *mac);

/** \brief : Update the license of the system
*
* \param[in] filePath : Path to the license file
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*           others hardware related error codes that must be converted with
*           IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_system_UploadLicenseFile(int deviceHandle, char* filePath);

/** \brief : Get number of activated features
*
* \param[out] numberofactivatedfeatures: Gives the number of activated
features
*
* \return : 0 if success,
*NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_system_GetNumberOfActivatedFeatures(int deviceHandle, int32_t * numberofactivatedfeatures);


/** \brief : Sets the Initialization mode
*
* \param[in] mode : 0-> High Accuracy Initialization,
* 1-> Quick Initialization,
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL  IDS_system_setInitMode(int deviceHandle, const int32_t mode);

/** \brief : Returns the Initialization mode
*
* \param[out] mode : 0-> High Accuracy Initialization,
* 1-> Quick Initialization,
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL  IDS_system_getInitMode(int deviceInitHandle, int32_t * mode);

/** \brief : Get the name of the activated feature number
*
* \param[in] featurenumber: Number of feature
* \param[out] featurename: The name of the corresponding feature
*
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_system_GetFeatureName(int deviceHandle, const int32_t featurenumber, char* featurename);









// Realtime Output
/** \brief : read the realtime output mode
 *
 * \param[out] rtOutMode : pointer to a integer where the mode will be stored
 *              0=HSSL (TTL), 1=HSSL (LVDS), 2=AquadB (TTL), 3=AquadB (LVDS),
 *              4=SinCos (TTL Error Signal), 5=SinCos (LVDS Error Signal
 *              6= Linear (TTL),7 =Linear (LVDS), 8 = BiSS-C
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_getRtOutMode(int deviceHandle, int32_t * rtOutMode);

/** \brief : Set the mode of the realtime output
 *
 * \param[in] rtOutMode : new mode to set
 *              0=HSSL (TTL), 1=HSSL (LVDS), 2=AquadB (TTL), 3=AquadB (LVDS),
 *              4=SinCos (TTL Error Signal), 5=SinCos (LVDS Error Signal),
 *              6= Linear (TTL),7 =Linear (LVDS), 8 = BiSS-C 
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_setRtOutMode(int deviceHandle, const int32_t rtOutMode);

/** \brief : The low parameter of the HSSL resolution. The hssl output will
 *           be a value between hssl low resolution and HSSL high resolution.
 *
 * \param[out] resolution :pointer to result (0 - 46)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_getResolutionHsslLow(int deviceHandle, int32_t * resolution);

/** \brief : The low parameter of the HSSL resolution. The hssl output will
 *           be a value between hssl low resolution and HSSL high resolution.
 *
 * \param[in] resolution : 0 - 46
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_setResolutionHsslLow(int deviceHandle, const int32_t resolution);

/** \brief : The high parameter of the HSSL resolution. The hssl output will
 *           be a value between hssl low resolution and HSSL high resolution.
 *
 * \param[out] resolution :pointer to result (1 - 47)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_getResolutionHsslHigh(int deviceHandle, int32_t * resolution);

/** \brief : The high parameter of the HSSL resolution. The hssl output will
 *           be a value between hssl low resolution and HSSL high resolution.
 *
 * \param[in] resolution : 1 - 47
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_setResolutionHsslHigh(int deviceHandle, const int32_t resolution);

/** \brief : The period of the hssl clock.
 *
 * \param[out] period :pointer to result (40 to 10200 ns)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_getPeriodHsslClk(int deviceHandle, int32_t * period);

/** \brief : The period of the hssl clock.
 *
 * \param[in] period : 40 to 10200 ns
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_setPeriodHsslClk(int deviceHandle, const int32_t period);

/** \brief : The gap between two values in ns.
 *
 * \param[out] gap :pointer to result ( 40 to 10200 ns)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_getPeriodHsslGap(int deviceHandle, int32_t * gap);

/** \brief : The gap between two values in ns.
 *
 * \param[in] gap : 40 to 10200 ns
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_setPeriodHsslGap(int deviceHandle, const int32_t gap);

/** \brief : The period of sin/cos and AquadB update clock in ns.
 *
 * \param[out] gap :pointer to result ( 40 to 10200 ns)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_getPeriodSinCosAndAquadBClk(int deviceHandle, int32_t * period);

/** \brief : The period of sin/cos and AquadB update clock in ns.
 *
 * \param[in] period : 40 to 10200 ns
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_setPeriodSinCosAndAquadBClk(int deviceHandle, const int32_t period);

/** \brief : The resolution of sin/cos and AquadB in 1pm
 *
 * \param[out] resolution :pointer to result ( 1 to 65535 pm)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_getResolutionSinCosAndAquadB(int deviceHandle, int32_t * resolution);

/** \brief : The resolution of sin/cos and AquadB in 1pm
 *
 * \param[in] resolution ( 1 to 65535 pm)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_rt_setResolutionSinCosAndAquadB(int deviceHandle, const int32_t resolution);


/** \brief : Set Distance mode (Available for HSSL and Linear Mode)
*
* \param[in] linearmode:
*         1 = Displacement  (Available in HSSL mode and Linear Mode)
*	      2 = Absolute Distance (Available in HSSL mode only)
*         3 = Vibrometry (Available in Linear mode only  (return ERR_INT_RANGE in Linear mode feature not active) 
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_rt_setRtDistanceMode(int deviceHandle, const int32_t distancemode);


/** \brief : Get Distance mode (Available for HSSL and Linear Mode)
*
* \param[out] Distancemode:
*         When Linear mode is selected : return  RtDistanceLinear ( Displacement or Vibrometry)
*         In all other mode:  return  RtDistance ( Displacement or Absolute Distance)
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_rt_getRtDistanceMode(int deviceHandle, int32_t * distancemode);



/** \brief : Set High Pass Cut-Off frequency filter number
*
* \param[in] filternumber: N, Linear Analog High Pass Cut-Off frequency is
*                           1600/2^N	kHz, with	N	 ∈ 1,24
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_rt_setRtLinearHighPassFilterNumber(int deviceHandle, const int32_t filternumber);

/** \brief : Set High Pass Cut-Off frequency filter number
*
* \param[out] filternumber: N, Linear Analog High Pass Cut-Off frequency is
*                          1600/2^N	kHz, with	N	 ∈ 1,24
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_rt_getRtLinearHighPassFilterNumber(int deviceHandle, int32_t * filternumber);

/** \brief : Set Linear Analog Output range
*
* \param[in] rangenumber: N, Linear Analog Range is +-2^(N+11)	pm	 ∈
* 0,34
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_rt_setRtLinearRangeNumber(int deviceHandle, const int32_t range);


/** \brief : Get Linear Analog Output range
*
* \param[out] rangenumber: N, Linear Analog Range is +-2^(N+11)	pm w ith N ∈
* 0,34
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_rt_getRtLinearRangeNumber(int deviceHandle,  int32_t * range);


/** \brief : Enables the Anti-Aliasing Unit with assigned Filter Window
*
* \param[in]
* - set: [0,1] 0 = disable Anti-Aliasing Filter, 1 = enable Anti-Aliasing Filter
* - attenuation : [3-30] dB m f_nyquist
* - window : 0 = Rectangular , 1 = Cosine, 2 = Cosine^2, 3 = Hamming, 4 Raised Cosine
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_rt_setAaf(int deviceHandle, const int32_t set, const int32_t attenuation, const int32_t window);

/** \brief : Checks if the Anti-Aliasing Unit is enabled
*
* \param[out] enabled : true = AAF is enabled , false = AAF is disabled
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_rt_AafIsEnabled(int deviceHandle, bool * enabled);

/** \brief : Returns the current Attenuation at f_nyquist of the Anti-Aliasing Unit
*
* \param[out] Attenuation : [0 - 33] dB at f_nyquist
*
* \return : 0 if success,
*NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_rt_getAafAttenuation(int deviceHandle, int32_t * Attenuation);

/** \brief : Returns the current Filter Window of the Anti-Aliasing Unit
*
* \param[out] FilterWindow : 0 = Rectangular , 1 = Cosine, 2 = Cosine^2, 3 = Hamming, 4 Raised Cosine
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_rt_getAafWindow(int deviceHandle, int32_t * FilterWindow);

/** \brief : Enable Test channel (Note enable on channel 0 )
*
*
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*           others hardware related error codes that must be converted with
*           IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_system_enableTestChannel(int deviceHandle);

/** \brief : Disable Test channel
*
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*           others hardware related error codes that must be converted with
*           IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_system_disableTestChannel(int deviceHandle);


/** \brief : Returns if the Test channel is enabled
*
* \param[out] connected : true if enabled, false if not
*
* \return : 0 if success,
*           NOT_CONNECTED_ERROR if there is no active connection to an IDS
*           others hardware related error codes that must be converted with
*           IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_system_isTestChannelEnabled(int deviceHandle, bool * enabled);





// Alignment

/** \brief : if the red pilot laser is enabled
 *
 * \param[out] enabled : true = enabled, false = disabled
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_laser_isEnabled(int deviceHandle, bool * enabled);

/** \brief : enable the pilot laser
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_laser_enable(int deviceHandle);

/** \brief : disable the pilot laser
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_laser_disable(int deviceHandle);

/** \brief : Start the optics alignment (Contrast measurement)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_startOpticsAlignment(int deviceHandle);

/** \brief : Stop the optics alignment (Contrast measurement)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_stopOpticsAlignment(int deviceHandle);

/** \brief : get the contrast of the signal (ratio sig max to
 *           sig min + some magic) in per mill.
 *
 * \param[in] axisNumber : axis to get the value from (0-2)
 * \param[out] contrast : in permill
 * \param[out] baseline : offset of the contrast measurment
 * \param[out] mixContrast : lower contrast measurment when measuring a mix contrast (indicated by error code)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_adjustment_getContrastInPermill(int deviceHandle, int axisNumber, int32_t * contrast, int32_t * baseline, int32_t* mixContrast);

/** \brief : Get the quality of signal in permill, this will allow the
 *           customer to readjust the measurement setup, if it is too low.
 *
 * \param[in]  axisNumber : number of axis on which quality is queried (0-2)
 * \param[out] contrast : contrast in permille
 * \param[out] baseline : baseline
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
extern int IDS_DLL IDS_displacement_getAxisSignalQuality(int deviceHandle, int axisNumber, int32_t * contrast, int32_t * baseline);

// Position

/** \brief : Returns the current averaging value. The averaging time is
 *           calculated by (2^n)*40ns, where n is the averaging value.
 *
 * \param[out] averageN : A value from 0 to 24
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_displacement_getAverageN(int deviceHandle, int32_t * averageN);

/** \brief : Sets the current averaging value. The averaging time is
 *           calculated by (2^n)*40ns, where n is the averaging value.
 *
 * \param[in] averageN : A value from 0 to 24
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_displacement_setAverageN(int deviceHandle, const int32_t averageN);

/** \brief : Get the absolute position of an axis
 *
 * \param[in] axis : number of the axis to get the position from(0-2)
 * \param[out] position : position of the axis in pm
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_displacement_getAbsolutePosition(int deviceHandle, const int axis, int64_t * position);

/** \brief : Get the absolute position of all axes
 *
 * \param[out] position0 : position of the axis 0 in pm
 * \param[out] position1 : position of the axis 1 in pm
 * \param[out] position2 : position of the axis 2 in pm
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_displacement_getAbsolutePositions(int deviceHandle, int64_t *position0, int64_t * position1, int64_t * position2);

/** \brief : Get the displacement of an axis
 *
 * \param[in] axis : number of the axis to get the displacement from(0-2)
 * \param[out] displacement : displacement of the axis in pm
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_displacement_getAxisDisplacement(int deviceHandle, const int axis, int64_t * displacement);

/** \brief : Get the displacement of an axis
 *
 * \param[out] displacement0 : displacement of the axis 0 in pm
 * \param[out] displacement1 : displacement of the axis 1 in pm
 * \param[out] displacement2 : displacement of the axis 2 in pm
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_displacement_getAxesDisplacement(int deviceHandle, int64_t * displacement0, int64_t * displacement1, int64_t * displacement2);


/** \brief : Start linearization procedure
 *
 * \param[in] deviceHandle : handle for the IDS to connect to
 * \param[in] axis : Axis which has to linearized
 * \param[in] fringesNbr : number of fringes for linearization
 * \param[in] samplesPerFringes : number of sample per fringe
 * \param[in] set : 0 = don't performe linearization
				   1 = perform linerization upload LUT and send LUT_array and residual nonlinear amplitude
				   2 = clear LUT (set LUT to zeros) 
 * \param[out] linTable : buffer of 512 x 32 bits where the linearization table will be stored [nm]
 * \param[out] nonLinearAmpl : buffer of 2 x 32 bits where the the absolute value of the positive and negative maximum of compensated table will be stored
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_displacement_linProc(int deviceHandle, const uint8_t axis, uint16_t fringesNbr , uint16_t samplesPerFringes, uint8_t set, double * linTable, double *nonLinearAmpl);

/** \brief : Reset axis to 0 to start a new measurement on the fly
 *
 * \param[in] axis : number of the axis to reset (0-2)
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_resetAxis(int deviceHandle, const int32_t axis);

/** \brief : Reset all axes to 0 to start a new measurement on the fly
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_resetAxes(int deviceHandle);

// IDS System

/** \brief : Return a string that describes the current mode in which the ids currently is
 *
 * \param[out] mode : pointer to a buffer where the mode will be stored
 *             expected values : "system idle", "measurement running", "optics alignment starting", 
 *                               "optics alignment running", "pilot laser enabled","Test Channel enabled" 
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_getCurrentMode(int deviceHandle, char* mode);

/** \brief : Start the measurement, this can take a while because the system
 *           needs to heat up the laser
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_startMeasurement(int deviceHandle);

/** \brief : Stop the measurement
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_stopMeasurement(int deviceHandle);

/** \brief Returns the system error if any occured. ERR_OK=0 if no error
 *         occured since the last time this method was called.
 *         The method automatically resets the system error to ERR_OK
 *
 * \param[out] error : system error
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_system_getSystemError(int deviceHandle, int64_t * error);

/** \brief : Returns the pass mode
 *
 * \param[out] mode : 0->single pass,
 *                    1->dual pass,
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_axis_getPassMode(int deviceHandle, int32_t * mode);

/** \brief : Sets the pass mode, also called the sensor head information
 *
 * \param[in] mode : 0->single pass,
 *                   1->dual pass,
 *                   2->xs sensor single pass,
 *                   3 -> customized sensor head
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_axis_setPassMode(int deviceHandle, const int32_t mode);


/** \brief : Returns the master axis
*
* \param[out] masteraxis : axisNumber : axis which is operating as master
axis from (0-2)
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_axis_getMasterAxis(int deviceHandle, int32_t * masteraxis);
/** \brief : Sets the master axis
*
* \param[in] masteraxis : axis which is operating as master axis from (0-2)
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_axis_setMasterAxis(int deviceHandle, const int32_t masteraxis);


// ECU

/** \brief : Returns if the ECU is connected to IDS
 *
 * \param[out] connected : true if connected, false if not
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_ecu_isConnected(int deviceHandle, bool * connected);


/** \brief : Returns if the ECU is enabled or disabled
 *
 * \param[out] enabled
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_ecu_isEnabled(int deviceHandle, bool * enabled);

/** \brief : enable the ECU
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_ecu_enable(int deviceHandle);

/** \brief : disable the ECU
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_ecu_disable(int deviceHandle);

/** \brief : Get the temperature in Degrees from the ECU
 *
 * \param[out] temp : temperature in degrees °C
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_ecu_getTemperatureInDegrees(int deviceHandle, double * temp);

/** \brief : Get the pressue in HPa from the ECU
 *
 * \param[out] pressure : pressure in HPa
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_ecu_getPressureInHPa(int deviceHandle, double * pressure);

/** \brief : Get the humidity in % from the ECU
 *
 * \param[out] humidity : humidity in %
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_ecu_getHumidityInPercent(int deviceHandle, double * humidity);

/** \brief : Get the refractive index from the ECU
 *
 * \param[out] rIndex : refractive index
 *
 * \return : 0 if success,
 *           NOT_CONNECTED_ERROR if there is no active connection to an IDS
 *           others hardware related error codes that must be converted with
 *           IDS_system_errorNumberToString function
 */
int IDS_DLL IDS_ecu_getRefractiveIndex(int deviceHandle, double * rIndex);

// BissC
/** \brief : Get the resolution N of Biss C with resolution = 2^N
*
* \param[out] resolution :pointer to result N = 1 to 16, with
* resolution = 2^N
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/

int IDS_DLL IDS_rt_setResolutionBissC(int deviceHandle, const int32_t resolution);
/** \brief : Set the resolution N of Biss C with resolution = 2^N
*
* \param[in] resolution N = 1 to 16, with resolution = 2^N
*
* \return : 0 if success,
* NOT_CONNECTED_ERROR if there is no active connection to an IDS
* others hardware related error codes that must be converted with
* IDS_system_errorNumberToString function
*/
int IDS_DLL IDS_rt_getResolutionBissC(int deviceHandle, int32_t * resolution);




#ifdef __cplusplus
}
#endif
#endif
