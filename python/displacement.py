class Displacement:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.sen.displacement"

    def getMeasurementEnabled(self):
        # type: () -> (bool)
        """
        This function can be used to see if the measurement is running.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_enabled: enabled true = enabled; false = disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getMeasurementEnabled")
        self.device.handleError(response)
        return response[1]                

    def getAverageN(self):
        # type: () -> (int)
        """
        Reads out the averaging (lowpass) parameter N.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_averageN: averageN value from 0 to 24
                    
        """
        
        response = self.device.request(self.interface_name + ".getAverageN")
        self.device.handleError(response)
        return response[1]                

    def setAverageN(self, averageN):
        # type: (int) -> ()
        """
        Sets the averaging (lowpass) parameter N.

        Parameters:
            averageN: value from 0 to 24
                    
        """
        
        response = self.device.request(self.interface_name + ".setAverageN", [averageN, ])
        self.device.handleError(response)
        return                 

    def getAxisSignalQuality(self, axis, ignoreFunctionError=True):
        # type: (int) -> (int, int)
        """
        This function can be used to monitor the signal contrast (peak-to-peak of the basic interference signal amplitude) and the baseline (its offset) during a running measurement.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
            value_contrast: contrast contrast of the base band signal in permille
            value_baseline: baseline offset of the contrast measurement in permille
                    
        """
        
        response = self.device.request(self.interface_name + ".getAxisSignalQuality", [axis, ])
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1], response[2]                

    def getReferencePosition(self, axis, ignoreFunctionError=True):
        # type: (int) -> (float)
        """
        Reads out the reference position value of the specific measurement axis./nThe reference position information is estimated at the measurement initialization procedure or on reset position.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
            value_position: position reference position of the axis in pm
                    
        """
        
        response = self.device.request(self.interface_name + ".getReferencePosition", [axis, ])
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1]                

    def getReferencePositions(self, ignoreFunctionError=True):
        # type: () -> (float, float, float)
        """
        Reads out the reference position value of all three measurement axes.
        Returns:
            value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
            value_position1: position0 reference position of the axis 0 in pm
            value_position2: position1 reference position of the axis 1 in pm
            value_position3: position2 reference position of the axis 2 in pm
                    
        """
        
        response = self.device.request(self.interface_name + ".getReferencePositions")
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1], response[2], response[3]                

    def getAbsolutePosition(self, axis, ignoreFunctionError=True):
        # type: (int) -> (float)
        """
        This function outputs the sum of the static absolute position register value and the continuously updated displacement register value for a specific measurement axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
            value_position: position absolute position of the axis in pm
                    
        """
        
        response = self.device.request(self.interface_name + ".getAbsolutePosition", [axis, ])
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1]                

    def getAbsolutePositions(self, ignoreFunctionError=True):
        # type: () -> (float, float, float)
        """
        This function outputs the sum of the static absolute position register value and the continuously updated displacement register value for all three measurement axes.
        Returns:
            value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
            value_position1: position0 absolute position of the axis 0 in pm
            value_position2: position1 absolute position of the axis 1 in pm
            value_position3: position2 absolute position of the axis 2 in pm
                    
        """
        
        response = self.device.request(self.interface_name + ".getAbsolutePositions")
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1], response[2], response[3]                

    def getAxisDisplacement(self, axis, ignoreFunctionError=True):
        # type: (int) -> (float)
        """
        Reads out the displacement value of a specific measurement axis.

        Parameters:
            axis: [0|1|2]
                    
        Returns:
            value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
            value_displacement: displacement displacement of the axis in pm
                    
        """
        
        response = self.device.request(self.interface_name + ".getAxisDisplacement", [axis, ])
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1]                

    def getAxesDisplacement(self, ignoreFunctionError=True):
        # type: () -> (float, float, float)
        """
        Reads out the displacement values of all three measurement axes.
        Returns:
            value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
            value_displacement1: displacement0 displacement of the axis 0 in pm
            value_displacement2: displacement1 displacement of the axis 1 in pm
            value_displacement3: displacement2 displacement of the axis 2 in pm
                    
        """
        
        response = self.device.request(self.interface_name + ".getAxesDisplacement")
        self.device.handleError(response, ignoreFunctionError)
        return response[0], response[1], response[2], response[3]                

