function [errNo, histogram] = nlc_getHistogram(tcp, axis)
% brief : Returns a histogram of the measured nonlinearity errors obtained from the last call of the createLut or estimateNonlinearites functions.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           histogram: histogram array


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.getHistogram", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
histogram = data.result(2);


end