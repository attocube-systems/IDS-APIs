function [errNo] = nlc_setDynamicNormalization(tcp, axis, mode)
% brief : Sets the normalization mode of a specific measurement axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           mode: 0 = dynamic normalization 1 = normalization frozen (for slow target drifts)2 = automatic alternation between mode 0 and 1 depending on the target velocity
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.setDynamicNormalization", "params": [%i, %i], "id": 1, "api": 2}', axis, mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end