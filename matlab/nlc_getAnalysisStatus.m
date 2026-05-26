function [warningNo, status] = nlc_getAnalysisStatus(tcp, axis)
% brief : Reads out whether the analysis of nonlinearities was performed or not for a specific measurement axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           warningNo: warning code, can be converted into a string using the errorNumberToString function
%           status: true if analysis data is available, else false


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.getAnalysisStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

warningNo = data.result(1);
status = data.result(2);


end