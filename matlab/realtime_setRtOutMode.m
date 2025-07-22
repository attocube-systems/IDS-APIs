function [value_errNo] = realtime_setRtOutMode(tcp, rtOutMode)
% brief : Sets the real-time output mode.
%
% param[in] tcp: TCP/IP connection ID
%           rtOutMode: 0 = HSSL (LVTTL), 1 = HSSL (LVDS), 2 = AquadB (LVTTL),/n3 = AquadB (LVDS), 4 = Sin/Cos (LVTTL error signal),/n5 = Sin/Cos (LVDS error signal), 6 = Linear (LVTTL error signal), 7 = Linear (LVDS error signal),/n8 = BiSS-C, 9 = Deactivated
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.setRtOutMode", "params": [%i], "id": 1, "api": 2}', rtOutMode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.discard", "params": [], "id": 1, "api": 2}');
end
writeline(tcp, data_send);
data_receive = readline(tcp);

end