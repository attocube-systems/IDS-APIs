class Nlc:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.sen.nlc"

    def clearLut(self, axis):
        # type: (int) -> ()
        """
        Deactivates the LUT and removes it from the device for a specific measurement axis.

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".clearLut", [axis, ])
        self.device.handleError(response)
        return                 

    def createLut(self, axis):
        # type: (int) -> ()
        """
        Creates a new LUT for a specific measurement axis.

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".createLut", [axis, ])
        self.device.handleError(response)
        return                 

    def estimateNonlinearities(self, axis):
        # type: (int) -> ()
        """
        Estimates the nonlinearity error for the current device settings without changing or updating any settings.

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".estimateNonlinearities", [axis, ])
        self.device.handleError(response)
        return                 

    def getDynamicNormalization(self, axis):
        # type: (int) -> (int)
        """
        Returns the normalization mode of a specific measurement axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            mode: 0 = dynamic normalization (default)
1 = normalization frozen (for slow target drifts)
2 = normalization mode determined by target velocity
                    
        """
        
        response = self.device.request(self.interface_name + ".getDynamicNormalization", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getHistogram(self, axis):
        # type: (int) -> (str)
        """
        Returns a histogram of the measured nonlinearity errors obtained from the last call of the createLut or estimateNonlinearites functions.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            histogram: histogram array
                    
        """
        
        response = self.device.request(self.interface_name + ".getHistogram", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getLut(self, axis):
        # type: (int) -> (str)
        """
        Returns the LUT determined by the createLut function, which can be applied by the setLutApplied function.        Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: errNo
            lut: LUT array with 512 integers
                    
        """
        
        response = self.device.request(self.interface_name + ".getLut", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getLutApplied(self, axis):
        # type: (int) -> (bool)
        """
        Returns whether a LUT is applied or not for a specific measurement axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            apply: true = applied; false = disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getLutApplied", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getLutStatus(self, axis, ignoreFunctionError=True):
        # type: (int) -> (bool)
        """
        Reads out whether the LUT is available or not for a specific measurement axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            warningNo: warning code, can be converted into a string using the errorNumberToString function
            status: true if a LUT exists, else false
                    
        """
        
        response = self.device.request(self.interface_name + ".getLutStatus", [axis, ])
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1]                

    def getNonlinearityEstimation(self):
        # type: () -> (str)
        """
        Returns the LUT created by the estimateNonlinearities function (read-only mode) to compensate the nonlinearity error of the device for the current device settings. If no estimation was created an array of zeros is returned.        Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            lut: LUT array with 512 integers
                    
        """
        
        response = self.device.request(self.interface_name + ".getNonlinearityEstimation")
        self.device.handleError(response)
        return response[1]                

    def getRawLut(self, axis):
        # type: (int) -> (str)
        """
        Returns the raw LUT created by the createLut or estimateNonlinearites functions.        Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).            For debugging only.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            raw_lut: Json dumped lut array
                    
        """
        
        response = self.device.request(self.interface_name + ".getRawLut", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getVelocityThresholds(self):
        # type: () -> (int, int)
        """
        Returns the threshold velocities for mode 2 of the setDynamicNormalization function.
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            velocityOn: target velocity in µm/s (default: 10 µm/s)
            velocityOff: target velocity in µm/s (default: 5 µm/s)
                    
        """
        
        response = self.device.request(self.interface_name + ".getVelocityThresholds")
        self.device.handleError(response)
        return response[1], response[2]                

    def setDynamicNormalization(self, axis, mode):
        # type: (int, int) -> ()
        """
        Sets the normalization mode of a specific measurement axis.

        Parameters:
            axis: [0|1|2]
            mode: 0 = dynamic normalization 
1 = normalization frozen (for slow target drifts)
2 = automatic alternation between mode 0 and 1 depending on the target velocity
                    
        """
        
        response = self.device.request(self.interface_name + ".setDynamicNormalization", [axis, mode, ])
        self.device.handleError(response)
        return                 

    def setLut(self, axis, lut):
        # type: (int, str) -> ()
        """
        Uploads a LUT for a specific measurement axis, which can be applied by the setLutApplied function.

        Parameters:
            axis: [0|1|2]
            lut: LUT array with 512 integers
                    
        """
        
        response = self.device.request(self.interface_name + ".setLut", [axis, lut, ])
        self.device.handleError(response)
        return                 

    def setLutApplied(self, axis, apply):
        # type: (int, bool) -> ()
        """
        Applies the LUT for a specific measurement axis.

        Parameters:
            axis: [0|1|2]
            apply: true = apply LUT; false = disable LUT
                    
        """
        
        response = self.device.request(self.interface_name + ".setLutApplied", [axis, apply, ])
        self.device.handleError(response)
        return                 

    def setVelocityThresholds(self, velocityOn, velocityOff):
        # type: (int, int) -> ()
        """
        Sets the threshold velocities for mode 2 of the setDynamicNormalization function. By default, the normalization in mode 2 is frozen for velocities below 5 µm/s and switches to dynamic mode for velocities above 10 µm/s.

        Parameters:
            velocityOn: target velocity in µm/s (default: 10 µm/s)
            velocityOff: target velocity in µm/s (default: 5 µm/s)
                    
        """
        
        response = self.device.request(self.interface_name + ".setVelocityThresholds", [velocityOn, velocityOff, ])
        self.device.handleError(response)
        return                 

