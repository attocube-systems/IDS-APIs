function [errNo, enabled] = IDS_realtime_getAafEnabled(tcp)
% brief : Checks if the anti-aliasing filter is enabled.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           enabled: enabled  0 - the Anti-Aliasing Filter is disabled 
%             1 - the Anti-Aliasing Filter is enabled

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.realtime.getAafEnabled", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
enabled = data.result (2);


end



