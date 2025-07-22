class Manual:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ecu.manual"

    def getHumidityInPercent(self, axis):
        # type: (int) -> (float)
        """
        Reads out the manually configured humidity for compensation mode 1.

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            humidity: value in percent
                    
        """
        
        response = self.device.request(self.interface_name + ".getHumidityInPercent", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getPressureInHPa(self, axis):
        # type: (int) -> (float)
        """
        Reads out the manually configured air pressure for compensation mode 1.

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            pressure: value in hPa
                    
        """
        
        response = self.device.request(self.interface_name + ".getPressureInHPa", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getRefractiveIndex(self, axis):
        # type: (int) -> (float)
        """
        Reads out the manually configured refractive index for compensation mode 2.

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            rindex: refractive index
                    
        """
        
        response = self.device.request(self.interface_name + ".getRefractiveIndex", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def getTemperatureInDegrees(self, axis):
        # type: (int) -> (float)
        """
        Reads out the manually configured temperature for compensation mode 1.

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
                    
        Returns:
            errNo: error code, if there was an error, otherwise 0 for ok
            temperature: value in degrees Celsius
                    
        """
        
        response = self.device.request(self.interface_name + ".getTemperatureInDegrees", [axis, ])
        self.device.handleError(response)
        return response[1]                

    def setHumidityInPercent(self, axis, humidity):
        # type: (int, float) -> ()
        """
        Sets the manually configured humidity for compensation mode 1. The input range is defined to 0 to 100 % (valid range for the Ciddor Equation).

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
            humidity: value from 0 % to 100 %
                    
        """
        
        response = self.device.request(self.interface_name + ".setHumidityInPercent", [axis, humidity, ])
        self.device.handleError(response)
        return                 

    def setPressureInHPa(self, axis, pressure):
        # type: (int, float) -> ()
        """
        Sets the manually configured air pressure for compensation mode 1. The input range is defined to 800 to 1200 hPa (valid range for the Ciddor Equation).

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
            pressure: value from 800 hPa to 1200 hPa
                    
        """
        
        response = self.device.request(self.interface_name + ".setPressureInHPa", [axis, pressure, ])
        self.device.handleError(response)
        return                 

    def setRefractiveIndex(self, axis, rindex):
        # type: (int, float) -> ()
        """
        Sets the manually configured refractive index for the compensation mode 2. The input range is defined to be greater than 1.

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
            rindex: refractive index
                    
        """
        
        response = self.device.request(self.interface_name + ".setRefractiveIndex", [axis, rindex, ])
        self.device.handleError(response)
        return                 

    def setTemperatureInDegrees(self, axis, temperature):
        # type: (int, float) -> ()
        """
        Sets the manually configured temperature for compensation mode 1. The input range is defined to -40 to +100 °C (valid range for the Ciddor Equation).

        Parameters:
            axis: [0|1|2]
Parameter has to be -1 for the moment,
individual axes will be supported in the next firmware release
            temperature: value from -40 °C to +100 °C
                    
        """
        
        response = self.device.request(self.interface_name + ".setTemperatureInDegrees", [axis, temperature, ])
        self.device.handleError(response)
        return                 

