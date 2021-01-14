function [errNo, histogram] = IDS_nlc_getHistogram(tcp, axis)
% brief : Returns a histogram of the measured nonlinearity errors obtained from the last call of createLut or estimateNonlinearites.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS
% param[out]
%           errNo: int32
%            Error number if one occured during retrieving the histogram
%           histogram: string
%            Json dumped histogram array


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.getHistogram", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
histogram = data.result {2, 1};


end


