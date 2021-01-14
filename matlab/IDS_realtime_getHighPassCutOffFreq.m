function [errNo, value] = IDS_realtime_getHighPassCutOffFreq(tcp)
% brief : Reads out the high pass filter number of Linear/Analog output mode.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           value: value N, Linear Analog High Pass Cut-Off freqency is 1600/2^N kHz, with N \\in [1,24]

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getHighPassCutOffFreq", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
value = data.result (2);


end



