function [value_warningNo, value_position] = displacement_getAbsolutePosition(tcp, axis)
% brief : This function outputs the sum of the static absolute position register value and the continuously updated displacement register value for a specific measurement axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
%           value_position: position absolute position of the axis in pm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.displacement.getAbsolutePosition", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_warningNo = data.result(1);
value_position = data.result(2);


end