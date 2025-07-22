function [value_errNo] = system_setDeviceName(tcp, name)
% brief : Sets custom name for the device.
%
% param[in] tcp: TCP/IP connection ID
%           name: device name
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.setDeviceName", "params": [%s], "id": 1, "api": 2}', name);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end