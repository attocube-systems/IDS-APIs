function [errNo] = IDS_system_resetError(tcp, perform)
% brief : Resets a measurement error that can have occurred with the aim to continue the interrupted measurement. It is configurable if an additional renormalization process (please refer to the IDS User Manual) should be performed or not.
%           
%           This function can be used for two concerns:
%           1.	FALSE: This function only clears displacement errors (e.g. after a beam interruption) of all three axes, while the displacement measurement is running.
%           2.	TRUE: This function can be utilized to normalize the Lissajous-Figure of all three optical axes during the running displacement measurement by sweeping the laser temperature and to clear all displacement errors. This normalization process takes around 14-20 seconds. This function can be used, for example, in two main applications:
%           A.	The alignment contrast decreases due to the angular change of the target and/or sensor head without any displacements (see Figure 45). Using this function, the Lissajous-Figure of each measurement axis gets normalized and high-resolution measurements are guaranteed.
%           B.	After changing the optical components as, for example, the retro reflector this function can be used to normalize the Lissajous-Figure after completely losing the signal (see Figure 46).
%           Attention: Depending on the Boolean input parameter performRenormalisation, it can be decided, if the renormalization process should be executed or skipped. If it is executed, the IDS system needs around 14-20 seconds to get back to the measurement mode. It is also important to comment that the recommended action after an error is to stop and to restart the displacement measurement. Moreover, losing displacement values due to an occurred error the internal absolute position can be different to the real absolute position and this can could result in dynamic movement errors or a wrong ECU compensation during long-term displacement measurements.
%
% param[in] tcp : TCP/IP connection ID
%           perform:  renormalization
% param[out]
%           errNo: errNo


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.system.resetError", "params": [%i], "id": 1, "api": 2}', perform);

fprintf(tcp, data_send);
data_receive = fscanf(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);


end


