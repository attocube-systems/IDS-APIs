function [warningNo, position0, position1, position2] = IDS_displacement_getAbsolutePositions(tcp)
% brief : The absolute position information is estimated at the measurement initialization 
%           procedure. This initial absolute position information is not updated during system 
%           operation, whereas the IDS continuously measures the relative displacement from 
%           that point. This function outputs the sum of the static absolute position register value 
%           and the continuously updated displacement register value for all three axes.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
%           position0: position0 position of the axis 0 in pm
%           position1: position1 position of the axis 1 in pm
%           position2: position2 position of the axis 2 in pm

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.getAbsolutePositions", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

warningNo = data.result (1);
position0 = data.result (2);
position1 = data.result (3);
position2 = data.result (4);


end



