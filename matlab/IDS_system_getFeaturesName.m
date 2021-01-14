function [errNo, names] = IDS_system_getFeaturesName(tcp, featurenumber)
% brief : Converts the IDS feature number to its corresponding name.
%
% param[in] tcp : TCP/IP connection ID
%           featurenumber:  Number of feature
% param[out]
%           errNo: errNo
%           names: names The name of the corresponding feature


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.getFeaturesName", "params": [%i], "id": 1, "api": 2}', featurenumber);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
names = data.result {2, 1};


end


