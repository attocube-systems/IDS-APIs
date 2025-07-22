function [value_errNo, value_proxyServer] = system_network_getProxyServer(tcp)
% brief : Gets the proxy settings of the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_proxyServer: proxyServer proxy server setting, empty for no proxy


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.getProxyServer", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_proxyServer = data.result(2);


end