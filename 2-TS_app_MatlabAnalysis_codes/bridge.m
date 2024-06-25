% Template MATLAB code for reading data from a private channel, analyzing
% the data and storing the analyzed data in another channel.

% Prior to running this MATLAB code template, assign the channel variables.
% Set 'readChannelID' to the channel ID of the channel to read from. Since 
% this is a private channel, also assign the read API Key to the 'readAPIKey'
% variable. You can find the read API Key on the right side pane of this page.

% To store the analyzed data, you will need to write it to a channel other
% than the one you are reading data from. Assign this channel ID to the
% 'writeChannelID' variable. Also assign the write API Key to the
% 'writeAPIKey' variable below. You can find the write API Key in the right
% side pane of this page.

% TODO - Replace the [] with channel ID to read data from:
readChannelID = [2582290];
% TODO - Enter the Read API Key between the '' below:
readAPIKey = '70URRTIX01JMOQJ9';

% TODO - Replace the [] with channel ID to write data to:
writeChannelID = [2582296];
% TODO - Enter the Write API Key between the '' below:
writeAPIKey = 'Y2A9Q6LC6A034TD6';
toto=3
%% Read Data %%
while toto==3
    data = thingSpeakRead(readChannelID, 'ReadKey', readAPIKey);


%% Analyze Data %%
% Add code in this section to analyze data and store the result in the
% 'analyzedData' variable.
analyzedData = data

%% Write Data %%
thingSpeakWrite(writeChannelID, analyzedData, 'WriteKey', writeAPIKey);
pause(10)
end