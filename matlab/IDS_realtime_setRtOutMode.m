function [errNo] = IDS_realtime_setRtOutMode(tcp, value)
% brief : Sets the real time output mode.
%
% param[in] tcp : TCP/IP connection ID
%           value:  rtOutMode 0 = HSSL (TTL), 1 = HSSL (LVDS), 2 = AquadB (TTL), 
%            3 = AquadB (LVDS), 4 = SinCos (TTL Error Signal), 
%            5 = SinCos (LVDS Error Signal), 6 = Linear (TTL), 7 = Linear (LVDS), 
%            8 = BiSS-C, 9 = Deactivated
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setRtOutMode", "params": [%i], "id": 1, "api": 2}', value);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.discard", "params": [], "id": 1, "api": 2}');
end
fprintf(tcp, data_send);
data_receive = fscanf(tcp);

end


