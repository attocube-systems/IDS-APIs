function [value_errNo, value_FWversion] = system_getFirmwareVersion(tcp)
% brief : Gets the firmware version of the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code to translate
%           value_FWversion: FWversion firmware version


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.getFirmwareVersion", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_FWversion = data.result(2);


end