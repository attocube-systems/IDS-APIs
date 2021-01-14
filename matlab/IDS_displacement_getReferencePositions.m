function [warningNo, position0, position1, position2] = IDS_displacement_getReferencePositions(tcp)
% brief : The reference position information is estimated at the measurement initialization procedure or on reset. 
%           This initial absolute position information is not updated during system 
%           operation, whereas the IDS continuously measures the relative displacement from 
%           that point.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           warningNo: warningNo
%           position0: position0 position of the axis 0 in pm
%           position1: position1 position of the axis 1 in pm
%           position2: position2 position of the axis 2 in pm

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.getReferencePositions", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

warningNo = data.result (1);
position0 = data.result (2);
position1 = data.result (3);
position2 = data.result (4);


end



