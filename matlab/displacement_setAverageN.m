function [value_errNo] = displacement_setAverageN(tcp, averageN)
% brief : Sets the averaging (lowpass) parameter N.
%
% param[in] tcp: TCP/IP connection ID
%           averageN: value from 0 to 24
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.displacement.setAverageN", "params": [%i], "id": 1, "api": 2}', averageN);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end