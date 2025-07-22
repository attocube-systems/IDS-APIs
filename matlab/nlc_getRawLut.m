function [errNo, raw_lut] = nlc_getRawLut(tcp, axis)
% brief : Returns the raw LUT created by the createLut or estimateNonlinearites functions.        Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).            For debugging only.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           raw_lut: Json dumped lut array


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.getRawLut", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
raw_lut = data.result(2);


end