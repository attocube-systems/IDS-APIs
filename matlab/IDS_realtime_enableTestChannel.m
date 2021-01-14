function [errNo] = IDS_realtime_enableTestChannel(tcp, axis)
% brief : Enables the Test Channel, which can be used for estimating the maximum signal range.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  Test Channel Master Axis
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.enableTestChannel", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


