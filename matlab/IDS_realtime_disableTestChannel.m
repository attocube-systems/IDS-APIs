function [errNo] = IDS_realtime_disableTestChannel(tcp)
% brief : Disables the test channel.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.disableTestChannel", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



