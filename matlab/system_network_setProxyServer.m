function [value_errNo] = system_network_setProxyServer(tcp, proxyServer)
% brief : Sets the proxy server of the device.
%
% param[in] tcp: TCP/IP connection ID
%           proxyServer: proxy server setting
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setProxyServer", "params": [%s], "id": 1, "api": 2}', proxyServer);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end