function [errNo, velocityOn, velocityOff] = IDS_nlc_getVelocityThresholds(tcp)
% brief : Returns the threshold velocity (in µm/s) for mode 2 of setDynamicNormalization.
%
% param[in] tcp : TCP/IP connection ID
% param[out]
%           errNo: int32
%            Error number if an error occured
%           velocityOn: int32
%            Velocity of the target in µm/s when to switch the normalization on (default: 10 µm/s)
%           velocityOff: int32
%            Velocity of the target in µm/s when to switch the normalization off (default: 5 µm/s)

data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.getVelocityThresholds", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
velocityOn = data.result (2);
velocityOff = data.result (3);


end



