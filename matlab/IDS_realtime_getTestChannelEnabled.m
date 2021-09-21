function [errNo, enabled] = IDS_realtime_getTestChannelEnabled(tcp)
% brief : Checks if the test channel is enabled
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           enabled: enabled true = enabled, false = disabled

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getTestChannelEnabled", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end



