function [errNo] = IDS_realtime_setResolutionHsslLow(tcp, value)
% brief : Sets the HSSL resolution low bit.
%
% param[in] tcp : TCP/IP connection ID
%           value:  Resolution in the Range of [0..46]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setResolutionHsslLow", "params": [%i], "id": 1, "api": 2}', value);

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


