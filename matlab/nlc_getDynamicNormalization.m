function [errNo, mode] = nlc_getDynamicNormalization(tcp, axis)
% brief : Returns the normalization mode of a specific measurement axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           mode: 0 = dynamic normalization (default)1 = normalization frozen (for slow target drifts)2 = normalization mode determined by target velocity


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.getDynamicNormalization", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
mode = data.result(2);


end