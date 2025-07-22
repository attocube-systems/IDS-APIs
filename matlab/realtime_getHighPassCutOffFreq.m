function [value_errNo, value_filternumber] = realtime_getHighPassCutOffFreq(tcp)
% brief : Reads out the high pass filter number of Linear analog output mode.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_filternumber: filternumber value from 1 to 24


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getHighPassCutOffFreq", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_filternumber = data.result(2);


end