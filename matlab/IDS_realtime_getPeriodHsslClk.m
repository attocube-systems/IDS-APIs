function [errNo, period] = IDS_realtime_getPeriodHsslClk(tcp)
% brief : Reads out the HSSL period clock.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           period: period Period in the Range of [40ns..10200ns]

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getPeriodHsslClk", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
period = data.result (2);


end



