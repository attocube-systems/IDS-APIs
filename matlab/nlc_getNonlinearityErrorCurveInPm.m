function [errNo, curve] = nlc_getNonlinearityErrorCurveInPm(tcp, axis)
% brief : Returns a string containing a serialized list of the residual nonlinearities in pm for the current measurement. The returned values represent the median nonlinearity error curve within one interferometric fringe and are based on the most recent successful result of analyzeNonlinearities(). If no estimation has been performed, the function returns an error. The returned values are only updated after a successful call to analyzeNonlinearities().        Use createLUT() followed by setLutApplied() for nonlinearity compensation.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           curve: JSON-encoded string containing an array of 512 integer values representing the error curve


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.getNonlinearityErrorCurveInPm", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
curve = data.result(2);


end