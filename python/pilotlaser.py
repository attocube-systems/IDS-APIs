    
class Pilotlaser():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ids.pilotlaser"
            
    def disable(self):
        """
        Disables the pilot laser.

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
        Enables the pilot laser.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "enable")
        self.device.handleError(response)
        return 

    def getEnabled(self):
        """
        Reads out whether the pilot laser is enabled or not.

        Parameters
        ----------

        Returns
        -------
        enable: enable true = enabled; false = disabled
        """
        response = self.device.request(self.interface_name + "." + "getEnabled")
        self.device.handleError(response)
        return response['result'][1]

