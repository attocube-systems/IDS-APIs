function [errNo] = IDS_realtime_setAaf(tcp, enabled, attenuation, window)
% brief : Sets the anti-aliasing filter with assigned filter window.
%
% param[in] tcp : TCP/IP connection ID
%           enabled:   0 - disables the Anti-Aliasing Filter 
%             1 - enables the Anti-Aliasing Filter
%           attenuation:  [3-30] dB m f_nyquist
%           window:  0 = Rectangular,
%             1 = Cosine,
%             2 = Cosine^2,
%             3 = Hamming,
%             4 = Raised Cosine,
%             5 = Automatic
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setAaf", "params": [%i, %i, %i], "id": 1, "api": 2}', enabled, attenuation, window);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


