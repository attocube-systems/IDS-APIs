class Ecu:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ecu"

    def disable(self):
        # type: () -> ()
        """
        Disables the ECU interface.
        """
        
        response = self.device.request(self.interface_name + ".disable")
        self.device.handleError(response)
        return                 

    def enable(self):
        # type: () -> ()
        """
        Enables the ECU interface.
        """
        
        response = self.device.request(self.interface_name + ".enable")
        self.device.handleError(response)
        return                 

    def getConnected(self):
        # type: () -> (bool)
        """
        Reads out whether the ECU interface is physically connected or not. Checking if the ECU is connected can only be done on an enabled ECU interface.
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            connected: true = connected; false = disconnected
                    
        """
        
        response = self.device.request(self.interface_name + ".getConnected")
        self.device.handleError(response)
        return response[1]                

    def getEnabled(self):
        # type: () -> (bool)
        """
        Reads out whether the ECU interface is enabled or not. Enabling the ECU interface is crucial for working with the ECU.
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            enabled: true = enabled; false = disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getEnabled")
        self.device.handleError(response)
        return response[1]                

    def getHumidityInPercent(self):
        # type: () -> (float)
        """
        Reads out the ECU measured air humidity in percent.
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            humidity: value in percent
                    
        """
        
        response = self.device.request(self.interface_name + ".getHumidityInPercent")
        self.device.handleError(response)
        return response[1]                

    def getPressureInHPa(self):
        # type: () -> (float)
        """
        Reads out the ECU measured air pressure in hPa.
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            pressure: value in hPa
                    
        """
        
        response = self.device.request(self.interface_name + ".getPressureInHPa")
        self.device.handleError(response)
        return response[1]                

    def getRefractiveIndex(self):
        # type: () -> (float)
        """
        Reads out the ECU estimated refractive index from the current ECU values. To get the refractive index for other compensation modes, please refer to the getRefractiveIndexForCompensation function.
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            rIndex: refractive index
                    
        """
        
        response = self.device.request(self.interface_name + ".getRefractiveIndex")
        self.device.handleError(response)
        return response[1]                

    def getRefractiveIndexCompensationMode(self, axis):
        # type: (int) -> (int)
        """
        Reads out the compensation mode which is currently used for the environmental compensation.

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            mode: 0 = direct ECU mode 
1 = uses refractive index calculated from the manually set values
2 = uses manually set refrative index
                    
        """
        
        response = self.device.request(self.interface_name + ".getRefractiveIndexCompensationMode", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getRefractiveIndexForCompensation(self, axis):
        # type: (int) -> (float)
        """
        Reads out the refractive index used according to the current environmental compensation mode for a specific measurement axis.

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            rIndex: refractive index
                    
        """
        
        response = self.device.request(self.interface_name + ".getRefractiveIndexForCompensation", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getTemperatureInDegrees(self):
        # type: () -> (float)
        """
        Reads out the ECU measured air temperature in degrees Celsius.
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            temperature: value in degrees Celsius
                    
        """
        
        response = self.device.request(self.interface_name + ".getTemperatureInDegrees")
        self.device.handleError(response)
        return response[1]                

    def setRefractiveIndexCompensationMode(self, axis, mode):
        # type: (int, int) -> ()
        """
        Sets the refractive index compensation mode.

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
            mode: 0 = direct ECU mode 
1 = uses refractive index calculated from the manually set values
2 = uses manually set refrative index
                    
        """
        
        response = self.device.request(self.interface_name + ".setRefractiveIndexCompensationMode", [axis, mode, ])
        self.device.handleError(response)
        return                 

