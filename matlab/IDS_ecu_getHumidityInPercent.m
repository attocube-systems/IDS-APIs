function [errNo, humidity] = IDS_ecu_getHumidityInPercent(tcp)
% brief : Reads out the ECU measured air humidity in percent.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           humidity: double
%            humidity in %

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getHumidityInPercent", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
humidity = data.result (2);


end



