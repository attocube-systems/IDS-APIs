function [value_errNo] = system_setAutoRestart(tcp, enable)
% brief : Enables or disables the automatic measurement restart after reboot.
%
% param[in] tcp: TCP/IP connection ID
%           enable: true = enable; false = disable
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.system.setAutoRestart", "params": [%i], "id": 1, "api": 2}', enable);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end