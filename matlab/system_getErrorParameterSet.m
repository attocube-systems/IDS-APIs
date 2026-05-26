function [value_errNo, value_setnumber] = system_getErrorParameterSet(tcp)
% brief : Gets the applied error parameter set.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_setnumber: setnumber 1 = New defaults from 2.0.0: more senstive beam interrupt detection/n2 = Old defaults till 1.9.3: less senstive beam interrupt detection (legacy version)


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.system.getErrorParameterSet", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_setnumber = data.result(2);


end