function [errNo] = nlc_analyzeNonlinearities(tcp, axis)
% brief : Estimates the nonlinearities for the current measurement without modifying any settings. After applying a LUT, this function can be used to determine the effectiveness of the applied LUT. The error curve as a function of phase can be retrieved using getNonlinearityErrorCurveInPm(). The error list, for example for histogram evaluation, can be retrieved using getNonlinearityErrorListInPm(). If the estimation fails, for example due to an unstable measurement setup, the previously stored estimation results are not updated. In this case, subsequent calls to the corresponding get-functions return the last valid results.        This function is only available in the "measurement running" state. While analysis, the device state changes to "measurement starting" (please refer to the getCurrentMode function).
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.analyzeNonlinearities", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end