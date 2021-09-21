function [errNo] = IDS_nlc_clearLut(tcp, axis)
% brief : Deactivates the LUT and removes it from the device
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS
% param[out]
%           errNo: int32
%            Error number if one occured during deletion of the LUT


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.clearLut", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


