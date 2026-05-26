function [value_errNo] = realtime_setInvertedErrorSignal(tcp, inverted)
% brief : Inverts the error signal.
%
% param[in] tcp: TCP/IP connection ID
%           inverted: true = inverted; false = non-inverted
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.realtime.setInvertedErrorSignal", "params": [%i], "id": 1, "api": 2}', inverted);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end