function [value_errNo, value_IP] = system_network_getIpAddress(tcp)
% brief : Gets the IP address of the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_IP: IP address as string


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getIpAddress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_IP = data.result(2);


end