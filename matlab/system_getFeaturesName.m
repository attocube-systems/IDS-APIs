function [value_errNo, value_names] = system_getFeaturesName(tcp, featurenumber)
% brief : Converts the device feature number to its corresponding name.
%
% param[in] tcp: TCP/IP connection ID
%           featurenumber: number of features
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_names: names name of the corresponding feature


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.system.getFeaturesName", "params": [%i], "id": 1, "api": 2}', featurenumber);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_names = data.result(2);


end