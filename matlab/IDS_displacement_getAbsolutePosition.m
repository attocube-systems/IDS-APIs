function [warningNo, position] = IDS_displacement_getAbsolutePosition(tcp, axis)
% brief : The absolute position information is estimated at the measurement initialization procedure. 
%           This initial absolute position information is not updated during system 
%           operation, whereas the IDS continuously measures the relative displacement from 
%           that point. This function outputs the sum of the static absolute position register value 
%           and the continuously updated displacement register value for a single axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           warningNo: warningNo
%           position: position position of the axis in pm


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.getAbsolutePosition", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

warningNo = data.result (1);
position = data.result (2);


end


