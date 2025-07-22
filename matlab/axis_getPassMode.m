function [value_errNo, value_mode] = axis_getPassMode(tcp)
% brief : Reads out the current pass mode.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_mode: mode 0 = single; pass 1 = dual pass


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.axis.getPassMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_mode = data.result(2);


end