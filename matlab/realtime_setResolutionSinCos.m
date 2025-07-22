function [value_errNo] = realtime_setResolutionSinCos(tcp, resolution)
% brief : Sets the Sin/Cos and AquadB resolution.
%
% param[in] tcp: TCP/IP connection ID
%           resolution: value from 1 pm to 65535 pm
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.setResolutionSinCos", "params": [%i], "id": 1, "api": 2}', resolution);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.discard", "params": [], "id": 1, "api": 2}');
end
writeline(tcp, data_send);
data_receive = readline(tcp);

end