function [errNo] = IDS_realtime_setPeriodSinCosClk(tcp, value)
% brief : Sets the Sine-Cosine and AquadB period clock. The value has to be a multiple of 40ns. If not, the value automatically is rounded.
%
% param[in] tcp : TCP/IP connection ID
%           value:  period 40ns to 10200ns
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setPeriodSinCosClk", "params": [%i], "id": 1, "api": 2}', value);

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


