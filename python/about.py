class About:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.system.about"

    def getInstalledPackages(self):
        # type: () -> (str)
        """
        Get list of packages installed on the device.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_string: string: comma separated list of packages
                    
        """
        
        response = self.device.request(self.interface_name + ".getInstalledPackages")
        self.device.handleError(response)
        return response[1]                

    def getPackageLicense(self, pckg):
        # type: (str) -> (str)
        """
        Get the license for a specific package.

        Parameters:
            pckg: string: Package name
                    
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_string: string: license for this package
                    
        """
        
        response = self.device.request(self.interface_name + ".getPackageLicense", [pckg, ])
        self.device.handleError(response)
        return response[1]                

