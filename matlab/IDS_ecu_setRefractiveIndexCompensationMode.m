function [errNo] = IDS_ecu_setRefractiveIndexCompensationMode(tcp, axis, mode)
% brief : Sets the refractive index mode.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to set the mode for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
%           mode: 
%            mode can be 0 for direct ECU mode, 1 to take the manual values and calculate the refractive index from this or 2 to directly take the set refrative index
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.setRefractiveIndexCompensationMode", "params": [%i, %i], "id": 1, "api": 2}', axis, mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


