function [errNo, temperature] = IDS_ecu_getTemperatureInDegrees(tcp)
% brief : Reads out the ECU measured air temperature in degrees Celsius.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           temperature: double
%            temperature in degrees C

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getTemperatureInDegrees", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
temperature = data.result (2);


end



