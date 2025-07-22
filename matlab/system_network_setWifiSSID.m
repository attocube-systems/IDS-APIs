function [value_errNo] = system_network_setWifiSSID(tcp, SSID)
% brief : Changes the SSID of the network hosted (mode: access point) or connected to (mode: client).
%
% param[in] tcp: TCP/IP connection ID
%           SSID: SSID string
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setWifiSSID", "params": [%s], "id": 1, "api": 2}', SSID);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end