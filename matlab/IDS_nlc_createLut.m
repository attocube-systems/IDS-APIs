function [errNo] = IDS_nlc_createLut(tcp, axis)
% brief : Creates a new LUT for the given axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS where the LUT should be generated
% param[out]
%           errNo: int32
%            Error number if one occured while starting the creation.
%Errors during creation can be pulled by getLutStatus


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.createLut", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


