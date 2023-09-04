%% Setting up arudino
a = arduino('com','Uno');


%% Collecting voltage information from the arduino
seconds =10; % Defining the required duration for the data collection
elapse_time = 0;
tic % initiate time duration

while elapse_time<seconds
    v = readVoltage(a,'A0'); % collecting voltage data from Arduino.
    % Please mind that you have to adjust the pin based on the your input
    % pin in arduino
    elapse_time = toc; %collecting time for each iteration 
end


%% Applying sensor transfer function 

 P = (v-0.2)/0.045; % calculating the pressure based on the read voltage
