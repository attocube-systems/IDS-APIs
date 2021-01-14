function [errNo] = IDS_realtime_setLinearRange(tcp, rangenumber)
% brief : Sets the range number of Linear/Analog output mode.
%
% param[in] tcp : TCP/IP connection ID
%           rangenumber:  N, Linear Analog Range is +-2^(N+11) pm, with N \\in [0, 34]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setLinearRange", "params": [%i], "id": 1, "api": 2}', rangenumber);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


