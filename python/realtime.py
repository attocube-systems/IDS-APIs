    
class Realtime():

    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.ids.realtime"
            
    def AafIsEnabled(self):
        """
        Checks if the anti-aliasing filter is enabled.

        Parameters
        ----------

        Returns
        -------
        enabled: enabled false: Anti-Aliasing Filter is disabled 
            true: Anti-Aliasing Filter is enabled
        """
        response = self.device.request(self.interface_name + "." + "AafIsEnabled")
        self.device.handleError(response)
        return response['result'][1]

    def apply(self):
        """
        Applies new real time settings. Necessary after JSON realtime set commands.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "apply")
        self.device.handleError(response)
        return 

    def disableTestChannel(self):
        """
        Disables the test channel.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "disableTestChannel")
        self.device.handleError(response)
        return 

    def discard(self):
        """
        Discards new real time settings. Necessary after JSON set commands in case of failure.

        Parameters
        ----------

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "discard")
        self.device.handleError(response)
        return 

    def enableTestChannel(self, axis):
        """
        Enables the Test Channel, which can be used for estimating the maximum signal range.

        Parameters
        ----------
        axis:  Test Channel Master Axis

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "enableTestChannel", [axis])
        self.device.handleError(response)
        return 

    def getAafAttenuation(self):
        """
        Returns the current attenuation at f_nyquist of the anti-aliasing filter.

        Parameters
        ----------

        Returns
        -------
        attenuation: attenuation [3-30] dB m f_nyquist
        """
        response = self.device.request(self.interface_name + "." + "getAafAttenuation")
        self.device.handleError(response)
        return response['result'][1]

    def getAafEnabled(self):
        """
        Checks if the anti-aliasing filter is enabled.

        Parameters
        ----------

        Returns
        -------
        enabled: enabled false - the Anti-Aliasing Filter is disabled 
             true - the Anti-Aliasing Filter is enabled
        """
        response = self.device.request(self.interface_name + "." + "getAafEnabled")
        self.device.handleError(response)
        return response['result'][1]

    def getAafWindow(self):
        """
        Returns the current filter window of the anti-aliasing filter.

        Parameters
        ----------

        Returns
        -------
        window: window 0 = Rectangular,
             1 = Cosine,
             2 = Cosine^2,
             3 = Hamming,
             4 = Raised Cosine,
             5 = Automatic
        """
        response = self.device.request(self.interface_name + "." + "getAafWindow")
        self.device.handleError(response)
        return response['result'][1]

    def getHighPassCutOffFreq(self):
        """
        Reads out the high pass filter number of Linear/Analog output mode.

        Parameters
        ----------

        Returns
        -------
        value: value N, Linear Analog High Pass Cut-Off freqency is 1600/2^N kHz, with N \\in [1,24]
        """
        response = self.device.request(self.interface_name + "." + "getHighPassCutOffFreq")
        self.device.handleError(response)
        return response['result'][1]

    def getLinearRange(self):
        """
        Reads out the range number of Linear/Analog output mode.

        Parameters
        ----------

        Returns
        -------
        rangenumber: rangenumber N, Linear Analog Range is +-2^(N+11) pm, with N \\in [0, 34]
        """
        response = self.device.request(self.interface_name + "." + "getLinearRange")
        self.device.handleError(response)
        return response['result'][1]

    def getPeriodHsslClk(self):
        """
        Reads out the HSSL period clock.

        Parameters
        ----------

        Returns
        -------
        period: period Period in the Range of [40ns..10200ns]
        """
        response = self.device.request(self.interface_name + "." + "getPeriodHsslClk")
        self.device.handleError(response)
        return response['result'][1]

    def getPeriodHsslGap(self):
        """
        Reads out the HSSL period gap.

        Parameters
        ----------

        Returns
        -------
        gap: gap Number of clocks
        """
        response = self.device.request(self.interface_name + "." + "getPeriodHsslGap")
        self.device.handleError(response)
        return response['result'][1]

    def getPeriodSinCosClk(self):
        """
        Reads out the Sine-Cosine and AquadB period clock.

        Parameters
        ----------

        Returns
        -------
        period: period 40ns to 10200ns
        """
        response = self.device.request(self.interface_name + "." + "getPeriodSinCosClk")
        self.device.handleError(response)
        return response['result'][1]

    def getResolutionBissC(self):
        """
        Reads out the BissC resolution.

        Parameters
        ----------

        Returns
        -------
        resolution: resolution 1pm to 65535pm
        """
        response = self.device.request(self.interface_name + "." + "getResolutionBissC")
        self.device.handleError(response)
        return response['result'][1]

    def getResolutionHsslHigh(self):
        """
        Reads out the HSSL resolution high bit.

        Parameters
        ----------

        Returns
        -------
        resolution: resolution Resolution in the Range of [0..46]
        """
        response = self.device.request(self.interface_name + "." + "getResolutionHsslHigh")
        self.device.handleError(response)
        return response['result'][1]

    def getResolutionHsslLow(self):
        """
        Reads out the HSSL resolution low bit.#

        Parameters
        ----------

        Returns
        -------
        resolution: resolution Resolution in the range of [0..46]
        """
        response = self.device.request(self.interface_name + "." + "getResolutionHsslLow")
        self.device.handleError(response)
        return response['result'][1]

    def getResolutionSinCos(self):
        """
        Reads out the Sine-Cosine and AquadB resolution.

        Parameters
        ----------

        Returns
        -------
        resolution: resolution 1pm to 65535pm
        """
        response = self.device.request(self.interface_name + "." + "getResolutionSinCos")
        self.device.handleError(response)
        return response['result'][1]

    def getRtDistanceMode(self):
        """
        Reads out the distance mode. Depending on the realtime output mode, the mode can 
           be Displacement (returns 1), Absolute Distance (returns 2) or Vibrometry (returns 3).

        Parameters
        ----------

        Returns
        -------
        linearmode: linearmode 1 = Displacement (Available in HSSL mode and Linear Mode) 
            2 = Absolute Distance (Available in HSSL mode only) 
            3 = Vibrometry (Available in Linear mode)
        """
        response = self.device.request(self.interface_name + "." + "getRtDistanceMode")
        self.device.handleError(response)
        return response['result'][1]

    def getRtOutMode(self):
        """
        Reads out the current realtime output mode.

        Parameters
        ----------

        Returns
        -------
        rtOutMode: rtOutMode 0 = HSSL (TTL), 1 = HSSL (LVDS), 2 = AquadB (TTL), 
            3 = AquadB (LVDS), 4 = SinCos (TTL Error Signal), 
            5 = SinCos (LVDS Error Signal), 6 = Linear (TTL), 7 = Linear (LVDS), 
            8 = BiSS-C, 9 = Deactivated
        """
        response = self.device.request(self.interface_name + "." + "getRtOutMode")
        self.device.handleError(response)
        return response['result'][1]

    def getTestChannelEnabled(self):
        """
        Checks if the test channel is enabled

        Parameters
        ----------

        Returns
        -------
        enabled: enabled true = enabled, false = disabled
        """
        response = self.device.request(self.interface_name + "." + "getTestChannelEnabled")
        self.device.handleError(response)
        return response['result'][1]

    def setAaf(self, enabled, attenuation, window):
        """
        Sets the anti-aliasing filter with assigned filter window.

        Parameters
        ----------
        enabled:   0 - disables the Anti-Aliasing Filter 
             1 - enables the Anti-Aliasing Filter
        attenuation:  [3-30] dB m f_nyquist
        window:  0 = Rectangular,
             1 = Cosine,
             2 = Cosine^2,
             3 = Hamming,
             4 = Raised Cosine,
             5 = Automatic

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setAaf", [enabled, attenuation, window])
        self.device.handleError(response)
        return 

    def setHighPassCutOffFreq(self, value):
        """
        Sets the high pass filter number of Linear/Analog output mode.

        Parameters
        ----------
        value:  N, Linear Analog High Pass Cut-Off freqency is 1600/2^N kHz, with N \\in [1,24]

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setHighPassCutOffFreq", [value])
        self.device.handleError(response)
        return 

    def setLinearRange(self, rangenumber):
        """
        Sets the range number of Linear/Analog output mode.

        Parameters
        ----------
        rangenumber:  N, Linear Analog Range is +-2^(N+11) pm, with N \\in [0, 34]

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setLinearRange", [rangenumber])
        self.device.handleError(response)
        return 

    def setPeriodHsslClk(self, period):
        """
        Set the HSSL period clock. The value has to be a multiple of 40ns. If not, the value automatically is rounded.

        Parameters
        ----------
        period:  Period in the Range of [40ns..10200ns]

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setPeriodHsslClk", [period])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

    def setPeriodHsslGap(self, value):
        """
        Set the HSSL gap.

        Parameters
        ----------
        value:  Number of clocks

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setPeriodHsslGap", [value])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

    def setPeriodSinCosClk(self, value):
        """
        Sets the Sine-Cosine and AquadB period clock. The value has to be a multiple of 40ns. If not, the value automatically is rounded.

        Parameters
        ----------
        value:  period 40ns to 10200ns

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setPeriodSinCosClk", [value])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

    def setResolutionBissC(self, value):
        """
        Sets the BissC resolution.

        Parameters
        ----------
        value:  resolution 1pm to 65535pm

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setResolutionBissC", [value])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

    def setResolutionHsslHigh(self, value):
        """
        Sets the HSSL resolution high bit.

        Parameters
        ----------
        value:  Resolution in the Range of [0..46]

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setResolutionHsslHigh", [value])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

    def setResolutionHsslLow(self, value):
        """
        Sets the HSSL resolution low bit.

        Parameters
        ----------
        value:  Resolution in the Range of [0..46]

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setResolutionHsslLow", [value])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

    def setResolutionSinCos(self, value):
        """
        Sets the Sine-Cosine and AquadB resolution.

        Parameters
        ----------
        value:  resolution 1pm to 65535pm

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setResolutionSinCos", [value])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

    def setRtDistanceMode(self, value):
        """
        Sets the distance mode. Depending on the configuration of the IDS the mode can be 
           Displacement (returns 1), Absolute Distance (returns 2) or Vibrometry (returns 3).

        Parameters
        ----------
        value:  1 = Displacement (HSSL mode and Linear Mode) 
            2 = Absolute Distance (HSSL mode only) 
            3 = Vibrometry (Linear mode)

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRtDistanceMode", [value])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

    def setRtOutMode(self, value):
        """
        Sets the real time output mode.

        Parameters
        ----------
        value:  rtOutMode 0 = HSSL (TTL), 1 = HSSL (LVDS), 2 = AquadB (TTL), 
            3 = AquadB (LVDS), 4 = SinCos (TTL Error Signal), 
            5 = SinCos (LVDS Error Signal), 6 = Linear (TTL), 7 = Linear (LVDS), 
            8 = BiSS-C, 9 = Deactivated

        Returns
        -------
        """
        response = self.device.request(self.interface_name + "." + "setRtOutMode", [value])
        if response['result'][0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return 

