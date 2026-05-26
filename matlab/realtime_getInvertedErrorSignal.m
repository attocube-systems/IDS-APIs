function [value_errNo, value_inverted] = realtime_getInvertedErrorSignal(tcp)
% brief : Checks if the error signal is inverted.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_inverted: inverted true = inverted; false = non-inverted


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.realtime.getInvertedErrorSignal", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_inverted = data.result(2);


end