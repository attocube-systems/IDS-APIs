function [errNo, rtOutMode] = IDS_realtime_getRtOutMode(tcp)
% brief : Reads out the current realtime output mode.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           rtOutMode: rtOutMode 0 = HSSL (TTL), 1 = HSSL (LVDS), 2 = AquadB (TTL), 
%            3 = AquadB (LVDS), 4 = SinCos (TTL Error Signal), 
%            5 = SinCos (LVDS Error Signal), 6 = Linear (TTL), 7 = Linear (LVDS), 
%            8 = BiSS-C, 9 = Deactivated

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getRtOutMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
rtOutMode = data.result (2);


end



