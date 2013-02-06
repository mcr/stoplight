#!/usr/bin/python

import usb # 1.0 not 0.4


import sys
sys.path.append("..")

from arduino.usbdevice import ArduinoUsbDevice

def led(theDevice, led, val):
    theDevice.write(ord(led))
    theDevice.write(val)

def red(val):
    led(theDevice, 'r', val)

def green(val):
    led(theDevice, 'g', val)

def blue(val):
    led(theDevice, 'b', val)

def yellow(val):
    led(theDevice, 'y', val)

theDevice = ArduinoUsbDevice(idVendor=0x16c0, idProduct=0x05df)

print "Found: 0x%04x 0x%04x %s %s" % (theDevice.idVendor, 
                                      theDevice.idProduct,
                                      theDevice.productName,
                                      theDevice.manufacturer)

if __name__ == "__main__":

    import sys
    import time

    red(0)
    green(0)
    yellow(0)
    blue(0)

    while True:
        red(255)
        green(0)
        time.sleep(0.5)

        blue(255)
        red(0)
        time.sleep(0.5)

        yellow(255)
        blue(0)
        time.sleep(0.5)
        
        green(255)
        yellow(0)
        time.sleep(0.5)

