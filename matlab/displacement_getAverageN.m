function [value_errNo, value_averageN] = displacement_getAverageN(tcp)
% brief : Reads out the averaging (lowpass) parameter N.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_averageN: averageN value from 0 to 24


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.displacement.getAverageN", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_averageN = data.result(2);


end