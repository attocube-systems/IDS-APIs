class Realtime:
    def __init__(self, device):
        self.device = device
        self.interface_name = "com.attocube.sen.realtime"

    def getRtOutMode(self):
        # type: () -> (int)
        """
        Reads out the current real-time output mode.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_rtOutMode: rtOutMode 0 = HSSL (LVTTL), 1 = HSSL (LVDS), 2 = AquadB (LVTTL),/n3 = AquadB (LVDS), 4 = Sin/Cos (LVTTL error signal),/n5 = Sin/Cos (LVDS error signal), 6 = Linear (LVTTL error signal), 7 = Linear (LVDS error signal),/n8 = BiSS-C, 9 = Deactivated
                    
        """
        
        response = self.device.request(self.interface_name + ".getRtOutMode")
        self.device.handleError(response)
        return response[1]                

    def setRtOutMode(self, rtOutMode):
        # type: (int) -> ()
        """
        Sets the real-time output mode.

        Parameters:
            rtOutMode: 0 = HSSL (LVTTL), 1 = HSSL (LVDS), 2 = AquadB (LVTTL),/n3 = AquadB (LVDS), 4 = Sin/Cos (LVTTL error signal),/n5 = Sin/Cos (LVDS error signal), 6 = Linear (LVTTL error signal), 7 = Linear (LVDS error signal),/n8 = BiSS-C, 9 = Deactivated
                    
        """
        
        response = self.device.request(self.interface_name + ".setRtOutMode", [rtOutMode, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getRtDistanceMode(self):
        # type: () -> (int)
        """
        Reads out the distance mode.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_mode: mode 1 = Displacement (all modes)/n2 = Absolute Distance (HSSL mode and BiSS C mode)/n3 = Vibrometry (Linear mode only)
                    
        """
        
        response = self.device.request(self.interface_name + ".getRtDistanceMode")
        self.device.handleError(response)
        return response[1]                

    def setRtDistanceMode(self, mode):
        # type: (int) -> ()
        """
        Sets the distance mode.

        Parameters:
            mode: 1 = Displacement (all modes)/n2 = Absolute Distance (HSSL mode and BiSS C mode)/n3 = Vibrometry (Linear mode only)
                    
        """
        
        response = self.device.request(self.interface_name + ".setRtDistanceMode", [mode, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getResolutionBissC(self):
        # type: () -> (int)
        """
        Reads out the BiSS C resolution.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_resolution: resolution value from 0 to 16
                    
        """
        
        response = self.device.request(self.interface_name + ".getResolutionBissC")
        self.device.handleError(response)
        return response[1]                

    def setResolutionBissC(self, resolution):
        # type: (int) -> ()
        """
        Sets the BiSS C resolution.

        Parameters:
            resolution: value from 0 to 16
                    
        """
        
        response = self.device.request(self.interface_name + ".setResolutionBissC", [resolution, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getResolutionHsslLow(self):
        # type: () -> (int)
        """
        Reads out the HSSL resolution low bit.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_resolution: resolution value from 0 to 46
                    
        """
        
        response = self.device.request(self.interface_name + ".getResolutionHsslLow")
        self.device.handleError(response)
        return response[1]                

    def setResolutionHsslLow(self, resolution):
        # type: (int) -> ()
        """
        Sets the HSSL resolution low bit.

        Parameters:
            resolution: value from 0 to 46
                    
        """
        
        response = self.device.request(self.interface_name + ".setResolutionHsslLow", [resolution, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getResolutionHsslHigh(self):
        # type: () -> (int)
        """
        Reads out the HSSL resolution high bit.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_resolution: resolution value from 1 to 47
                    
        """
        
        response = self.device.request(self.interface_name + ".getResolutionHsslHigh")
        self.device.handleError(response)
        return response[1]                

    def setResolutionHsslHigh(self, resolution):
        # type: (int) -> ()
        """
        Sets the HSSL resolution high bit.

        Parameters:
            resolution: value from 1 to 47
                    
        """
        
        response = self.device.request(self.interface_name + ".setResolutionHsslHigh", [resolution, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getLinearRange(self):
        # type: () -> (int)
        """
        Reads out the range number N of Linear analog output mode.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_rangenumber: rangenumber value from 0 to 34
                    
        """
        
        response = self.device.request(self.interface_name + ".getLinearRange")
        self.device.handleError(response)
        return response[1]                

    def setLinearRange(self, rangenumber):
        # type: (int) -> ()
        """
        Sets the range number of Linear analog output mode.

        Parameters:
            rangenumber: value from 0 to 34
                    
        """
        
        response = self.device.request(self.interface_name + ".setLinearRange", [rangenumber, ])
        self.device.handleError(response)
        return                 

    def getPeriodHsslClk(self):
        # type: () -> (int)
        """
        Reads out the HSSL period clock.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_period: period value from 40 ns to 10200 ns
                    
        """
        
        response = self.device.request(self.interface_name + ".getPeriodHsslClk")
        self.device.handleError(response)
        return response[1]                

    def setPeriodHsslClk(self, period):
        # type: (int) -> ()
        """
        Set the HSSL period clock.

        Parameters:
            period: value from 40 ns to 10200 ns
                    
        """
        
        response = self.device.request(self.interface_name + ".setPeriodHsslClk", [period, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getPeriodHsslGap(self):
        # type: () -> (int)
        """
        Reads out the HSSL period gap as number of clocks.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_gap: gap value from 1 to 255
                    
        """
        
        response = self.device.request(self.interface_name + ".getPeriodHsslGap")
        self.device.handleError(response)
        return response[1]                

    def setPeriodHsslGap(self, gap):
        # type: (int) -> ()
        """
        Set the HSSL period gap as number of clocks.

        Parameters:
            gap: value from 1 to 255
                    
        """
        
        response = self.device.request(self.interface_name + ".setPeriodHsslGap", [gap, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getPeriodSinCosClk(self):
        # type: () -> (int)
        """
        Reads out the Sin/Cos and AquadB period clock.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_period: period value from 40 ns to 10200 ns
                    
        """
        
        response = self.device.request(self.interface_name + ".getPeriodSinCosClk")
        self.device.handleError(response)
        return response[1]                

    def setPeriodSinCosClk(self, period):
        # type: (int) -> ()
        """
        Sets the Sin/Cos and AquadB period clock.

        Parameters:
            period: value from 40 ns to 10200 ns
                    
        """
        
        response = self.device.request(self.interface_name + ".setPeriodSinCosClk", [period, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getResolutionSinCos(self):
        # type: () -> (int)
        """
        Reads out the Sin/Cos and AquadB resolution.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_resolution: resolution value from 1 pm to 65535 pm
                    
        """
        
        response = self.device.request(self.interface_name + ".getResolutionSinCos")
        self.device.handleError(response)
        return response[1]                

    def setResolutionSinCos(self, resolution):
        # type: (int) -> ()
        """
        Sets the Sin/Cos and AquadB resolution.

        Parameters:
            resolution: value from 1 pm to 65535 pm
                    
        """
        
        response = self.device.request(self.interface_name + ".setResolutionSinCos", [resolution, ])
        if response[0] == 0:
            self.apply()
        else:
            self.discard()
        self.device.handleError(response)
        return                 

    def getHighPassCutOffFreq(self):
        # type: () -> (int)
        """
        Reads out the high pass filter number of Linear analog output mode.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_filternumber: filternumber value from 1 to 24
                    
        """
        
        response = self.device.request(self.interface_name + ".getHighPassCutOffFreq")
        self.device.handleError(response)
        return response[1]                

    def setHighPassCutOffFreq(self, filternumber):
        # type: (int) -> ()
        """
        Sets the high pass filter number of Linear analog output mode.

        Parameters:
            filternumber: value from 1 to 24
                    
        """
        
        response = self.device.request(self.interface_name + ".setHighPassCutOffFreq", [filternumber, ])
        self.device.handleError(response)
        return                 

    def setAaf(self, enable, attenuation, window):
        # type: (bool, int, int) -> ()
        """
        Sets the anti-aliasing filter with assigned filter window.

        Parameters:
            enable: true = enable; false = disable
            attenuation: value from 3 dB to 30 dB
            window: 0 = Rectangular,/n1 = Cosine,/n2 = Cosine^2,/n3 = Hamming,/n4 = Raised Cosine
                    
        """
        
        response = self.device.request(self.interface_name + ".setAaf", [enable, attenuation, window, ])
        self.device.handleError(response)
        return                 

    def getAafAttenuation(self):
        # type: () -> (int)
        """
        Returns the current attenuation of the anti-aliasing filter.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_attenuation: attenuation value from 3 dB to 30 dB (default: 15 dB)
                    
        """
        
        response = self.device.request(self.interface_name + ".getAafAttenuation")
        self.device.handleError(response)
        return response[1]                

    def getAafWindow(self):
        # type: () -> (int)
        """
        Returns the current filter window of the anti-aliasing filter.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_window: window 0 = Rectangular,/n1 = Cosine,/n2 = Cosine^2,/n3 = Hamming,/n4 = Raised Cosine (default)
                    
        """
        
        response = self.device.request(self.interface_name + ".getAafWindow")
        self.device.handleError(response)
        return response[1]                

    def getAafEnabled(self):
        # type: () -> (bool)
        """
        Checks if the anti-aliasing filter is enabled.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_enabled: enabled true = enabled; false = disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getAafEnabled")
        self.device.handleError(response)
        return response[1]                

    def apply(self):
        # type: () -> ()
        """
        Applies new real-time settings.
        """
        
        response = self.device.request(self.interface_name + ".apply")
        self.device.handleError(response)
        return                 

    def discard(self):
        # type: () -> ()
        """
        Discards new real-time settings.
        """
        
        response = self.device.request(self.interface_name + ".discard")
        self.device.handleError(response)
        return                 

    def enableTestChannel(self):
        # type: () -> ()
        """
        Enables the test channel on measurement axis 0, which can be used for estimating the maximum signal range./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function).
        """
        
        response = self.device.request(self.interface_name + ".enableTestChannel")
        self.device.handleError(response)
        return                 

    def disableTestChannel(self):
        # type: () -> ()
        """
        Disables the test channel.
        """
        
        response = self.device.request(self.interface_name + ".disableTestChannel")
        self.device.handleError(response)
        return                 

    def getTestChannelEnabled(self):
        # type: () -> (bool)
        """
        Checks if the test channels are enabled.
        Returns:
            value_errNo: errNo error code, if there was an error, otherwise 0 for ok
            value_enabled: enabled true = enabled; false = disabled
                    
        """
        
        response = self.device.request(self.interface_name + ".getTestChannelEnabled")
        self.device.handleError(response)
        return response[1]                

