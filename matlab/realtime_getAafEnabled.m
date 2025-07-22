function [value_errNo, value_enabled] = realtime_getAafEnabled(tcp)
% brief : Checks if the anti-aliasing filter is enabled.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_enabled: enabled true = enabled; false = disabled


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getAafEnabled", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_enabled = data.result(2);


end