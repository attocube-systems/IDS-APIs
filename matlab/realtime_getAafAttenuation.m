function [value_errNo, value_attenuation] = realtime_getAafAttenuation(tcp)
% brief : Returns the current attenuation of the anti-aliasing filter.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_attenuation: attenuation value from 3 dB to 30 dB (default: 15 dB)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getAafAttenuation", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_attenuation = data.result(2);


end