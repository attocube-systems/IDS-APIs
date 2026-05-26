function [value_errNo] = system_setErrorParameterSet(tcp, setnumber)
% brief : Sets the error parameter set.
%
% param[in] tcp: TCP/IP connection ID
%           setnumber: 1 = default mode: standard beam interruption detection (less sensitive)/n2 = strict mode: more sensitive beam interruption detection; improves responsiveness but may increase false positives
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.system.setErrorParameterSet", "params": [%i], "id": 1, "api": 2}', setnumber);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end