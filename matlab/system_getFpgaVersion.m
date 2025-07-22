function [value_errNo, value_version] = system_getFpgaVersion(tcp)
% brief : Reads out the device FPGA version.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_version: version version in the form X.Y.Z


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.system.getFpgaVersion", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_version = data.result(2);


end