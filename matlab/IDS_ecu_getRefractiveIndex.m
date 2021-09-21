function [errNo, rIndex] = IDS_ecu_getRefractiveIndex(tcp)
% brief : Reads out the ECU estimated refractive index for the current
%        ECU readings. To get the refractive index for other modes, please see
%        getRefractiveIndexForCompensation.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           rIndex: double
%            refractive index

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getRefractiveIndex", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
rIndex = data.result (2);


end



