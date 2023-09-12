import serial

import time 

import matplotlib.pyplot as plt

ser = serial.Serial('COM7',115200, timeout=1)

time.sleep(1)

data = []

for i in range(50):
    line = ser.readline()
    if line:
        string = line.decode()
        num = float(string)
        print(num)
        data.append(num)

ser.close()

#please to the conversion from read value to pressure



plt.plot(data)
plt.xlabel('time')
plt.show()
