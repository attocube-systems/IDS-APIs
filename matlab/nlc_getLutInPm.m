function [errNo, lut] = nlc_getLutInPm(tcp, axis)
% brief : This function returns the LUT after calling the createLut() function. If no estimation has been performed, the function returns an error.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           lut: JSON-encoded string containing an array of 512 integer values representing the LUT


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.getLutInPm", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
lut = data.result(2);


end