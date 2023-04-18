import serial
import matplotlib.pyplot as plt
import numpy as np

serdev = 'COM3'
s = serial.Serial(serdev, 9600)

Fs = 128
x = np.arange(0,1,1/Fs)
y = np.arange(0,1,1/Fs)
z = np.arange(0,1,1/Fs)

s.write('1'.encode('utf-8'))

for i in range(0, int(Fs)):
    x[i] = float(s.readline())
    y[i] = float(s.readline())
    z[i] = float(s.readline())
    #print(line)

plt.figure
plt.subplot(3,1,1) #1*3 1
plt.title("x")
plt.plot(x)
plt.subplot(3,1,2) #1*3 2
plt.title("y")
plt.plot(y)
plt.subplot(3,1,3) #1*3 3
plt.title("z")
plt.plot(z)
plt.tight_layout()

plt.show()
