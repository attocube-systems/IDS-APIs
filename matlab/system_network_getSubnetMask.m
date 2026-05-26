function [value_errNo, value_netmask] = system_network_getSubnetMask(tcp)
% brief : Gets the subnet mask of the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_netmask: netmask subnet mask as string


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.network.getSubnetMask", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_netmask = data.result(2);


end