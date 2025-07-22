function [errNo, pressure] = manual_getPressureInHPa(tcp, axis)
% brief : Reads out the manually configured air pressure for compensation mode 1.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]Parameter has to be -1 for the moment,individual axes will be supported in the next firmware release
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           pressure: value in hPa


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.manual.getPressureInHPa", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
pressure = data.result(2);


end