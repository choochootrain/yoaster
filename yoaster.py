import serial
import subprocess
import datetime

ser = serial.Serial('/dev/ttyUSB0', 9600)
now = datetime.datetime.now()
done = True

while True:
  response = ser.readline().strip()
  if (datetime.datetime.now() - now).total_seconds() > 1:
    now = datetime.datetime.now()
    if response == '1' and not done:
        print 'Yoaster done'
        subprocess.call(['./yoall.sh'])
        done = True
    elif response == '2':
        print 'Yoaster initialized'
        done = False
