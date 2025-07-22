function [errNo] = nlc_setVelocityThresholds(tcp, velocityOn, velocityOff)
% brief : Sets the threshold velocities for mode 2 of the setDynamicNormalization function. By default, the normalization in mode 2 is frozen for velocities below 5 µm/s and switches to dynamic mode for velocities above 10 µm/s.
%
% param[in] tcp: TCP/IP connection ID
%           velocityOn: target velocity in µm/s (default: 10 µm/s)
%           velocityOff: target velocity in µm/s (default: 5 µm/s)
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.setVelocityThresholds", "params": [%i, %i], "id": 1, "api": 2}', velocityOn, velocityOff);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);


end