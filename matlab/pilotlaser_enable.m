function [errNo] = pilotlaser_enable(tcp)
% brief : Enables the pilot laser.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.pilotlaser.enable", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end