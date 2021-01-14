function [warningNo, displacement0, displacement1, displacement2] = IDS_displacement_getAxesDisplacement(tcp)
% brief : Reads out the displacement values of all three measurement axes.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           warningNo: warningNo
%           displacement0: displacement0 displacement of the axis 0 in pm
%           displacement1: displacement1 displacement of the axis 1 in pm
%           displacement2: displacement2 displacement of the axis 2 in pm

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.getAxesDisplacement", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

warningNo = data.result (1);
displacement0 = data.result (2);
displacement1 = data.result (3);
displacement2 = data.result (4);


end



