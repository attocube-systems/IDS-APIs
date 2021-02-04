function [errNo] = IDS_system_getSystemError(tcp)
% brief : Reads out the system error. The function returns an integer number which represents 
%           the error. The number can be converted into a string using the errorNumberToString 
%           function.
%           Use this function to query errors occured while starting and running measurements and alignments.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: errNo

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.getSystemError", "params": [], "id": 1, "api": 2}');

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end



