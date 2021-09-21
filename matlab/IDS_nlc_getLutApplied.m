function [errNo, apply] = IDS_nlc_getLutApplied(tcp, axis)
% brief : Returns whether a LUT is applied or not for a given axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS of which the LUT apply rule is queried
% param[out]
%           errNo: int32
%            Error number if an error occured while quering the LUT apply rule
%           apply: boolean
%            True, if LUT is applied on this axis else False


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.getLutApplied", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
apply = data.result (2);


end


