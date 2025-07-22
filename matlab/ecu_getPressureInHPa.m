function [errNo, pressure] = ecu_getPressureInHPa(tcp)
% brief : Reads out the ECU measured air pressure in hPa.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           pressure: value in hPa


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.getPressureInHPa", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
pressure = data.result(2);


end