function [errNo, window] = IDS_realtime_getAafWindow(tcp)
% brief : Returns the current filter window of the anti-aliasing filter.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           window: window 0 = Rectangular,
%             1 = Cosine,
%             2 = Cosine^2,
%             3 = Hamming,
%             4 = Raised Cosine,
%             5 = Automatic

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getAafWindow", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
window = data.result (2);


end



