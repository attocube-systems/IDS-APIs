function [errNo, resolution] = IDS_realtime_getResolutionHsslHigh(tcp)
% brief : Reads out the HSSL resolution high bit.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           resolution: resolution Resolution in the Range of [0..46]

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getResolutionHsslHigh", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
resolution = data.result (2);


end



