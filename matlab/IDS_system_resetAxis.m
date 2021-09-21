function [errNo] = IDS_system_resetAxis(tcp, axis)
% brief : Resets the position value of a specific measurement axis to zero.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.resetAxis", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


