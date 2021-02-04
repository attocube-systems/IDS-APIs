function [errNo] = IDS_system_stopMeasurement(tcp)
% brief : Stops the displacement measurement system state.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo Error on initiating the system mode change

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.stopMeasurement", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



