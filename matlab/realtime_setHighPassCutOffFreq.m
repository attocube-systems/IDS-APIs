function [value_errNo] = realtime_setHighPassCutOffFreq(tcp, filternumber)
% brief : Sets the high pass filter number of Linear analog output mode.
%
% param[in] tcp: TCP/IP connection ID
%           filternumber: value from 1 to 24
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.setHighPassCutOffFreq", "params": [%i], "id": 1, "api": 2}', filternumber);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end