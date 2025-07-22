function [value_errNo, value_enabled] = system_network_getEnableDhcpClient(tcp)
% brief : Gets the status of DHCP client.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_enabled: enabled true = enabled, false = disabled


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getEnableDhcpClient", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_enabled = data.result(2);


end