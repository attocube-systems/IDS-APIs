function [errNo, velocityOn, velocityOff] = nlc_getVelocityThresholds(tcp)
% brief : Returns the threshold velocities for mode 2 of the setDynamicNormalization function.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           errNo: error code, if there was an error, otherwise 0 for ok
%           velocityOn: target velocity in µm/s (default: 10 µm/s)
%           velocityOff: target velocity in µm/s (default: 5 µm/s)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.nlc.getVelocityThresholds", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result(1);
velocityOn = data.result(2);
velocityOff = data.result(3);


end