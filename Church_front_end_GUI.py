#/usr/bin/env python

##############################################################
# PTZ camera control GUI
# This program is the front GUI control for sending IR signals
# to a PZT camera. This program sends I2C data via on screen  
# button to an Ardiuno that will transmit the IR signals
# 
# Tony Davis 
# 26.12.2020
# issue 0.01
###############################################################

from tkinter import  *              # import to the Tkinter libraries
from smbus import SMBus             # import libary for I2C communication 

addr = 0x8                           # setup bus address
bus = SMBus(1)                       # make sure bus 1 is used

win = Tk()                           # define an instance of TKinter

win.geometry('900x500+30+95')        # define tkinter window
win.title('Church IR Transmitter')   # give the window a title

### These functions transmit I2C hex data to an Ardiuno
### the '0' (addr, 0x1) tells the program to transmit the data in hex format

def cameraFuc1():
    bus.write_byte(addr, 0x1)
    
def cameraFuc2():
    bus.write_byte(addr, 0x2)
    
def cameraFuc3():
    bus.write_byte(addr, 0x3)
    
def cameraFuc4():
    bus.write_byte(addr, 0x4)

def cameraFuc5():
    bus.write_byte(addr, 0x5)

def cameraFuc6():
    bus.write_byte(addr, 0x6)

def cameraFuc7():
    bus.write_byte(addr, 0x7)

def cameraFuc8():
    bus.write_byte(addr, 0x8)
    
def cameraFuc9():
    bus.write_byte(addr, 0x9)
    
def cameraFuc10():
    bus.write_byte(addr, 0xA)
    
def cameraTiltUp():
    bus.write_byte(addr, 0xB)

def cameraTiltDown():
    bus.write_byte(addr, 0xC)
    
def cameraPanLeft():
    bus.write_byte(addr, 0xD)
    
def cameraPanRight():
    bus.write_byte(addr, 0xE)

def cameraZoomIn():
    bus.write_byte(addr, 0xF)

def cameraZoomOut():
    bus.write_byte(addr, 0x0)
    

    
mylabel_0 = Label(text ='PTZ Camera Control',font=('Calibri',14,'bold'),width=90).place(x=45, y=30)
    
    
mylabel_1 = Label(text ='1').place(x=100, y=80)
mylabel_2 = Label(text ='2').place(x=270, y=80)
mylabel_3 = Label(text ='3').place(x=440, y=80)
mylabel_4 = Label(text ='4').place(x=610, y=80)
mylabel_4 = Label(text ='5').place(x=782, y=80)
mylabel_6 = Label(text ='6').place(x=100, y=180)
mylabel_7 = Label(text ='7').place(x=270, y=180)
mylabel_8 = Label(text ='8').place(x=440, y=180)
mylabel_9 = Label(text ='9').place(x=610, y=180)
mylabel_10 = Label(text ='10').place(x=782, y=180)
mylabel_11 = Label(text ='Pan and Tilt').place(x=300, y=350)
mylabel_12 = Label(text ='Zoom').place(x=600, y=350)
mylabel_13 = Label(text ='Pan,Tilt and Zoom controls are as if looking into the camera').place(x=280, y=450)


    
#### Buttons and their parameters along with the commands to activate the relevent function ####

myButton_1 = Button(win,text='Altar Wide View',height=3,width=15,  command = cameraFuc1).place(x=30, y=100)
myButton_2 = Button(win,text='Priest at Chair',height=3,width=15,  command = cameraFuc2).place(x=203, y=100)
myButton_3 = Button(win,text='Readers Lectern',height=3,width=15,  command = cameraFuc3).place(x=376, y=100)
myButton_4 = Button(win,text='Main Lectern',height=3,width=15,  command = cameraFuc4).place(x=546, y=100)
myButton_5 = Button(win,text='Altar Close Up View',height=3,width=15,  command = cameraFuc5).place(x=719, y=100)
myButton_6 = Button(win,text='Baptism & Funeral',height=3,width=15,  command = cameraFuc6).place(x=30, y=200)
myButton_7 = Button(win,text='Main Cross',height=3,width=15,  command = cameraFuc7).place(x=203, y=200)
myButton_8 = Button(win,text='Wall Poster',height=3,width=15,  command = cameraFuc8).place(x=376, y=200)
myButton_9 = Button(win,text='Monstrance',height=3,width=15,  command = cameraFuc9).place(x=546, y=200)
myButton_10 = Button(win,text='Windows/Prayer',height=3,width=15,  command = cameraFuc10).place(x=719, y=200)

##### Up, down, left, right and zoom buttons  #######

myButton_11 = Button(win,text='↑',height=1,width=5,  command = cameraTiltUp).place(x=420, y=300)
myButton_12 = Button(win,text='↓ ',height=1,width=5,  command = cameraTiltDown).place(x=420, y=390)
myButton_13 = Button(win,text='←',height=3,width=1,  command = cameraPanLeft).place(x=390, y=330)
myButton_14 = Button(win,text='→',height=3,width=1,  command = cameraPanRight).place(x=485, y=330)
myButton_15 = Button(win,text='In',height=3,width=1,  command = cameraZoomIn).place(x=550, y=300)
myButton_16 = Button(win,text='Out',height=3,width=1,  command = cameraZoomOut).place(x=550, y=360)


# ᐯ ᐱ  ᐳ ᐸ  ↑←  →  ↓ ᐃ

win.mainloop()


 
