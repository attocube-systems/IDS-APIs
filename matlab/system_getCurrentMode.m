function [value_errNo, value_mode] = system_getCurrentMode(tcp)
% brief : Reads out the current device system state.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_mode: mode "system idle", "measurement starting", "measurement running", "measurement restarting",/n"optics alignment starting", "optics alignment running", "test channels enabled"


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.system.getCurrentMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_mode = data.result(2);


end