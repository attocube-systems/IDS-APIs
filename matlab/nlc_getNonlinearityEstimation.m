function [errNo, lut] = nlc_getNonlinearityEstimation(tcp)
% brief : Returns the LUT created by the estimateNonlinearities function (read-only mode) to compensate the nonlinearity error of the device for the current device settings. If no estimation was created an array of zeros is returned.        Attention: the LUT values represent the internal units. To convert the LUT values into nm, please multiply the LUT array by factor ((2^16-1)*(1530/2)).
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           lut: LUT array with 512 integers


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.getNonlinearityEstimation", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
lut = data.result(2);


end