function [errNo, pressure] = IDS_manual_getPressureInHPa(tcp, axis)
% brief : Reads out the manually configured Pressure (compensation mode 1).
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to get the pressure for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           pressure: double
%            pressure in hPa


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.manual.getPressureInHPa", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
pressure = data.result (2);


end


