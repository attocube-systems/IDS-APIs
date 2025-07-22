function [value_errNo, value_string] = system_about_getPackageLicense(tcp, pckg)
% brief : Get the license for a specific package.
%
% param[in] tcp: TCP/IP connection ID
%           pckg: string: Package name
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_string: string: license for this package


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.about.getPackageLicense", "params": [%s], "id": 1, "api": 2}', pckg);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_string = data.result(2);


end