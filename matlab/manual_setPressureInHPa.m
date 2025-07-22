function [errNo] = manual_setPressureInHPa(tcp, axis, pressure)
% brief : Sets the manually configured air pressure for compensation mode 1. The input range is defined to 800 to 1200 hPa (valid range for the Ciddor Equation).
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]Parameter has to be -1 for the moment,individual axes will be supported in the next firmware release
%           pressure: value from 800 hPa to 1200 hPa
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.manual.setPressureInHPa", "params": [%i, %d], "id": 1, "api": 2}', axis, pressure);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end