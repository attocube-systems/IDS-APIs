function [errNo, lintable, nonlinearamp] = IDS_displacement_linProc(tcp, axis, fringesnbr, samplesperfringe, set)
% brief : Important note: This function is not actively supported anymore. With IDS firmware 1.7.0, a new set of functions corresponding to the linearization procedure was introduced and effectively outdated this function.
%           
%           Starts linearization procedure (additional IDS feature).
%
% param[in] tcp : TCP/IP connection ID
%           axis:  [0|1|2]
%           fringesnbr:  Number of fringes to be acquired
%           samplesperfringe:  Number of samples per fringe
%           set:  0 = evaluate current nonlinear amplitude 
%            1 = perform linearization and upload look up table 
%            2 = Clear look up table 
%            3 = Perform only calculation of Phi file
% param[out]
%           errNo: errNo
%           lintable: lintable String, which contains all 512 phase related correction values
%           nonlinearamp: nonlinearamp String which contains the residual positive and negative maximal nonlinear amplitude


data_send = sprintf('{"jsonrpc": "2.0", "method": "com.attocube.ids.displacement.linProc", "params": [%i, %i, %i, %i], "id": 1, "api": 2}', axis, fringesnbr, samplesperfringe, set);

writeline(tcp, data_send);
data_receive = readline(tcp);
data = jsondecode(data_receive);

errNo = data.result (1);
lintable = data.result (2);
nonlinearamp = data.result (3);


end


