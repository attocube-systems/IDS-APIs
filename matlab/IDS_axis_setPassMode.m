function [errNo] = IDS_axis_setPassMode(tcp, mode)
% brief : Sets the desired pass mode. Effectively this mode defines, if the correction factor of two (necessary for measurements in optical dual pass configuration) is applied.
%
% param[in] tcp : TCP/IP connection ID
%           mode:  0 = single pass; 1 = dual pass
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.setPassMode", "params": [%i], "id": 1, "api": 2}', mode);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.axis.discard", "params": [], "id": 1, "api": 2}');
end
writeline(tcp, data_send);
data_receive = readline(tcp);

end


