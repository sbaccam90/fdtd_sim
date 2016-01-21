clc
clear all
close all

z = readOneD('sim');
SimpleWaterfall(z, 1, 1.9)  % vertical offset = 1, scale factor = 1.9
xlabel('Space [spatial index]')
ylabel('Time [frame number]')

%reel = oneDmovie('sim',-1,1);
%movie(reel,10)
