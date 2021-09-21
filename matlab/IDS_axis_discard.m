function [errNo] = IDS_axis_discard(tcp)
% brief : Discards new axis settings. Necessary after JSON set commands instead of apply() in case of failure.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.discard", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



