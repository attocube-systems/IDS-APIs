function [errNo, type] = IDS_system_getDeviceType(tcp)
% brief : Reads out the IDS device type. For differences between the device types please refer to the IDS User Manual.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           type: type Type of IDS (e.g. "IDS3010")

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.getDeviceType", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
type = data.result {2, 1};


end



