function [value_warningNo, value_displacement1, value_displacement2, value_displacement3] = displacement_getAxesDisplacement(tcp)
% brief : Reads out the displacement values of all three measurement axes.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
%           value_displacement1: displacement0 displacement of the axis 0 in pm
%           value_displacement2: displacement1 displacement of the axis 1 in pm
%           value_displacement3: displacement2 displacement of the axis 2 in pm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.displacement.getAxesDisplacement", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_warningNo = data.result(1);
value_displacement1 = data.result(2);
value_displacement2 = data.result(3);
value_displacement3 = data.result(4);


end