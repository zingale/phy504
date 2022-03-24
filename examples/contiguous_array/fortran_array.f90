program main

  implicit none

  integer, parameter :: MAX_SIZE = 2000

  double precision, allocatable :: a(:,:)
  double precision :: start, end
  integer :: irow, icol

  allocate(a(MAX_SIZE, MAX_SIZE))

  call cpu_time(start)

  do icol = 1, MAX_SIZE
     do irow = 1, MAX_SIZE
        a(irow, icol) = dble(irow + icol + 1)
     end do
  end do

  call cpu_time(end)

  print *, "cpu time = ", end - start

end program main