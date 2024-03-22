ALL: test_array timing fortran_array

# get all the sources and the headers
SOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create the list of objects by replacing the .cpp with .o for the
# sources
OBJECTS := $(SOURCE:.cpp=.o)

# we have 2 targets here, which means two main() functions.  We need
# to exclude these from the general list of sources / objects, so we
# filter them out
MAINS := test_array.o timing.o test_copy.o
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

# by default, debug mode will be disabled
DEBUG ?= FALSE

CXXFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g

ifeq (${DEBUG}, TRUE)
   CXXFLAGS += -g
else
   CXXFLAGS += -DNDEBUG -O3
endif

F90FLAGS := -O3 -g

# general rule for compiling a .cpp file to .o
%.o : %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -c $<

%.o : %.f90
	gfortran ${F90FLAGS} -c $<

# the test_array program -- we need to explicitly include
# test_array.o here
test_array: test_array.o ${OBJECTS}
	g++ ${CXXFLAGS} -o $@ test_array.o ${OBJECTS}

# the timing program -- likewise, explicitly include
# timing.o here
timing: timing.o $(OBJECTS)
	g++ ${CXXFLAGS} -o $@ timing.o ${OBJECTS}

fortran_array: fortran_array.o
	gfortran ${F90FLAGS} -o $@ fortran_array.o

# 'make clean' will erase all the intermediate objects
clean:
	rm -f *.o test_array timing fortran_array
