function [errNo, enabled] = nlc_getLutDuringInit(tcp)
% brief : Reads out the current configuration of the LUT creation during the measurement initialization.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           enabled: true for create LUT during measurement initialization, else false


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.getLutDuringInit", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
enabled = data.result(2);


end