function [value_errNo] = axis_setAutoMasterAxis(tcp, automatic)
% brief : Enables the automatic configuration of the master axis during measurement initialization.
%
% param[in] tcp: TCP/IP connection ID
%           automatic: true = automatic; false = manual
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.axis.setAutoMasterAxis", "params": [%i], "id": 1, "api": 2}', automatic);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end