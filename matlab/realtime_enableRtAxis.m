function [value_errNo] = realtime_enableRtAxis(tcp, axis, enabled)
% brief : Enables the real-time output of the specific measurement axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           enabled: true = enable; false = disable
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.realtime.enableRtAxis", "params": [%i, %i], "id": 1, "api": 2}', axis, enabled);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end