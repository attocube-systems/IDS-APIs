function [value_errNo, value_Is1, value_Is2] = SEN_getLockStatus(tcp)
% brief : Gets the lock status of the device and if the current client is authorized to use the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo errorCode
%           value_Is1: Is the device locked?
%           value_Is2: Is the client authorized?


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "getLockStatus", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_Is1 = data.result(2);
value_Is2 = data.result(3);


end