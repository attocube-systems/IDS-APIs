function [errNo, enable] = IDS_pilotlaser_getEnabled(tcp)
% brief : Reads out whether the pilot laser is enabled or not.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           enable: enable true = enabled; false = disabled

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.pilotlaser.getEnabled", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enable = data.result (2);


end



