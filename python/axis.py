    
class Axis():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ids.axis"
            
    def apply(self):
        """
        Applies new axis settings. Necessary after JSON set commands.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "apply")
        self.device.handleError(response)
        return 

    def discard(self):
        """
        Discards new axis settings. Necessary after JSON set commands instead of apply() in case of failure.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "discard")
        self.device.handleError(response)
        return 

    def getMasterAxis(self):
        """
        Returns the master axis (for more information please refer to the IDS User Manual).
            ADD MORE INFO

        Parameters
        ----------

        Returns
        -------
        masteraxis: masteraxis Axis which is operating as masteraxis [0..2]
        """
        response = self.device.request(self.interface_name + "." + "getMasterAxis")
        self.device.handleError(response)
        return response['result'][1]

    def getPassMode(self):
        """
        Reads out the current pass mode.

        Parameters
        ----------

        Returns
        -------
        mode: mode 0 = single; pass 1 = dual pass
        """
        response = self.device.request(self.interface_name + "." + "getPassMode")
        self.device.handleError(response)
        return response['result'][1]

    def setMasterAxis(self, axis):
        """
        Sets the master axis (for more information please refer to the IDS User Manual).

        Parameters
        ----------
        axis:  Axis which is operating as masteraxis [0..2]

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setMasterAxis", [axis])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        return 

    def setPassMode(self, mode):
        """
        Sets the desired pass mode. Effectively this mode defines, if the correction factor of two (necessary for measurements in optical dual pass configuration) is applied.

        Parameters
        ----------
        mode:  0 = single pass; 1 = dual pass

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setPassMode", [mode])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        return 

