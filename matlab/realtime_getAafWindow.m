function [value_errNo, value_window] = realtime_getAafWindow(tcp)
% brief : Returns the current filter window of the anti-aliasing filter.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_window: window 0 = Rectangular,/n1 = Cosine,/n2 = Cosine^2,/n3 = Hamming,/n4 = Raised Cosine (default)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getAafWindow", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_window = data.result(2);


end