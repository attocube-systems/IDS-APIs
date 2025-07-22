function [errNo] = ecu_setRefractiveIndexCompensationMode(tcp, axis, mode)
% brief : Sets the refractive index compensation mode.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]Parameter has to be -1 for the moment,individual axes will be supported in the next firmware release
%           mode: 0 = direct ECU mode 1 = uses refractive index calculated from the manually set values2 = uses manually set refrative index
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.setRefractiveIndexCompensationMode", "params": [%i, %i], "id": 1, "api": 2}', axis, mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end