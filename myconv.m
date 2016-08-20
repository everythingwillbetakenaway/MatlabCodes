function out = myconv(x1,x2)
x1padded = [x1 zeros(1,length(x2))];
x2padded = [x2 zeros(1,length(x1))];
A = fft(x1padded);
B = fft(x2padded);
 
result = ifft(A.*B);
 
out =  result;
end