function [value_errNo] = system_setInitMode(tcp, mode)
% brief : Sets the mode for the initialization procedure that is performed when starting a measurement.
%
% param[in] tcp: TCP/IP connection ID
%           mode: 0 = High Accuracy Initialization; 1 = Quick Initialization
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.system.setInitMode", "params": [%i], "id": 1, "api": 2}', mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end