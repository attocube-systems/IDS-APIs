    
class Nlc():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ids.nlc"
            
    def clearLut(self, axis):
        """
        Deactivates the LUT and removes it from the device

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "clearLut", [axis])
        self.device.handleError(response)
        return 

    def createLut(self, axis):
        """
        Creates a new LUT for the given axis.

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS where the LUT should be generated

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "createLut", [axis])
        self.device.handleError(response)
        return 

    def estimateNonlinearities(self, axis):
        """
        Estimates the nonlinearity error for the current device settings without changing or updating any settings.

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS of which the nonlinearity error is to be estimated

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "estimateNonlinearities", [axis])
        self.device.handleError(response)
        return 

    def getDynamicNormalization(self, axis):
        """
        Returns the normalization mode of a specific axis.

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS of which the normalization mode is queried

        Returns
        -------
        mode: int32
            Normalization Mode

    0    Dynamic normalization

    1    Normalization frozen

    2    Normalization mode determined by target velocity
        """
        response = self.device.request(self.interface_name + "." + "getDynamicNormalization", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getHistogram(self, axis):
        """
        Returns a histogram of the measured nonlinearity errors obtained from the last call of createLut or estimateNonlinearites.

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS

        Returns
        -------
        histogram: string
            Json dumped histogram array
        """
        response = self.device.request(self.interface_name + "." + "getHistogram", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getLut(self, axis):
        """
        Returns the LUT determined by createLut (which can be applied by setLutApplied).

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS

        Returns
        -------
        lut: string
            Json dumped LUT array with 512 integers
        """
        response = self.device.request(self.interface_name + "." + "getLut", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getLutApplied(self, axis):
        """
        Returns whether a LUT is applied or not for a given axis.

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS of which the LUT apply rule is queried

        Returns
        -------
        apply: boolean
            True, if LUT is applied on this axis else False
        """
        response = self.device.request(self.interface_name + "." + "getLutApplied", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getLutStatus(self, axis):
        """
        Returns if a LUT is available and if warnings or errors occurred during creation.

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS of which the status of the LUT should be returned
        Returns
        -------
        creationWarning: int32
            Error or warning number if one occured while creating the LUT, 0 in case of no error
        status: boolean
            True, if a LUT exists else False
        """
        response = self.device.request(self.interface_name + "." + "getLutStatus", [axis])
        return response['result'][0], response['result'][1]

    def getNonlinearityEstimation(self):
        """
        Returns the LUT created by estimateNonlinearities (read-only mode) to compensate the nonlinearity error of the device for the current device settings. If no estimation was created an array of zeros is returned.

        Parameters
        ----------

        Returns
        -------
        lut: string
            Json dumped LUT array with 512 integers
        """
        response = self.device.request(self.interface_name + "." + "getNonlinearityEstimation")
        self.device.handleError(response)
        return response['result'][1]

    def getVelocityThresholds(self):
        """
        Returns the threshold velocity (in µm/s) for mode 2 of setDynamicNormalization.

        Parameters
        ----------

        Returns
        -------
        velocityOn: int32
            Velocity of the target in µm/s when to switch the normalization on (default: 10 µm/s)
        velocityOff: int32
            Velocity of the target in µm/s when to switch the normalization off (default: 5 µm/s)
        """
        response = self.device.request(self.interface_name + "." + "getVelocityThresholds")
        self.device.handleError(response)
        return response['result'][1], response['result'][2]

    def setDynamicNormalization(self, axis, mode):
        """
        Sets the normalization mode of a specific axis.

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS of which the normalization mode should be set
        mode: 
            Normalization Mode
                0    Dynamic normalization (default)
                1    Normalization frozen (for slow target drifts)
                2    Automatic alternation between mode 0 and 1 depending on the target velocity

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setDynamicNormalization", [axis, mode])
        self.device.handleError(response)
        return 

    def setLut(self, axis, lut):
        """
        Uploads a LUT for a specific axis (which can be applied by setLutApplied)

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS
        lut: 
            Json dumped LUT array with 512 integers

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setLut", [axis, lut])
        self.device.handleError(response)
        return 

    def setLutApplied(self, axis, apply):
        """
        Sets the apply rule for the given axis

        Parameters
        ----------
        axis: 
            Axis [0|1|2] of the IDS of which the apply rule should be set
        apply: 
            True for applying a LUT, False for disabling a LUT

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setLutApplied", [axis, apply])
        self.device.handleError(response)
        return 

    def setVelocityThresholds(self, velocityOn, velocityOff):
        """
        Sets the threshold velocity (in µm/s) for mode 2 of setDynamicNormalization. By default, the normalization in mode 2 is frozen for velocities below 5 µm/s and switched to dynamic mode for velocities above 10 µm/s.

        Parameters
        ----------
        velocityOn: 
            Velocity of the target in µm/s when to switch the normalization on (default: 10 µm/s)
        velocityOff: 
            Velocity of the target in µm/s when to switch the normalization off (default: 5 µm/s)

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setVelocityThresholds", [velocityOn, velocityOff])
        self.device.handleError(response)
        return 

