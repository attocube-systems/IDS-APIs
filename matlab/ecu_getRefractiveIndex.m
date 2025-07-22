function [errNo, rIndex] = ecu_getRefractiveIndex(tcp)
% brief : Reads out the ECU estimated refractive index from the current ECU values. To get the refractive index for other compensation modes, please refer to the getRefractiveIndexForCompensation function.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           rIndex: refractive index


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getRefractiveIndex", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
rIndex = data.result(2);


end