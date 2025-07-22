function [errNo, lut] = nlc_getLut(tcp, axis)
% brief : Returns the LUT determined by the createLut function, which can be applied by the setLutApplied function.        Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: errNo
%           lut: LUT array with 512 integers


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.getLut", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
lut = data.result(2);


end