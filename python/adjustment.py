    
class Adjustment():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ids.adjustment"
            
    def getAdjustmentEnabled(self):
        """
        This function can be used to see if the adjustment is running

        Parameters
        ----------

        Returns
        -------
        enable: enable true = enabled; false = disabled
        """
        response = self.device.request(self.interface_name + "." + "getAdjustmentEnabled")
        self.device.handleError(response)
        return response['result'][1]

    def getContrastInPermille(self, axis, ignoreFunctionError=True):
        """
        This function can be used to monitor the alignment contrast (peak-to-peak of the 
           basic interference signal amplitude) and the basline (its offset) during alignment 
           mode. It is used to monitor and optimize the optical alignment such that it allows the 
           successful initialization of a measurement. To monitor the optical contrast during a 
           running measurement, please use the getAxisSignalQuality function.
           
           Important: The baseline and contrast needs to be added, otherwise an overload can 
           occure without being recognized. Example: baseline 15permille and contrast 850permille. Just 
           from the contrast it looks good. Adding the baseline the overload is visible.

        Parameters
        ----------
        axis:  Axis to get the value from [0..2]
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        contast: contast Contrast of the base band signal in permille
        baseline: baseline Offset of the contrast measurement in permille
        mixcontrast: mixcontrast lower contrast measurment when measuring a mix contrast (indicated by error code)
        """
        response = self.device.request(self.interface_name + "." + "getContrastInPermille", [axis])
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1], response['result'][2], response['result'][3]

