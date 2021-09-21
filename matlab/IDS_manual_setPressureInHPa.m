function [errNo] = IDS_manual_setPressureInHPa(tcp, axis, pressure)
% brief : Sets the manually configured Pressure (compensation mode 1). The input range is defined to 800 to 1200 hPa (valid range for the Ciddor Equation).
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to set the pressure for-
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
%           pressure: 
%            pressure in hPa
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.manual.setPressureInHPa", "params": [%i, %d], "id": 1, "api": 2}', axis, pressure);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


