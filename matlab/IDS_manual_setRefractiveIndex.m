function [errNo] = IDS_manual_setRefractiveIndex(tcp, axis, rindex)
% brief : Sets the refractive index for the direct mode (compensation mode 2). The input range is defined to be greater than 1.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to set the mode for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
%           rindex: 
%            refractive index
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.manual.setRefractiveIndex", "params": [%i, %d], "id": 1, "api": 2}', axis, rindex);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


