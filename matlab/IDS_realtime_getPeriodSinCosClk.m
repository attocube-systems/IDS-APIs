function [errNo, period] = IDS_realtime_getPeriodSinCosClk(tcp)
% brief : Reads out the Sine-Cosine and AquadB period clock.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           period: period 40ns to 10200ns

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getPeriodSinCosClk", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
period = data.result (2);


end



