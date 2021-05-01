# gnuplot settings --------------------------------------------------------------------
set key        # Show legend
set xl "x" font "Times-New = Roman: Italic, 18" # Label on horizontal axis
set yl "C (x, t)" font "Times-New = Roman: Italic, 18" # Label on the vertical axis 
Set Xrange [- 200 : 200 ] # range of horizontal axis
set yrange [ 0 : 10 ] # vertical range
set term gif animate      # set output to gif animated


#Variable settings -----------------------------------------------------------------------
n0 = 0 # Specify the first data number
Number of repetitions of n1 = 15 # n0
n2 = 550 # Specify the last data number
dn = 1 # number increment
set output "diffusion.gif" # Output file name setting


#Start of loop ---------------------------------------------------------------------
Repeat load "dif-loop1.plt" # n0 n1 times
load "dif-loop2.plt" # gif the data of n0 to n2