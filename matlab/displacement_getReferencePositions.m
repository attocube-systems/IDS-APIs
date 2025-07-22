function [value_warningNo, value_position1, value_position2, value_position3] = displacement_getReferencePositions(tcp)
% brief : Reads out the reference position value of all three measurement axes.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
%           value_position1: position0 reference position of the axis 0 in pm
%           value_position2: position1 reference position of the axis 1 in pm
%           value_position3: position2 reference position of the axis 2 in pm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.displacement.getReferencePositions", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_warningNo = data.result(1);
value_position1 = data.result(2);
value_position2 = data.result(3);
value_position3 = data.result(4);


end