function [value_errNo] = system_network_setWifiPassphrase(tcp, psk)
% brief : Changes the passphrase of the network hosted (mode: access point) or connected to (mode: client).
%
% param[in] tcp: TCP/IP connection ID
%           psk: pre-shared key
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setWifiPassphrase", "params": [%s], "id": 1, "api": 2}', psk);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end