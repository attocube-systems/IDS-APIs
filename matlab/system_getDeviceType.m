function [value_errNo, value_type] = system_getDeviceType(tcp)
% brief : Reads out the device type.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_type: type type of the device (e.g. "IDS3010")


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.system.getDeviceType", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_type = data.result(2);


end