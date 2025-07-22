function [value_errNo, value_name] = system_getHostname(tcp)
% brief : Returns the device hostname.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_name: name hostname


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.getHostname", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_name = data.result(2);


end