function [errNo, humidity] = IDS_manual_getHumidityInPercent(tcp, axis)
% brief : Reads out the manually configured humidity (compensation mode 1).
%
% param[in] tcp : TCP/IP connection ID
%           axis: 
%            Axis to get the humidity for.
%            Parameter has to be -1 for the moment,
%            individual axes will be supported in the next firmware release
% param[out]
%           errNo: int32
%            Error code, if there was an error, otherwise 0 for ok
%           humidity: double
%            humidity in hPa


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ecu.manual.getHumidityInPercent", "params": [%i], "id": 1, "api": 2}', axis);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
humidity = data.result (2);


end


