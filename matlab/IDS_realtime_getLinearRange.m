function [errNo, rangenumber] = IDS_realtime_getLinearRange(tcp)
% brief : Reads out the range number of Linear/Analog output mode.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           rangenumber: rangenumber N, Linear Analog Range is +-2^(N+11) pm, with N \\in [0, 34]

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getLinearRange", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
rangenumber = data.result (2);


end



