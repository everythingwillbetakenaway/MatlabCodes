fvtool(b);

% ellipt.m - Compare minimum-phase and zero-phase
 %
dosounds = 1;
lowpass impulse responses.
N = 8;
Rp = 0.5;
Rs = 60;
Fs = 8192;
Fp = 2000;
Fc = 2200;
Ns = 4096;
%[B,A] = ellip(Rp, Rs,Fp/(0.5*Fs), Fc/(0.5*Fs)); % Octave
 [B,A] = ellip(N, Rp, Rs, Fp/(0.5*Fs)); % Matlab
% Minimum phase case:
imp = [1,zeros(1,Ns/2-1)]; % or 'h1=impz(B,A,Ns/2-1)' h1 = filter(B,A,imp); % min-phase impulse response hmp = filter(B,A,[h1,zeros(1,Ns/2)]); % apply twice
% Zero phase case:
h1r = fliplr(h1); % maximum-phase impulse response
hzp = filter(B,A,[h1r,zeros(1,Ns/2)]); % min*max=zp
% hzp = fliplr(hzp); % not needed here since symmetric
% plot impulse- and amplitude-responses
% Let's hear them! while(dosounds) sound(hmp,Fs); pause(0.5); sound(hzp,Fs); pause(1);
plot