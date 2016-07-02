#!/usr/bin/python
import win32print
import win32ui
from PIL import Image, ImageWin
import time, os, glob

# Processor load is heavy at startup; wait a moment to avoid
# stalling during greeting.
#time.sleep(3)
#
# Constants for GetDeviceCaps
#
#
# HORZRES / VERTRES = printable area
#
HORZRES = 8
VERTRES = 10
#
# LOGPIXELS = dots per inch
#
LOGPIXELSX = 88
LOGPIXELSY = 90
#
# PHYSICALWIDTH/HEIGHT = total area
#
PHYSICALWIDTH = 110
PHYSICALHEIGHT = 111
#
# PHYSICALOFFSETX/Y = left / top margin
#
PHYSICALOFFSETX = 112
PHYSICALOFFSETY = 113

# printer_name = win32print.GetDefaultPrinter ()
printers = ["EPSON TM-T20II Receipt", "EPSON TM-T20II Receipt5"]
# printer_name[0] = "EPSON TM-T20II Receipt"
# printer_name[1] = "EPSON TM-T20II Receipt5"

while(True):
	#lst = os.listdir("../picturesToPrint/")
	lst = glob.glob('../picturesToPrint/*.jpg')
	noPics = len(lst)
	print str(noPics) + " pictures found"
	if noPics == 0:
		print "Waiting..."
		continue;
	#for picture in lst:
	#	print picture.split('\\', 1)[-1]

	current_screen = int(filter(str.isdigit, lst[0].split('\\', 1)[-1].split('-')[0])) - 1
	print current_screen
	time.sleep(3)