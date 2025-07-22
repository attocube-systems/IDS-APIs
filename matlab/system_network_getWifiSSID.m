function [value_errNo, value_SSID] = system_network_getWifiSSID(tcp)
% brief : Gets the SSID of the network hosted (mode: access point) or connected to (mode: client).
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_SSID: SSID SSID string


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getWifiSSID", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_SSID = data.result(2);


end