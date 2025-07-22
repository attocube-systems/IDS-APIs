function [value_errNo, value_mode] = system_getInitMode(tcp)
% brief : Returns the initialization mode.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_mode: mode 0 = High Accuracy Initialization; 1 = Quick Initialization (default: 0)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.system.getInitMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_mode = data.result(2);


end