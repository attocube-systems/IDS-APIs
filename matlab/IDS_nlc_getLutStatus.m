function [creationWarning, status] = IDS_nlc_getLutStatus(tcp, axis)
% brief : Returns if a LUT is available and if warnings or errors occurred during creation.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS of which the status of the LUT should be returned
% param[out]
%           creationWarning: int32
%            Error or warning number if one occured while creating the LUT, 0 in case of no error
%           status: boolean
%            True, if a LUT exists else False


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.getLutStatus", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

creationWarning = data.result (1);
status = data.result (2);


end


