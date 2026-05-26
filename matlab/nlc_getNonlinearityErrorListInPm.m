function [errNo, histogram] = nlc_getNonlinearityErrorListInPm(tcp, axis)
% brief : Returns a string containing a serialized list of the measured nonlinearities in pm for the current measurement. The returned data represents peak-to-peak values of the single fringes based on the most recent successful estimation performed by createLut() or analyzeNonlinearities(). It can be visualized as a histogram to analyze the distribution and magnitude of the residual nonlinearities. If no estimation has been performed, the function returns an error.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           histogram: JSON-encoded string containing a list of the nonlinearity residuals


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.getNonlinearityErrorListInPm", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
histogram = data.result(2);


end