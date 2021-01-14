function [errNo, nbr] = IDS_system_getNbrFeaturesActivated(tcp)
% brief : Reads out the amount of activated features activated on the IDS.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           nbr: nbr Gives the number of activated features.

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.getNbrFeaturesActivated", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
nbr = data.result (2);


end



