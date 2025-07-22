function [errNo, apply] = nlc_getLutApplied(tcp, axis)
% brief : Returns whether a LUT is applied or not for a specific measurement axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           apply: true = applied; false = disabled


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.getLutApplied", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
apply = data.result(2);


end