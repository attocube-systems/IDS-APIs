function [errNo] = nlc_setLutApplied(tcp, axis, apply)
% brief : Applies the LUT for a specific measurement axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
%           apply: true = apply LUT; false = disable LUT
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.setLutApplied", "params": [%i, %i], "id": 1, "api": 2}', axis, apply);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end