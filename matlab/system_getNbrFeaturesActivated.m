function [value_errNo, value_nbr] = system_getNbrFeaturesActivated(tcp)
% brief : Reads out the number of the activated features on the device.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_nbr: nbr the number of activated features


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.system.getNbrFeaturesActivated", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_nbr = data.result(2);


end