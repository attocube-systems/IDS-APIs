function [value_errNo, value_resolution] = realtime_getResolutionSinCos(tcp)
% brief : Reads out the Sin/Cos and AquadB resolution.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_resolution: resolution value from 1 pm to 65535 pm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getResolutionSinCos", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_resolution = data.result(2);


end