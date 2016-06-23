import win32print
import win32ui
from PIL import Image, ImageWin

printer_info = win32print.EnumPrinters (
   win32print.PRINTER_ENUM_LOCAL | win32print.PRINTER_ENUM_CONNECTIONS
)
printer_name = win32print.GetDefaultPrinter()

print printer_info
print printer_name