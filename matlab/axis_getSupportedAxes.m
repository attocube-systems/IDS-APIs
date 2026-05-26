function [value_errNo, value_supportedAxis1, value_supportedAxis2, value_supportedAxis3] = axis_getSupportedAxes(tcp)
% brief : Gets supported IDS axes for application.
%
% param[in] tcp: TCP/IP connection ID
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok
%           value_supportedAxis1: supportedAxis1 true = supported; false = unsupported
%           value_supportedAxis2: supportedAxis2 true = supported; false = unsupported
%           value_supportedAxis3: supportedAxis3 true = supported; false = unsupported


data_send = sprintf('{"jsonrpc": "2.0", "pid": "sen", "method": "com.attocube.sen.axis.getSupportedAxes", "params": [], "id": 1, "api": 2}');

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);
value_supportedAxis1 = data.result(2);
value_supportedAxis2 = data.result(3);
value_supportedAxis3 = data.result(4);


end