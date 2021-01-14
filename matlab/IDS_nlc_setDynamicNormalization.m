function [errNo] = IDS_nlc_setDynamicNormalization(tcp, axis, mode)
% brief : Sets the normalization mode of a specific axis.
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis [0|1|2] of the IDS of which the normalization mode should be set
%           mode: 
%            Normalization Mode
%                0    Dynamic normalization (default)
%                1    Normalization frozen (for slow target drifts)
%                2    Automatic alternation between mode 0 and 1 depending on the target velocity
% param[out]
%           errNo: int32
%            Error number if an error occured during switching the normalization mode


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.setDynamicNormalization", "params": [%i, %i], "id": 1, "api": 2}', axis, mode);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


