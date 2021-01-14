function [errNo, rindex] = IDS_manual_getRefractiveIndex(tcp, axis)
% brief : Reads out the manually configured value for the refractive index (compensation mode 2).
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to get the mode for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           rindex: double
%            refractive index


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.manual.getRefractiveIndex", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
rindex = data.result (2);


end


