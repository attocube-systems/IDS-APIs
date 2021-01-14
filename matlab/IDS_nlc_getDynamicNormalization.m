function [errNo, mode] = IDS_nlc_getDynamicNormalization(tcp, axis)
% brief : Returns the normalization mode of a specific axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS of which the normalization mode is queried
% param[out]
%           errNo: int32
%            Error number if an error occured while getting normalization mode
%           mode: int32
%            Normalization Mode
%
%    0    Dynamic normalization
%
%    1    Normalization frozen
%
%    2    Normalization mode determined by target velocity


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.getDynamicNormalization", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end


