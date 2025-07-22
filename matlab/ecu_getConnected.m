function [errNo, connected] = ecu_getConnected(tcp)
% brief : Reads out whether the ECU interface is physically connected or not. Checking if the ECU is connected can only be done on an enabled ECU interface.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           connected: true = connected; false = disconnected


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getConnected", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
connected = data.result(2);


end