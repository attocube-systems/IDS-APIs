function [errNo] = nlc_setLut(tcp, axis, lut)
% brief : Uploads a LUT for a specific measurement axis, which can be applied by the setLutApplied function.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           lut: LUT array with 512 integers
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.setLut", "params": [%i, %s], "id": 1, "api": 2}', axis, lut);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end