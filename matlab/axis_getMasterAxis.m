function [value_errNo, value_axis] = axis_getMasterAxis(tcp)
% brief : Returns the master axis (for more information, please refer to the device user manual).
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_axis: axis [0|1|2]


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.axis.getMasterAxis", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_axis = data.result(2);


end