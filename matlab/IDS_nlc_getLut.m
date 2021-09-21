function [errNo, lut] = IDS_nlc_getLut(tcp, axis)
% brief : Returns the LUT determined by createLut (which can be applied by setLutApplied).
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS
% param[out]
%           errNo: int32
%            Error number if one occured during retrieving the LUT
%           lut: string
%            Json dumped LUT array with 512 integers


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.getLut", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
lut = data.result {2, 1};


end


