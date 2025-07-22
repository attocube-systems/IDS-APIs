function [value_errNo] = realtime_setAaf(tcp, enable, attenuation, window)
% brief : Sets the anti-aliasing filter with assigned filter window.
%
% param[in] tcp: TCP/IP connection ID
%           enable: true = enable; false = disable
%           attenuation: value from 3 dB to 30 dB
%           window: 0 = Rectangular,/n1 = Cosine,/n2 = Cosine^2,/n3 = Hamming,/n4 = Raised Cosine
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.setAaf", "params": [%i, %i, %i], "id": 1, "api": 2}', enable, attenuation, window);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end