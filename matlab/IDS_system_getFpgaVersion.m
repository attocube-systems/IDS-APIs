function [errNo, version] = IDS_system_getFpgaVersion(tcp)
% brief : Reads out the IDS FPGA version.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo
%           version: version Version in the form X.Y.Z

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.getFpgaVersion", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
version = data.result {2, 1};


end



