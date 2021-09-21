function [errNo] = IDS_realtime_setPeriodHsslClk(tcp, period)
% brief : Set the HSSL period clock. The value has to be a multiple of 40ns. If not, the value automatically is rounded.
%
% param[in] tcp : TCP/IP connection ID
%           period:  Period in the Range of [40ns..10200ns]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setPeriodHsslClk", "params": [%i], "id": 1, "api": 2}', period);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.discard", "params": [], "id": 1, "api": 2}');
end
writeline(tcp, data_send);
data_receive = readline(tcp);

end


