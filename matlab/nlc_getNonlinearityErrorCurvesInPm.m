function [errNo, curves] = nlc_getNonlinearityErrorCurvesInPm(tcp, axis)
% brief : Returns a string containing a serialized matrix of nonlinearity error curves in pm for the current measurement. The returned values are based on the most recent successful estimation performed by createLut() or analyzeNonlinearities(). Each row represents the nonlinearity error curve of one measured interferometric fringe. If no estimation has been performed, the function returns an error.        For the median nonlinearity error curve or static LUT calculated from these individual fringes, use getNonlinearityErrorCurveInPm() or getLutInPm(), respectively.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           curves: JSON-encoded string containing a 2-dimensional array representing multiple error curves


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.getNonlinearityErrorCurvesInPm", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
curves = data.result(2);


end