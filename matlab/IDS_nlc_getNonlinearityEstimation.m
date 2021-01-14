function [errNo, lut] = IDS_nlc_getNonlinearityEstimation(tcp)
% brief : Returns the LUT created by estimateNonlinearities (read-only mode) to compensate the nonlinearity error of the device for the current device settings. If no estimation was created an array of zeros is returned.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error number if one occured loading the LUT
%           lut: string
%            Json dumped LUT array with 512 integers

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.getNonlinearityEstimation", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
lut = data.result {2, 1};


end



