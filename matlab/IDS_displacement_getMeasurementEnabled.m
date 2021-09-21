function [errNo, enable] = IDS_displacement_getMeasurementEnabled(tcp)
% brief : This function can be used to see if the measurement is running
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           enable: enable true = enabled; false = disabled

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.getMeasurementEnabled", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enable = data.result (2);


end



