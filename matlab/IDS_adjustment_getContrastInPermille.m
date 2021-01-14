function [warningNo, contast, baseline, mixcontrast] = IDS_adjustment_getContrastInPermille(tcp, axis)
% brief : This function can be used to monitor the alignment contrast (peak-to-peak of the 
%           basic interference signal amplitude) and the basline (its offset) during alignment 
%           mode. It is used to monitor and optimize the optical alignment such that it allows the 
%           successful initialization of a measurement. To monitor the optical contrast during a 
%           running measurement, please use the getAxisSignalQuality function.
%           
%           Important: The baseline and contrast needs to be added, otherwise an overload can 
%           occure without being recognized. Example: baseline 150‰ and contrast 850‰. Just 
%           from the contrast it looks good. Adding the baseline the overload is visible.
%
% param[in] tcp : TCP/IP connection ID
%           axis:  Axis to get the value from [0..2]
% param[out]
%           warningNo: warningNo
%           contast: contast Contrast of the base band signal in ‰
%           baseline: baseline Offset of the contrast measurement in ‰
%           mixcontrast: mixcontrast lower contrast measurment when measuring a mix contrast (indicated by error code)


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.adjustment.getContrastInPermille", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

warningNo = data.result (1);
contast = data.result (2);
baseline = data.result (3);
mixcontrast = data.result (4);


end


