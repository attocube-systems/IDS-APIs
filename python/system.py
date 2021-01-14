    
class System():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ids.system"
            
    def getCurrentMode(self):
        """
        Reads out the current IDS system state.

        Parameters
        ----------

        Returns
        -------
        mode: mode Values: "system idle", "measurement starting", "measurement running", "optics alignment starting", "optics alignment running", "test channels enabled"
        """
        response = self.device.request(self.interface_name + "." + "getCurrentMode")
        self.device.handleError(response)
        return response['result'][1]

    def getDeviceType(self):
        """
        Reads out the IDS device type. For differences between the device types please refer to the IDS User Manual.

        Parameters
        ----------

        Returns
        -------
        type: type Type of IDS (e.g. "IDS3010")
        """
        response = self.device.request(self.interface_name + "." + "getDeviceType")
        self.device.handleError(response)
        return response['result'][1]

    def getFeaturesName(self, featurenumber):
        """
        Converts the IDS feature number to its corresponding name.

        Parameters
        ----------
        featurenumber:  Number of feature

        Returns
        -------
        names: names The name of the corresponding feature
        """
        response = self.device.request(self.interface_name + "." + "getFeaturesName", [featurenumber])
        self.device.handleError(response)
        return response['result'][1]

    def getFpgaVersion(self):
        """
        Reads out the IDS FPGA version.

        Parameters
        ----------

        Returns
        -------
        version: version Version in the form X.Y.Z
        """
        response = self.device.request(self.interface_name + "." + "getFpgaVersion")
        self.device.handleError(response)
        return response['result'][1]

    def getInitMode(self):
        """
        Returns the Initialization mode.

        Parameters
        ----------

        Returns
        -------
        mode: mode 0 = High Accuracy Initialization; 1 = Quick Initialization
        """
        response = self.device.request(self.interface_name + "." + "getInitMode")
        self.device.handleError(response)
        return response['result'][1]

    def getNbrFeaturesActivated(self):
        """
        Reads out the amount of activated features activated on the IDS.

        Parameters
        ----------

        Returns
        -------
        nbr: nbr Gives the number of activated features.
        """
        response = self.device.request(self.interface_name + "." + "getNbrFeaturesActivated")
        self.device.handleError(response)
        return response['result'][1]

    def getSystemError(self):
        """
        Reads out the system error. The function returns an integer number which represents 
           the error. The number can be converted into a string using the errorNumberToString 
           function, which is described below.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "getSystemError")
        self.device.handleError(response)
        return 

    def resetAxes(self):
        """
        Resets the position value of all measurement axes to zero.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "resetAxes")
        self.device.handleError(response)
        return 

    def resetAxis(self, axis):
        """
        Resets the position value of a specific measurement axis to zero.

        Parameters
        ----------
        axis:  [0|1|2]

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "resetAxis", [axis])
        self.device.handleError(response)
        return 

    def resetError(self, perform):
        """
        Resets a measurement error that can have occurred with the aim to continue the interrupted measurement. It is configurable if an additional renormalization process (please refer to the IDS User Manual) should be performed or not.
           
           This function can be used for two concerns:
           1.	FALSE: This function only clears displacement errors (e.g. after a beam interruption) of all three axes, while the displacement measurement is running.
           2.	TRUE: This function can be utilized to normalize the Lissajous-Figure of all three optical axes during the running displacement measurement by sweeping the laser temperature and to clear all displacement errors. This normalization process takes around 14-20 seconds. This function can be used, for example, in two main applications:
           A.	The alignment contrast decreases due to the angular change of the target and/or sensor head without any displacements (see Figure 45). Using this function, the Lissajous-Figure of each measurement axis gets normalized and high-resolution measurements are guaranteed.
           B.	After changing the optical components as, for example, the retro reflector this function can be used to normalize the Lissajous-Figure after completely losing the signal (see Figure 46).
           Attention: Depending on the Boolean input parameter performRenormalisation, it can be decided, if the renormalization process should be executed or skipped. If it is executed, the IDS system needs around 14-20 seconds to get back to the measurement mode. It is also important to comment that the recommended action after an error is to stop and to restart the displacement measurement. Moreover, losing displacement values due to an occurred error the internal absolute position can be different to the real absolute position and this can could result in dynamic movement errors or a wrong ECU compensation during long-term displacement measurements.

        Parameters
        ----------
        perform:  renormalization

        Returns
        -------
        """
        self.device.tcp.settimeout(20.0)
        response = self.device.request(self.interface_name + "." + "resetError", [perform])
        self.device.tcp.settimeout(10)
        self.device.handleError(response)
        return 

    def setInitMode(self, mode):
        """
        Sets the mode for the initialization procedure that is performed when starting a measurement.

        Parameters
        ----------
        mode:  0 = High Accuracy Initialization; 1 = Quick Initialization

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setInitMode", [mode])
        self.device.handleError(response)
        return 

    def startMeasurement(self):
        """
        Starts the displacement measurement system state.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "startMeasurement")
        self.device.handleError(response)
        return 

    def startOpticsAlignment(self):
        """
        Starts the optical alignment system state.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "startOpticsAlignment")
        self.device.handleError(response)
        return 

    def stopMeasurement(self):
        """
        Stops the displacement measurement system state.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "stopMeasurement")
        self.device.handleError(response)
        return 

    def stopOpticsAlignment(self):
        """
        Stops the optical alignment system state.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "stopOpticsAlignment")
        self.device.handleError(response)
        return 

