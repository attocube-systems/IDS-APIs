function [errNo] = IDS_displacement_setAverageN(tcp, value)
% brief : Sets the averaging (lowpass) parameter N. The averaging time is calculated by 
%           (2^N)*40ns, where N is the averaging value. Please refere to the manual for a table with stopband and 3dB cut-off frequency.
%
% param[in] tcp : TCP/IP connection ID
%           value:  AverageN value from 0 to 24
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.setAverageN", "params": [%i], "id": 1, "api": 2}', value);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


