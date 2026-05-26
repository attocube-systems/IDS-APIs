function [value_errNo, value_enableFineTuning] = system_getOptimizeParametersDuringInit(tcp)
% brief : Reads out the current parameter optimization configuration used for the automatic system compensation.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_enableFineTuning: enableFineTuning true = enable; false = disable


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.system.getOptimizeParametersDuringInit", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_enableFineTuning = data.result(2);


end