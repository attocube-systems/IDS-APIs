function [errNo] = manual_setRefractiveIndex(tcp, axis, rindex)
% brief : Sets the manually configured refractive index for the compensation mode 2. The input range is defined to be greater than 1.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]Parameter has to be -1 for the moment,individual axes will be supported in the next firmware release
%           rindex: refractive index
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.manual.setRefractiveIndex", "params": [%i, %d], "id": 1, "api": 2}', axis, rindex);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end