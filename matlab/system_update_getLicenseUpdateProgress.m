function [value_errNo, value_progress] = system_update_getLicenseUpdateProgress(tcp)
% brief : Gets the progress of running license update.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_progress: progress value in %


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.update.getLicenseUpdateProgress", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_progress = data.result(2);


end