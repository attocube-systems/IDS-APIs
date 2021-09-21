function [errNo, mode] = IDS_ecu_getRefractiveIndexCompensationMode(tcp, axis)
% brief : Reads out the compensation mode (see below) which is currently used for the environmental compensation.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to get the mode for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           mode: int32
%            mode see defintion in set function


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getRefractiveIndexCompensationMode", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end


