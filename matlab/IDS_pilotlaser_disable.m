function [errNo] = IDS_pilotlaser_disable(tcp)
% brief : Disables the pilot laser.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.pilotlaser.disable", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



