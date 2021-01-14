function [errNo] = system_network_setWifiMode(tcp, wifi)
% brief : Change the operation mode of the wifi adapter
%
% param[in] tcp : TCP/IP connection ID
%           wifi:  mode: 0: Access point, 1: Wifi client
% param[out]
%           errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.network.setWifiMode", "params": [%i], "id": 1, "api": 2}', wifi);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


