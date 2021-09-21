function [errNo] = IDS_nlc_setVelocityThresholds(tcp, velocityOn, velocityOff)
% brief : Sets the threshold velocity (in µm/s) for mode 2 of setDynamicNormalization. By default, the normalization in mode 2 is frozen for velocities below 5 µm/s and switched to dynamic mode for velocities above 10 µm/s.
%
% param[in] tcp : TCP/IP connection ID
%           velocityOn: 
%            Velocity of the target in µm/s when to switch the normalization on (default: 10 µm/s)
%           velocityOff: 
%            Velocity of the target in µm/s when to switch the normalization off (default: 5 µm/s)
% param[out]
%           errNo: int32
%            Error number if an error occured


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.nlc.setVelocityThresholds", "params": [%i, %i], "id": 1, "api": 2}', velocityOn, velocityOff);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


