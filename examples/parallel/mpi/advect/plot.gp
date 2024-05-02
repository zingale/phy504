set term x11 persist
set view map
set size ratio -1
set autoscale fix
splot 'advection_t1.000_mpi.out' notitle w pm3d
