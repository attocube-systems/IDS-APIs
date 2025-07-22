function [value_errNo, value_period] = realtime_getPeriodSinCosClk(tcp)
% brief : Reads out the Sin/Cos and AquadB period clock.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_period: period value from 40 ns to 10200 ns


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getPeriodSinCosClk", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_period = data.result(2);


end