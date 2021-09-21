function [errNo] = IDS_nlc_estimateNonlinearities(tcp, axis)
% brief : Estimates the nonlinearity error for the current device settings without changing or updating any settings.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS of which the nonlinearity error is to be estimated
% param[out]
%           errNo: int32
%            Error number if one occured while estimating the nonlinearity error


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.estimateNonlinearities", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


