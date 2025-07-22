function [value_errNo] = system_update_uploadLicenseBase64(tcp, offset, b64Data)
% brief : Uploads new license file in format base 64.
%
% param[in] tcp: TCP/IP connection ID
%           offset: offset of the data
%           b64Data: base64 data string
% param[out]
%           value_errNo: errNo error code, if there was an error, otherwise 0 for ok


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.system.update.uploadLicenseBase64", "params": [%i, %s], "id": 1, "api": 2}', offset, b64Data);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

value_errNo = data.result(1);


end