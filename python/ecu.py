    
class Ecu():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ecu"
            
    def disable(self):
        """
        Disables the ECU interface.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "disable")
        self.device.handleError(response)
        return 

    def enable(self):
        """
        Enables the ECU interface.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "enable")
        self.device.handleError(response)
        return 

    def getConnected(self):
        """
        Reads out whether the ECU interface is physically connected or not. Checking if the ECU is connected can only be done on an enabled ECU interface.

        Parameters
        ----------

        Returns
        -------
        connected: boolean
            true if connected, false if not
        """
        response = self.device.request(self.interface_name + "." + "getConnected")
        self.device.handleError(response)
        return response['result'][1]

    def getEnabled(self):
        """
        Reads out whether the ECU interface is enabled or not. Enabling the ECU interface is crucial for working with the ECU.

        Parameters
        ----------

        Returns
        -------
        enabled: boolean
            true if enabled, false if not
        """
        response = self.device.request(self.interface_name + "." + "getEnabled")
        self.device.handleError(response)
        return response['result'][1]

    def getHumidityInPercent(self):
        """
        Reads out the ECU measured air humidity in percent.

        Parameters
        ----------

        Returns
        -------
        humidity: double
            humidity in %
        """
        response = self.device.request(self.interface_name + "." + "getHumidityInPercent")
        self.device.handleError(response)
        return response['result'][1]

    def getPressureInHPa(self):
        """
        Reads out the ECU measured air pressure in hPa.

        Parameters
        ----------

        Returns
        -------
        pressure: double
            pressure in hPa
        """
        response = self.device.request(self.interface_name + "." + "getPressureInHPa")
        self.device.handleError(response)
        return response['result'][1]

    def getRefractiveIndex(self):
        """
        Reads out the ECU estimated refractive index for the current
        ECU readings. To get the refractive index for other modes, please see
        getRefractiveIndexForCompensation.

        Parameters
        ----------

        Returns
        -------
        rIndex: double
            refractive index
        """
        response = self.device.request(self.interface_name + "." + "getRefractiveIndex")
        self.device.handleError(response)
        return response['result'][1]

    def getRefractiveIndexCompensationMode(self, axis):
        """
        Reads out the compensation mode (see below) which is currently used for the environmental compensation.

        Parameters
        ----------
        axis: 
            Axis to get the mode for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release

        Returns
        -------
        mode: int32
            mode see defintion in set function
        """
        response = self.device.request(self.interface_name + "." + "getRefractiveIndexCompensationMode", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getRefractiveIndexForCompensation(self, axis):
        """
        Reads out the refractive index used according to the current environmental compensation mode for this axis.

        Parameters
        ----------
        axis: 
            Axis to get the refractive index for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release

        Returns
        -------
        rIndex: double
            refractive index
        """
        response = self.device.request(self.interface_name + "." + "getRefractiveIndexForCompensation", [axis])
        self.device.handleError(response)
        return response['result'][1]

    def getTemperatureInDegrees(self):
        """
        Reads out the ECU measured air temperature in degrees Celsius.

        Parameters
        ----------

        Returns
        -------
        temperature: double
            temperature in degrees C
        """
        response = self.device.request(self.interface_name + "." + "getTemperatureInDegrees")
        self.device.handleError(response)
        return response['result'][1]

    def setRefractiveIndexCompensationMode(self, axis, mode):
        """
        Sets the refractive index mode.

        Parameters
        ----------
        axis: 
            Axis to set the mode for.
            Parameter has to be -1 for the moment,
            individual axes will be supported in the next firmware release
        mode: 
            mode can be 0 for direct ECU mode, 1 to take the manual values and calculate the refractive index from this or 2 to directly take the set refrative index

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRefractiveIndexCompensationMode", [axis, mode])
        self.device.handleError(response)
        return 

