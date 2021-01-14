function [errNo, connected] = IDS_ecu_getConnected(tcp)
% brief : Reads out whether the ECU interface is physically connected or not. Checking if the ECU is connected can only be done on an enabled ECU interface.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           connected: boolean
%            true if connected, false if not

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getConnected", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
connected = data.result (2);


end



