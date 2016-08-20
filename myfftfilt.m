function out = myfftfilt(x, h)
 
Nx = length(x);
Nh = length(h);
N = Nx + Nh - 1;
 
h = [h zeros(1,N-Nh)];
x = [x zeros(1,N-Nx)];
 
h_dft = fft(h);
x_dft = fft(x);
 
for k = 1:N
   dft(k) = h_dft(k).*x_dft(k);
end
result = ifft(dft);
out = result;
end