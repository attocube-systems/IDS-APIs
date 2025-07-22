function [value_errNo] = system_resetError(tcp, performRenormalization)
% brief : Resets a measurement error that has been raised with the aim to continue the interrupted measurement./nIt is configurable if an additional renormalization process (please refer to the device user manual) should be performed or not./n/n  This function can be used in two cases:/n 	1.
%
% param[in] tcp: TCP/IP connection ID
%           performRenormalization: true = enable; false = disable
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.system.resetError", "params": [%i], "id": 1, "api": 2}', performRenormalization);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end