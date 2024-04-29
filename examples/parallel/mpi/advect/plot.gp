set term x11 persist
set autoscale xy
set view map
set size ratio -1
#set xrange [0:63]
#set yrange [0:63]
splot 'advect_mpi.out' notitle w pm3d 

