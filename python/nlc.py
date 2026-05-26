class Nlc:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.sen.nlc"

    def analyzeNonlinearities(self, axis):
        # type: (int) -> ()
        """
        Estimates the nonlinearities for the current measurement without modifying any settings. After applying a LUT, this function can be used to determine the effectiveness of the applied LUT. The error curve as a function of phase can be retrieved using getNonlinearityErrorCurveInPm(). The error list, for example for histogram evaluation, can be retrieved using getNonlinearityErrorListInPm(). If the estimation fails, for example due to an unstable measurement setup, the previously stored estimation results are not updated. In this case, subsequent calls to the corresponding get-functions return the last valid results.        This function is only available in the "measurement running" state. While analysis, the device state changes to "measurement starting" (please refer to the getCurrentMode function).

        Parameters:
            axis: [0|1|2]
                    
        """
        try:
            self.device.tcp.settimeout(20.0)
        
            response = self.device.request(self.interface_name + ".analyzeNonlinearities", [axis, ])
            self.device.handleError(response)
            return                 
        finally:
            self.device.tcp.settimeout(10)
        

    def clearAll(self, axis):
        # type: (int) -> ()
        """
        Deactivates the active LUT and clears all associated data created by createLut() and analyzeNonlinearities(), including the cached results returned by getLutInPm(), getNonlinearityErrorCurveInPm(), getNonlinearityErrorCurvesInPm(), and getNonlinearityErrorListInPm().

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".clearAll", [axis, ])
        self.device.handleError(response)
        return                 

    def createLut(self, axis):
        # type: (int) -> ()
        """
        Estimates the nonlinearities for a specific measurement axis and creates a new LUT based on the result. The initial nonlinearities can be analyzed using getNonlinearityErrorListInPm(). The generated LUT can be applied with setLutApplied() and retrieved with getLutInPm(). After applying a LUT, this function can be called again for further optimization. The newly generated LUT is then combined with the existing LUT. If the estimation fails, for example due to an unstable measurement setup, the previously stored LUT results are not updated. In this case, subsequent calls to the corresponding get-functions return the last valid results.        This function is only available in the "measurement running" state. While the LUT is being created, the device state changes to "measurement starting" (please refer to the getCurrentMode function).

        Parameters:
            axis: [0|1|2]
                    
        """
        try:
            self.device.tcp.settimeout(20.0)
        
            response = self.device.request(self.interface_name + ".createLut", [axis, ])
            self.device.handleError(response)
            return                 
        finally:
            self.device.tcp.settimeout(10)
        

    def getAnalysisStatus(self, axis, ignoreFunctionError=True):
        # type: (int) -> (bool)
        """
        Reads out whether the analysis of nonlinearities was performed or not for a specific measurement axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            warningNo: warning code, can be converted into a string using the errorNumberToString function
            status: true if analysis data is available, else false
                    
        """
        
        response = self.device.request(self.interface_name + ".getAnalysisStatus", [axis, ])
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1]                

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

    def getLutDuringInit(self):
        # type: () -> (bool)
        """
        Reads out the current configuration of the LUT creation during the measurement initialization.
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            enabled: true for create LUT during measurement initialization, else false
                    
        """
        
        response = self.device.request(self.interface_name + ".getLutDuringInit")
        self.device.handleError(response)
        return response[1]                

    def getLutInPm(self, axis):
        # type: (int) -> (str)
        """
        This function returns the LUT after calling the createLut() function. If no estimation has been performed, the function returns an error.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            lut: JSON-encoded string containing an array of 512 integer values representing the LUT
                    
        """
        
        response = self.device.request(self.interface_name + ".getLutInPm", [axis, ])
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

    def getNonlinearityErrorCurveInPm(self, axis):
        # type: (int) -> (str)
        """
        Returns a string containing a serialized list of the residual nonlinearities in pm for the current measurement. The returned values represent the median nonlinearity error curve within one interferometric fringe and are based on the most recent successful result of analyzeNonlinearities(). If no estimation has been performed, the function returns an error. The returned values are only updated after a successful call to analyzeNonlinearities().        Use createLUT() followed by setLutApplied() for nonlinearity compensation.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            curve: JSON-encoded string containing an array of 512 integer values representing the error curve
                    
        """
        
        response = self.device.request(self.interface_name + ".getNonlinearityErrorCurveInPm", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getNonlinearityErrorCurvesInPm(self, axis):
        # type: (int) -> (str)
        """
        Returns a string containing a serialized matrix of nonlinearity error curves in pm for the current measurement. The returned values are based on the most recent successful estimation performed by createLut() or analyzeNonlinearities(). Each row represents the nonlinearity error curve of one measured interferometric fringe. If no estimation has been performed, the function returns an error.        For the median nonlinearity error curve or static LUT calculated from these individual fringes, use getNonlinearityErrorCurveInPm() or getLutInPm(), respectively.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            curves: JSON-encoded string containing a 2-dimensional array representing multiple error curves
                    
        """
        
        response = self.device.request(self.interface_name + ".getNonlinearityErrorCurvesInPm", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getNonlinearityErrorListInPm(self, axis):
        # type: (int) -> (str)
        """
        Returns a string containing a serialized list of the measured nonlinearities in pm for the current measurement. The returned data represents peak-to-peak values of the single fringes based on the most recent successful estimation performed by createLut() or analyzeNonlinearities(). It can be visualized as a histogram to analyze the distribution and magnitude of the residual nonlinearities. If no estimation has been performed, the function returns an error.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            histogram: JSON-encoded string containing a list of the nonlinearity residuals
                    
        """
        
        response = self.device.request(self.interface_name + ".getNonlinearityErrorListInPm", [axis, ])
        self.device.handleError(response)
        return response[1]                

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

    def setLutDuringInit(self, enabled):
        # type: (bool) -> ()
        """
        Enables or disables the creation of the LUT during measurement initialization.

        Parameters:
            enabled: true for create LUT during measurement initialization, else false
                    
        """
        
        response = self.device.request(self.interface_name + ".setLutDuringInit", [enabled, ])
        self.device.handleError(response)
        return                 

    def setLutInPm(self, axis, lut):
        # type: (int, str) -> ()
        """
        Uploads a LUT for a specific measurement axis, which can be applied by the setLutApplied() function.

        Parameters:
            axis: [0|1|2]
            lut: JSON-encoded string containing an array of 512 integer values representing the LUT
                    
        """
        
        response = self.device.request(self.interface_name + ".setLutInPm", [axis, lut, ])
        self.device.handleError(response)
        return                 

