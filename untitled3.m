[x,fs]=audioread('music1.wav');
 
M = 31;
a = 1;
b = 1/M * ones (1,M);
 
[h,t] = impz(b,a,31);



y=myfftfilt(h',x');
sound(y,fs);
plot(y);




%y=fftfilt(h,x);
%sound(y,fs);
%plot(y);