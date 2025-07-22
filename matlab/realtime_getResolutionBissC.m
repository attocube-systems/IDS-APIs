function [value_errNo, value_resolution] = realtime_getResolutionBissC(tcp)
% brief : Reads out the BiSS C resolution.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_resolution: resolution value from 0 to 16


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getResolutionBissC", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_resolution = data.result(2);


end