function [errNo] = IDS_manual_setTemperatureInDegrees(tcp, axis, temperature)
% brief : Sets the manually configured Temperature (compensation mode 1). The input range is defined to -40 to +100 °C (valid range for the Ciddor Equation).
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to set the temperature for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
%           temperature: 
%            temperature in degree celcius
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.manual.setTemperatureInDegrees", "params": [%i, %d], "id": 1, "api": 2}', axis, temperature);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


