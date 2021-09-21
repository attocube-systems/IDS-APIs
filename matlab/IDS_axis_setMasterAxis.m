function [errNo] = IDS_axis_setMasterAxis(tcp, axis)
% brief : Sets the master axis (for more information please refer to the IDS User Manual).
%
% param[in] tcp : TCP/IP connection ID
%           axis:  Axis which is operating as masteraxis [0..2]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.setMasterAxis", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.discard", "params": [], "id": 1, "api": 2}');
end
writeline(tcp, data_send);
data_receive = readline(tcp);

end


