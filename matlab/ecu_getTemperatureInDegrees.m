function [errNo, temperature] = ecu_getTemperatureInDegrees(tcp)
% brief : Reads out the ECU measured air temperature in degrees Celsius.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           temperature: value in degrees Celsius


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getTemperatureInDegrees", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
temperature = data.result(2);


end