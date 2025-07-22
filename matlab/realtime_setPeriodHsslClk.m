function [value_errNo] = realtime_setPeriodHsslClk(tcp, period)
% brief : Set the HSSL period clock.
%
% param[in] tcp: TCP/IP connection ID
%           period: value from 40 ns to 10200 ns
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.setPeriodHsslClk", "params": [%i], "id": 1, "api": 2}', period);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.discard", "params": [], "id": 1, "api": 2}');
end
writeline(tcp, data_send);
data_receive = readline(tcp);

end