function [errNo, resolution] = IDS_realtime_getResolutionHsslLow(tcp)
% brief : Reads out the HSSL resolution low bit.#
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           resolution: resolution Resolution in the range of [0..46]

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getResolutionHsslLow", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
resolution = data.result (2);


end



