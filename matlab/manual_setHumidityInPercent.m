function [errNo] = manual_setHumidityInPercent(tcp, axis, humidity)
% brief : Sets the manually configured humidity for compensation mode 1. The input range is defined to 0 to 100 % (valid range for the Ciddor Equation).
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]Parameter has to be -1 for the moment,individual axes will be supported in the next firmware release
%           humidity: value from 0 % to 100 %
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.manual.setHumidityInPercent", "params": [%i, %d], "id": 1, "api": 2}', axis, humidity);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end