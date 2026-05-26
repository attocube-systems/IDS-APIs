function [errNo] = nlc_createLut(tcp, axis)
% brief : Estimates the nonlinearities for a specific measurement axis and creates a new LUT based on the result. The initial nonlinearities can be analyzed using getNonlinearityErrorListInPm(). The generated LUT can be applied with setLutApplied() and retrieved with getLutInPm(). After applying a LUT, this function can be called again for further optimization. The newly generated LUT is then combined with the existing LUT. If the estimation fails, for example due to an unstable measurement setup, the previously stored LUT results are not updated. In this case, subsequent calls to the corresponding get-functions return the last valid results.        This function is only available in the "measurement running" state. While the LUT is being created, the device state changes to "measurement starting" (please refer to the getCurrentMode function).
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.createLut", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end