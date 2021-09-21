function [errNo, gap] = IDS_realtime_getPeriodHsslGap(tcp)
% brief : Reads out the HSSL period gap.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           gap: gap Number of clocks

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getPeriodHsslGap", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
gap = data.result (2);


end



