import time
import serial

ser = Serial(port='/dev/ttyUSB1')

ser.Open()

msg = 1
ser.write(msg)
ret_msg = ser.read()
print "I have recieved"+ret_msgs
