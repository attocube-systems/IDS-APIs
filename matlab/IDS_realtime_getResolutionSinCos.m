function [errNo, resolution] = IDS_realtime_getResolutionSinCos(tcp)
% brief : Reads out the Sine-Cosine and AquadB resolution.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           resolution: resolution 1pm to 65535pm

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getResolutionSinCos", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
resolution = data.result (2);


end



