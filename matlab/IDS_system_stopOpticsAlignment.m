function [errNo] = IDS_system_stopOpticsAlignment(tcp)
% brief : Stops the optical alignment system state.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo Error on initiating the system mode change

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.stopOpticsAlignment", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



