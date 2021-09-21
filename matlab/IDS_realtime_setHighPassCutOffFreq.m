function [errNo] = IDS_realtime_setHighPassCutOffFreq(tcp, value)
% brief : Sets the high pass filter number of Linear/Analog output mode.
%
% param[in] tcp : TCP/IP connection ID
%           value:  N, Linear Analog High Pass Cut-Off freqency is 1600/2^N kHz, with N \\in [1,24]
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setHighPassCutOffFreq", "params": [%i], "id": 1, "api": 2}', value);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


