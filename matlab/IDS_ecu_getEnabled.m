function [errNo, enabled] = IDS_ecu_getEnabled(tcp)
% brief : Reads out whether the ECU interface is enabled or not. Enabling the ECU interface is crucial for working with the ECU.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           enabled: boolean
%            true if enabled, false if not

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getEnabled", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end



