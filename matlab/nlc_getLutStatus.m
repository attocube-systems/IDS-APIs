function [warningNo, status] = nlc_getLutStatus(tcp, axis)
% brief : Reads out whether the LUT is available or not for a specific measurement axis.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           warningNo: warning code, can be converted into a string using the errorNumberToString function
%           status: true if a LUT exists, else false


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.getLutStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

warningNo = data.result(1);
status = data.result(2);


end