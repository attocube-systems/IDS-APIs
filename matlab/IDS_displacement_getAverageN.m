function [errNo, averageN] = IDS_displacement_getAverageN(tcp)
% brief : Reads-out the averaging (lowpass) parameter N. The averaging time is calculated by 
%           (2^N)*40ns, where N is the averaging value. Please refere to the manual for a table with stopband and 3dB cut-off frequency.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           averageN: averageN A value from 0 to 24

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.getAverageN", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
averageN = data.result (2);


end



