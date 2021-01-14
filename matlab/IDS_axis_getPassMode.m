function [errNo, mode] = IDS_axis_getPassMode(tcp)
% brief : Reads out the current pass mode.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           mode: mode 0 = single; pass 1 = dual pass

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.getPassMode", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end



