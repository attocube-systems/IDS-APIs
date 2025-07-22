class Adjustment:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.sen.adjustment"

    def getContrastInPermille(self, axis, ignoreFunctionError=True):
        # type: (int) -> (int, int, int)
        """
        This function can be used to monitor the alignment contrast (peak-to-peak of the basic interference signal amplitude) and the baseline (its offset) during alignment mode.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
            value_contrast: contrast contrast of the base band signal in permille
            value_baseline: baseline offset of the contrast measurement in permille
            value_mixcontrast: mixcontrast lower contrast measurement when measuring a mixed contrast (indicated by error code)
                    
        """
        
        response = self.device.request(self.interface_name + ".getContrastInPermille", [axis, ])
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1], response[2], response[3]                

    def getAdjustmentEnabled(self):
        # type: () -> (bool)
        """
        This function can be used to see if the adjustment is running.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_enabled: enabled true = enabled; false = disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getAdjustmentEnabled")
        self.device.handleError(response)
        return response[1]                

