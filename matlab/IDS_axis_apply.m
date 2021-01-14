function [errNo] = IDS_axis_apply(tcp)
% brief : Applies new axis settings. Necessary after JSON set commands.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.apply", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



