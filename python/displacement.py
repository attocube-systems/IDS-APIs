    
class Displacement():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ids.displacement"
            
    def getAbsolutePosition(self, axis, ignoreFunctionError=True):
        """
        The absolute position information is estimated at the measurement initialization procedure. 
           This initial absolute position information is not updated during system 
           operation, whereas the IDS continuously measures the relative displacement from 
           that point. This function outputs the sum of the static absolute position register value 
           and the continuously updated displacement register value for a single axis.

        Parameters
        ----------
        axis:  [0|1|2]
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        position: position position of the axis in pm
        """
        response = self.device.request(self.interface_name + "." + "getAbsolutePosition", [axis])
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1]

    def getAbsolutePositions(self, ignoreFunctionError=True):
        """
        The absolute position information is estimated at the measurement initialization 
           procedure. This initial absolute position information is not updated during system 
           operation, whereas the IDS continuously measures the relative displacement from 
           that point. This function outputs the sum of the static absolute position register value 
           and the continuously updated displacement register value for all three axes.

        Parameters
        ----------
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        position0: position0 position of the axis 0 in pm
        position1: position1 position of the axis 1 in pm
        position2: position2 position of the axis 2 in pm
        """
        response = self.device.request(self.interface_name + "." + "getAbsolutePositions")
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1], response['result'][2], response['result'][3]

    def getAverageN(self):
        """
        Reads-out the averaging (lowpass) parameter N. The averaging time is calculated by 
           (2^N)*40ns, where N is the averaging value. Please refere to the manual for a table with stopband and 3dB cut-off frequency.

        Parameters
        ----------

        Returns
        -------
        averageN: averageN A value from 0 to 24
        """
        response = self.device.request(self.interface_name + "." + "getAverageN")
        self.device.handleError(response)
        return response['result'][1]

    def getAxesDisplacement(self, ignoreFunctionError=True):
        """
        Reads out the displacement values of all three measurement axes.

        Parameters
        ----------
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        displacement0: displacement0 displacement of the axis 0 in pm
        displacement1: displacement1 displacement of the axis 1 in pm
        displacement2: displacement2 displacement of the axis 2 in pm
        """
        response = self.device.request(self.interface_name + "." + "getAxesDisplacement")
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1], response['result'][2], response['result'][3]

    def getAxisDisplacement(self, axis, ignoreFunctionError=True):
        """
        Reads out the displacement value of a specific measurement axis.

        Parameters
        ----------
        axis:  [0|1|2]
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        displacement: displacement Displacement of the axis in pm
        """
        response = self.device.request(self.interface_name + "." + "getAxisDisplacement", [axis])
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1]

    def getAxisSignalQuality(self, axis, ignoreFunctionError=True):
        """
        This function can be used to monitor the alignment contrast (peak-to-peak of the basic 
           interference signal amplitude) and the basline (its offset) during a running 
           measurement. Please note that the getAxisSignalQuality function output is only 
           updated when a displacement is measured. This means that angular misalignments 
           without displacement changes on the measurement axes cannot be detected. 
           Furthermore, we recommend using the IDS high accuracy initialization to obtain 
           correct values directly after measurement initialization. When using the quick 
           initialization, the initial value might be falsified at first, but correct after some detected 
           measurement (because it is updated with the correct value then).

        Parameters
        ----------
        axis:  [0|1|2]
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        contrast: contrast Contrast of the base band signal in ‰
        baseline: baseline Offset of the contrast measurement in ‰
        """
        response = self.device.request(self.interface_name + "." + "getAxisSignalQuality", [axis])
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1], response['result'][2]

    def getMeasurementEnabled(self):
        """
        This function can be used to see if the measurement is running

        Parameters
        ----------

        Returns
        -------
        enable: enable true = enabled; false = disabled
        """
        response = self.device.request(self.interface_name + "." + "getMeasurementEnabled")
        self.device.handleError(response)
        return response['result'][1]

    def getReferencePosition(self, axis, ignoreFunctionError=True):
        """
        The reference position information is estimated at the measurement initialization procedure or on reset. 
           This initial absolute position information is not updated during system 
           operation, whereas the IDS continuously measures the relative displacement from 
           that point.

        Parameters
        ----------
        axis:  [0|1|2]
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        position: position reference position of the axis in pm
        """
        response = self.device.request(self.interface_name + "." + "getReferencePosition", [axis])
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1]

    def getReferencePositions(self, ignoreFunctionError=True):
        """
        The reference position information is estimated at the measurement initialization procedure or on reset. 
           This initial absolute position information is not updated during system 
           operation, whereas the IDS continuously measures the relative displacement from 
           that point.

        Parameters
        ----------
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        position0: position0 position of the axis 0 in pm
        position1: position1 position of the axis 1 in pm
        position2: position2 position of the axis 2 in pm
        """
        response = self.device.request(self.interface_name + "." + "getReferencePositions")
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1], response['result'][2], response['result'][3]

    def getSignalQuality(self, axis, ignoreFunctionError=True):
        """
        This function can be used to monitor the alignment contrast (peak-to-peak of the basic 
           interference signal amplitude) and the basline (its offset) during a running 
           measurement. Please note that the getAxisSignalQuality function output is only 
           updated when a displacement is measured. This means that angular misalignments 
           without displacement changes on the measurement axes cannot be detected. 
           Furthermore, we recommend using the IDS high accuracy initialization to obtain 
           correct values directly after measurement initialization. When using the quick 
           initialization, the initial value might be falsified at first, but correct after some detected 
           measurement (because it is updated with the correct value then).

        Parameters
        ----------
        axis:  [0|1|2]
        ignoreFunctionError : boolean (default: True)
            True = Do not raise an AttoException if a warning code is returned.

        Returns
        -------
        warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
        contrast: contrast Contrast of the base band signal in ‰
        baseline: baseline Offset of the contrast measurement in ‰
        """
        response = self.device.request(self.interface_name + "." + "getSignalQuality", [axis])
        self.device.handleError(response, ignoreFunctionError)
        return response['result'][0], response['result'][1], response['result'][2]

    def linProc(self, axis, fringesnbr, samplesperfringe, set):
      """
        Important note: This function is not actively supported anymore. With IDS firmware 1.7.0, a new set of functions corresponding to the linearization procedure was introduced and effectively outdated this function.
           
           Starts linearization procedure (additional IDS feature).

        Parameters
        ----------
        axis:  [0|1|2]
        fringesnbr:  Number of fringes to be acquired
        samplesperfringe:  Number of samples per fringe
        set:  0 = evaluate current nonlinear amplitude 
            1 = perform linearization and upload look up table 
            2 = Clear look up table 
            3 = Perform only calculation of Phi file

        Returns
        -------
        lintable: lintable String, which contains all 512 phase related correction values
        nonlinearamp: nonlinearamp String which contains the residual positive and negative maximal nonlinear amplitude
      """
      try:
        self.device.tcp.settimeout(100.0)
        response = self.device.request(self.interface_name + "." + "linProc", [axis, fringesnbr, samplesperfringe, set])
        self.device.handleError(response)
        return response['result'][1], response['result'][2]
      finally:
        self.device.tcp.settimeout(10)

    def setAverageN(self, value):
        """
        Sets the averaging (lowpass) parameter N. The averaging time is calculated by 
           (2^N)*40ns, where N is the averaging value. Please refere to the manual for a table with stopband and 3dB cut-off frequency.

        Parameters
        ----------
        value:  AverageN value from 0 to 24

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setAverageN", [value])
        self.device.handleError(response)
        return 

