function [value_warningNo, value_contrast, value_baseline, value_mixcontrast] = adjustment_getContrastInPermille(tcp, axis)
% brief : This function can be used to monitor the alignment contrast (peak-to-peak of the basic interference signal amplitude) and the baseline (its offset) during alignment mode.
%
% param[in] tcp: TCP/IP connection ID
%           axis: [0|1|2]
% param[out]
%           value_warningNo: warningNo warning code, can be converted into a string using the errorNumberToString function
%           value_contrast: contrast contrast of the base band signal in permille
%           value_baseline: baseline offset of the contrast measurement in permille
%           value_mixcontrast: mixcontrast lower contrast measurement when measuring a mixed contrast (indicated by error code)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.sen.adjustment.getContrastInPermille", "params": [%i], "id": 1, "api": 2}', axis);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_warningNo = data.result(1);
value_contrast = data.result(2);
value_baseline = data.result(3);
value_mixcontrast = data.result(4);


end