function [errNo] = IDS_system_startOpticsAlignment(tcp)
% brief : Starts the optical alignment system state.
%            Please query errors during starting and running alignments by system.getSystemError
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo Error on initiating the system mode change

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.startOpticsAlignment", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



