dm6467
======

usefull stuff for dm6467[t] processor and ts320dm6467[t]

to get this project:
git clone https://github.com/gxk/dm6467.git

To change DDR speed edit follows file 
Common/src/device.c
Depend on your clock(usualy 40 or 33MHz) set parameter PLL2_Mult
For example, PLL2_Mult = 24, gives DDR speed of 396MHz in case of 33MHz clock
