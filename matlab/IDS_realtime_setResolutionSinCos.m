function [errNo] = IDS_realtime_setResolutionSinCos(tcp, value)
% brief : Sets the Sine-Cosine and AquadB resolution.
%
% param[in] tcp : TCP/IP connection ID
%           value:  resolution 1pm to 65535pm
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.setResolutionSinCos", "params": [%i], "id": 1, "api": 2}', value);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);

if errNo == 0
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.apply", "params": [], "id": 1, "api": 2}');
else
    data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.discard", "params": [], "id": 1, "api": 2}');
end
fprintf(tcp, data_send);
data_receive = fscanf(tcp);

end


