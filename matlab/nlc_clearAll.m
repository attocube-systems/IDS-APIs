function [errNo] = nlc_clearAll(tcp, axis)
% brief : Deactivates the active LUT and clears all associated data created by createLut() and analyzeNonlinearities(), including the cached results returned by getLutInPm(), getNonlinearityErrorCurveInPm(), getNonlinearityErrorCurvesInPm(), and getNonlinearityErrorListInPm().
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.clearAll", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end