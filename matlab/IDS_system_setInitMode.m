function [errNo] = IDS_system_setInitMode(tcp, mode)
% brief : Sets the mode for the initialization procedure that is performed when starting a measurement.
%
% param[in] tcp : TCP/IP connection ID
%           mode:  0 = High Accuracy Initialization; 1 = Quick Initialization
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.setInitMode", "params": [%i], "id": 1, "api": 2}', mode);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


