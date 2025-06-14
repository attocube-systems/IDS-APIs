function [errNo, temperature] = IDS_manual_getTemperatureInDegrees(tcp, axis)
% brief : Reads out the manually configured Temperature (compensation mode 1).
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to set the temperature for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           temperature: double
%            temperature in degree celsius


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.manual.getTemperatureInDegrees", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
temperature = data.result (2);


end


