function [errNo] = IDS_ecu_disable(tcp)
% brief : Disables the ECU interface.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.disable", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



