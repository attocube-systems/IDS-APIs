class System:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.sen.system"

    def stopMeasurement(self):
        # type: () -> ()
        """
        Stops the measurement system state.
        """
        
        response = self.device.request(self.interface_name + ".stopMeasurement")
        self.device.handleError(response)
        return                 

    def startMeasurement(self):
        # type: () -> ()
        """
        Starts the measurement system state./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function)
        """
        
        response = self.device.request(self.interface_name + ".startMeasurement")
        self.device.handleError(response)
        return                 

    def restartMeasurement(self):
        # type: () -> ()
        """
        Restarts the absolute measurement system state./nThis function is only available in the "measurement running" state (please refer to the getCurrentMode function).
        """
        
        response = self.device.request(self.interface_name + ".restartMeasurement")
        self.device.handleError(response)
        return                 

    def getAutoRestart(self):
        # type: () -> (bool)
        """
        Gets the current configuration of the automatic measurement restart after reboot.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_enabled: enabled true = enabled; false = disabled (default: true)
                    
        """
        
        response = self.device.request(self.interface_name + ".getAutoRestart")
        self.device.handleError(response)
        return response[1]                

    def setAutoRestart(self, enable):
        # type: (bool) -> ()
        """
        Enables or disables the automatic measurement restart after reboot.

        Parameters:
            enable: true = enable; false = disable
                    
        """
        
        response = self.device.request(self.interface_name + ".setAutoRestart", [enable, ])
        self.device.handleError(response)
        return                 

    def startOpticsAlignment(self):
        # type: () -> ()
        """
        Starts the optical alignment system state./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function).
        """
        
        response = self.device.request(self.interface_name + ".startOpticsAlignment")
        self.device.handleError(response)
        return                 

    def stopOpticsAlignment(self):
        # type: () -> ()
        """
        Stops the optical alignment system state./nThis function is only available in the "optics alignment running" state (please refer to the getCurrentMode function).
        """
        
        response = self.device.request(self.interface_name + ".stopOpticsAlignment")
        self.device.handleError(response)
        return                 

    def resetAxes(self):
        # type: () -> ()
        """
        Resets the displacement value of all measurement axes to zero.
        """
        
        response = self.device.request(self.interface_name + ".resetAxes")
        self.device.handleError(response)
        return                 

    def resetAxis(self, axis):
        # type: (int) -> ()
        """
        Resets the displacement value of a specific measurement axis to zero.

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".resetAxis", [axis, ])
        self.device.handleError(response)
        return                 

    def resetError(self, performRenormalization):
        # type: (bool) -> ()
        """
        Resets a measurement error that has been raised with the aim to continue the interrupted measurement./nIt is configurable if an additional renormalization process (please refer to the IDS User Manual) should be performed or not./n  This function can be used in two cases:/n 	1.

        Parameters:
            performRenormalization: true = enable; false = disable
                    
        """
        try:
            self.device.tcp.settimeout(20.0)
        
            response = self.device.request(self.interface_name + ".resetError", [performRenormalization, ])
            self.device.handleError(response)
            return                 
        finally:
            self.device.tcp.settimeout(10)
        

    def getCurrentMode(self):
        # type: () -> (str)
        """
        Reads out the current device system state.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_mode: mode "system idle", "measurement starting", "measurement running", "measurement restarting",/n"optics alignment starting", "optics alignment running", "test channels enabled"
                    
        """
        
        response = self.device.request(self.interface_name + ".getCurrentMode")
        self.device.handleError(response)
        return response[1]                

    def getFpgaVersion(self):
        # type: () -> (str)
        """
        Reads out the device FPGA version.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_version: version version in the form X.Y.Z
                    
        """
        
        response = self.device.request(self.interface_name + ".getFpgaVersion")
        self.device.handleError(response)
        return response[1]                

    def getDeviceType(self):
        # type: () -> (str)
        """
        Reads out the device type.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_type: type type of the device (e.g. "IDS3010")
                    
        """
        
        response = self.device.request(self.interface_name + ".getDeviceType")
        self.device.handleError(response)
        return response[1]                

    def getSystemError(self):
        # type: () -> ()
        """
        Reads out the system error.
        """
        
        response = self.device.request(self.interface_name + ".getSystemError")
        self.device.handleError(response)
        return                 

    def getNbrFeaturesActivated(self):
        # type: () -> (int)
        """
        Reads out the number of the activated features on the device.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_nbr: nbr the number of activated features
                    
        """
        
        response = self.device.request(self.interface_name + ".getNbrFeaturesActivated")
        self.device.handleError(response)
        return response[1]                

    def getFeaturesName(self, featurenumber):
        # type: (int) -> (str)
        """
        Converts the device feature number to its corresponding name.

        Parameters:
            featurenumber: number of features
                    
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_names: names name of the corresponding feature
                    
        """
        
        response = self.device.request(self.interface_name + ".getFeaturesName", [featurenumber, ])
        self.device.handleError(response)
        return response[1]                

    def setOptimizeParametersDuringInit(self, enableFineTuning):
        # type: (bool) -> ()
        """
        Enables or disables the parameter optimization used for the automatic system compensation.

        Parameters:
            enableFineTuning: true = enable; false = disable
                    
        """
        
        response = self.device.request(self.interface_name + ".setOptimizeParametersDuringInit", [enableFineTuning, ])
        self.device.handleError(response)
        return                 

    def getOptimizeParametersDuringInit(self):
        # type: () -> (bool)
        """
        Reads out the current parameter optimization configuration used for the automatic system compensation.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_enableFineTuning: enableFineTuning true = enable; false = disable
                    
        """
        
        response = self.device.request(self.interface_name + ".getOptimizeParametersDuringInit")
        self.device.handleError(response)
        return response[1]                

    def getInitMode(self):
        # type: () -> (int)
        """
        Returns the initialization mode.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_mode: mode 0 = High Accuracy Initialization; 1 = Quick Initialization (default: 0)
                    
        """
        
        response = self.device.request(self.interface_name + ".getInitMode")
        self.device.handleError(response)
        return response[1]                

    def setInitMode(self, mode):
        # type: (int) -> ()
        """
        Sets the mode for the initialization procedure that is performed when starting a measurement.

        Parameters:
            mode: 0 = High Accuracy Initialization; 1 = Quick Initialization
                    
        """
        
        response = self.device.request(self.interface_name + ".setInitMode", [mode, ])
        self.device.handleError(response)
        return                 

    def setErrorParameterSet(self, setnumber):
        # type: (int) -> ()
        """
        Sets the error parameter set.

        Parameters:
            setnumber: 1 = default mode: standard beam interruption detection (less sensitive)/n2 = strict mode: more sensitive beam interruption detection; improves responsiveness but may increase false positives
                    
        """
        
        response = self.device.request(self.interface_name + ".setErrorParameterSet", [setnumber, ])
        self.device.handleError(response)
        return                 

    def getErrorParameterSet(self):
        # type: () -> (int)
        """
        Gets the applied error parameter set.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_setnumber: setnumber 1 = New defaults from 2.0.0: more senstive beam interrupt detection/n2 = Old defaults till 1.9.3: less senstive beam interrupt detection (legacy version)
                    
        """
        
        response = self.device.request(self.interface_name + ".getErrorParameterSet")
        self.device.handleError(response)
        return response[1]                

