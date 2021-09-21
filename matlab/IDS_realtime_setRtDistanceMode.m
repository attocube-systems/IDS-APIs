function [errNo] = IDS_realtime_setRtDistanceMode(tcp, value)
% brief : Sets the distance mode. Depending on the configuration of the IDS the mode can be 
%           Displacement (returns 1), Absolute Distance (returns 2) or Vibrometry (returns 3).
%
% param[in] tcp : TCP/IP connection ID
%           value:  1 = Displacement (HSSL mode and Linear Mode) 
%            2 = Absolute Distance (HSSL mode only) 
%            3 = Vibrometry (Linear mode)
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setRtDistanceMode", "params": [%i], "id": 1, "api": 2}', value);

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


