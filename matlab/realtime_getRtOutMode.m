function [value_errNo, value_rtOutMode] = realtime_getRtOutMode(tcp)
% brief : Reads out the current real-time output mode.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_rtOutMode: rtOutMode 0 = HSSL (LVTTL), 1 = HSSL (LVDS), 2 = AquadB (LVTTL),/n3 = AquadB (LVDS), 4 = Sin/Cos (LVTTL error signal),/n5 = Sin/Cos (LVDS error signal), 6 = Linear (LVTTL error signal), 7 = Linear (LVDS error signal),/n8 = BiSS-C, 9 = Deactivated


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.realtime.getRtOutMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_rtOutMode = data.result(2);


end