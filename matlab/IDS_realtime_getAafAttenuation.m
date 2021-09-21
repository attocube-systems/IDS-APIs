function [errNo, attenuation] = IDS_realtime_getAafAttenuation(tcp)
% brief : Returns the current attenuation at f_nyquist of the anti-aliasing filter.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           attenuation: attenuation [3-30] dB m f_nyquist

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getAafAttenuation", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
attenuation = data.result (2);


end



