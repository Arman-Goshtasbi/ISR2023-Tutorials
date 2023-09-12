

%% Setting up arudino
a = arduino('COM7','Uno');


%% Collecting voltage information from the arduino
seconds =5; % Defining the required duration for the data collection
elapse_time = 0;
tic % initiate time duration
v = [];
while elapse_time<seconds
    v_new = readVoltage(a,'A1'); % collecting voltage data from Arduino.
    v = [v;v_new];
    % Please mind that you have to adjust the pin based on the your input
    % pin in arduino
    elapse_time = toc; %collecting time for each iteration 
    pause(0.05)
end


%% Applying sensor transfer function 

 P = (v-0.2)/0.045; % calculating the pressure based on the read voltage
    
