class Axis:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.sen.axis"

    def getPassMode(self):
        # type: () -> (int)
        """
        Reads out the current pass mode.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_mode: mode 0 = single; pass 1 = dual pass
                    
        """
        
        response = self.device.request(self.interface_name + ".getPassMode")
        self.device.handleError(response)
        return response[1]                

    def setPassMode(self, mode):
        # type: (int) -> ()
        """
        Sets the desired pass mode.

        Parameters:
            mode: 0 = single pass; 1 = dual pass
                    
        """
        
        response = self.device.request(self.interface_name + ".setPassMode", [mode, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getMasterAxis(self):
        # type: () -> (int)
        """
        Returns the master axis (for more information, please refer to the device user manual).
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_axis: axis [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".getMasterAxis")
        self.device.handleError(response)
        return response[1]                

    def setMasterAxis(self, axis):
        # type: (int) -> ()
        """
        Sets the master axis (for more information, please refer to the device user manual).

        Parameters:
            axis: [0|1|2]
                    
        """
        
        response = self.device.request(self.interface_name + ".setMasterAxis", [axis, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def apply(self):
        # type: () -> ()
        """
        Applies new axis settings.
        """
        
        response = self.device.request(self.interface_name + ".apply")
        self.device.handleError(response)
        return                 

    def setAutoMasterAxis(self, automatic):
        # type: (bool) -> ()
        """
        Enables the automatic configuration of the master axis during measurement initialization.

        Parameters:
            automatic: true = automatic; false = manual
                    
        """
        
        response = self.device.request(self.interface_name + ".setAutoMasterAxis", [automatic, ])
        self.device.handleError(response)
        return                 

    def getAutoMasterAxis(self):
        # type: () -> (bool)
        """
        Gets status of the automatic configuration of the master axis.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_automatic: automatic true = automatic; false = manual (default: true)
                    
        """
        
        response = self.device.request(self.interface_name + ".getAutoMasterAxis")
        self.device.handleError(response)
        return response[1]                

    def discard(self):
        # type: () -> ()
        """
        Discards new axis settings.
        """
        
        response = self.device.request(self.interface_name + ".discard")
        self.device.handleError(response)
        return                 

