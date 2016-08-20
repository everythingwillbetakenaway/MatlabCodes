function out = mycirconv(x1,x2)
X1 = fft(x1);
X2 = fft(x2);
result = ifft(X1.*X2);
 
out = result;
end