function [errNo, mode] = IDS_system_getInitMode(tcp)
% brief : Returns the Initialization mode.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           mode: mode 0 = High Accuracy Initialization; 1 = Quick Initialization

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.getInitMode", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result (2);


end



