function [warningNo, contrast, baseline] = IDS_displacement_getSignalQuality(tcp, axis)
% brief : This function can be used to monitor the alignment contrast (peak-to-peak of the basic 
%           interference signal amplitude) and the basline (its offset) during a running 
%           measurement. Please note that the getAxisSignalQuality function output is only 
%           updated when a displacement is measured. This means that angular misalignments 
%           without displacement changes on the measurement axes cannot be detected. 
%           Furthermore, we recommend using the IDS high accuracy initialization to obtain 
%           correct values directly after measurement initialization. When using the quick 
%           initialization, the initial value might be falsified at first, but correct after some detected 
%           measurement (because it is updated with the correct value then).
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
% param[out]
%           warningNo: warningNo Warning code, can be converted into a string using the errorNumberToString function
%           contrast: contrast Contrast of the base band signal in ‰
%           baseline: baseline Offset of the contrast measurement in ‰


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.getSignalQuality", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

warningNo = data.result (1);
contrast = data.result (2);
baseline = data.result (3);


end


