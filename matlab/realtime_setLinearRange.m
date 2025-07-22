function [errNo] = realtime_setLinearRange(tcp, rangenumber)
% brief : Sets the range number of Linear analog output mode.
%
% param[in] tcp: TCP/IP connection ID
%           rangenumber: value from 0 to 34
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.setLinearRange", "params": [%i], "id": 1, "api": 2}', rangenumber);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end