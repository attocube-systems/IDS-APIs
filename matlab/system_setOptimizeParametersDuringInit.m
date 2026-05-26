function [value_errNo] = system_setOptimizeParametersDuringInit(tcp, enableFineTuning)
% brief : Enables or disables the parameter optimization used for the automatic system compensation.
%
% param[in] tcp: TCP/IP connection ID
%           enableFineTuning: true = enable; false = disable
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.system.setOptimizeParametersDuringInit", "params": [%i], "id": 1, "api": 2}', enableFineTuning);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end