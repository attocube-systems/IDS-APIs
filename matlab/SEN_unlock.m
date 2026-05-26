function [value_errNo] = SEN_unlock(tcp, password)
% brief : Unlocks the device. Afterwards, the device functions are accessible without any password. For grant access without unlocking the device, please use the grantAccess function.
%
% param[in] tcp: TCP/IP connection ID
%           password: current password string
% param[out]
%           value_errNo: errNo errorCode


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "unlock", "params": [%s], "id": 1, "api": 2}', password);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end