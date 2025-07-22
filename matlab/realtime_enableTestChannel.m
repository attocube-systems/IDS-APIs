function [value_errNo] = realtime_enableTestChannel(tcp)
% brief : Enables the test channel on measurement axis 0, which can be used for estimating the maximum signal range./nThis function is only available in the "system idle" state (please refer to the getCurrentMode function).
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.enableTestChannel", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end