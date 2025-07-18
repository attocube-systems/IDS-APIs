function [errNo, rIndex] = IDS_ecu_getRefractiveIndexForCompensation(tcp, axis)
% brief : Reads out the refractive index used according to the current environmental compensation mode for this axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to get the refractive index for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           rIndex: double
%            refractive index


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getRefractiveIndexForCompensation", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
rIndex = data.result (2);


end


