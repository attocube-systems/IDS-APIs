function [errNo, masteraxis] = IDS_axis_getMasterAxis(tcp)
% brief : Returns the master axis (for more information please refer to the IDS User Manual).
%            ADD MORE INFO
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           masteraxis: masteraxis Axis which is operating as masteraxis [0..2]

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.getMasterAxis", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
masteraxis = data.result (2);


end



