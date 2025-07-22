function [value_errNo, value_automatic] = axis_getAutoMasterAxis(tcp)
% brief : Gets status of the automatic configuration of the master axis.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_automatic: automatic true = automatic; false = manual (default: true)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.axis.getAutoMasterAxis", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_automatic = data.result(2);


end