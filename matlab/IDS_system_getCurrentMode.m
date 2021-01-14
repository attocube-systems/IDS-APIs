function [errNo, mode] = IDS_system_getCurrentMode(tcp)
% brief : Reads out the current IDS system state.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           mode: mode Values: "system idle", "measurement starting", "measurement running", "optics alignment starting", "optics alignment running", "test channels enabled"

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.getCurrentMode", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
mode = data.result {2, 1};


end



