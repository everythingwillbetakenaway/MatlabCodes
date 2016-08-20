K = dftmtx(8);
X1 = [1:8]';
X2 = ones(1,8)';
X3 = [11100000]';
Y1 = K*X1;
Y12 = fft(X1);
figure;
Y2 = K*X2;
Y3 = K*X3;
y22 = fft(X2);
y32 = fft(X3);

Y1shift = fftshift(Y1);
Y2shift = fftshift(Y2);
Y3shift = fftshift(Y3);
 
x = [-pi:2*pi/8:pi*7/8];
length(x);
stem(x,Y3shift);
figure;
y = [0:2*pi/8:2*pi*7/8];
length(y);
stem(y,Y3);