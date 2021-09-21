function [errNo] = IDS_nlc_setLut(tcp, axis, lut)
% brief : Uploads a LUT for a specific axis (which can be applied by setLutApplied)
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS
%           lut: 
%            Json dumped LUT array with 512 integers
% param[out]
%           errNo: int32
%            Error number if one occured during uploading the LUT


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.setLut", "params": [%i, %s], "id": 1, "api": 2}', axis, lut);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


