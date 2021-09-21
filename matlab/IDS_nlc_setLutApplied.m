function [errNo] = IDS_nlc_setLutApplied(tcp, axis, apply)
% brief : Sets the apply rule for the given axis
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS of which the apply rule should be set
%           apply: 
%            True for applying a LUT, False for disabling a LUT
% param[out]
%           errNo: int32
%            Error number if an error occured while enabling or disabling a LUT


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.setLutApplied", "params": [%i, %i], "id": 1, "api": 2}', axis, apply);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


