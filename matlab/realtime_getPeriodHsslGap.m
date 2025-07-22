function [value_errNo, value_gap] = realtime_getPeriodHsslGap(tcp)
% brief : Reads out the HSSL period gap as number of clocks.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_gap: gap value from 1 to 255


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getPeriodHsslGap", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_gap = data.result(2);


end