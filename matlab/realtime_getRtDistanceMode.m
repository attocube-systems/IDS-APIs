function [value_errNo, value_mode] = realtime_getRtDistanceMode(tcp)
% brief : Reads out the distance mode.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_mode: mode 1 = Displacement (all modes)/n2 = Absolute Distance (HSSL mode and BiSS C mode)/n3 = Vibrometry (Linear mode only)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getRtDistanceMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_mode = data.result(2);


end