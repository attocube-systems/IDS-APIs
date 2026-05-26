function [errNo] = nlc_setLutDuringInit(tcp, enabled)
% brief : Enables or disables the creation of the LUT during measurement initialization.
%
% param[in] tcp: TCP/IP connection ID
%           enabled: true for create LUT during measurement initialization, else false
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.nlc.setLutDuringInit", "params": [%i], "id": 1, "api": 2}', enabled);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end