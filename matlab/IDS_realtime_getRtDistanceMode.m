function [errNo, linearmode] = IDS_realtime_getRtDistanceMode(tcp)
% brief : Reads out the distance mode. Depending on the realtime output mode, the mode can 
%           be Displacement (returns 1), Absolute Distance (returns 2) or Vibrometry (returns 3).
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           linearmode: linearmode 1 = Displacement (Available in HSSL mode and Linear Mode) 
%            2 = Absolute Distance (Available in HSSL mode only) 
%            3 = Vibrometry (Available in Linear mode)

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getRtDistanceMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
linearmode = data.result (2);


end



