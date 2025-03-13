ALL: test_array test_copy

# get all the sources and the headers
SOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create the list of objects by replacing the .cpp with .o for the
# sources
OBJECTS := $(SOURCE:.cpp=.o)

# we have 2 targets here, which means two main() functions.  We need
# to exclude these from the general list of sources / objects, so we
# filter them out
MAINS := test_array.o test_copy.o
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

# by default, debug mode will be disabled
DEBUG ?= FALSE

CXXFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g -std=c++23

ifeq (${DEBUG}, TRUE)
   CXXFLAGS += -g
else
   CXXFLAGS += -DNDEBUG -O3
endif

# general rule for compiling a .cpp file to .o
%.o : %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -c $<


# the test_array program -- we need to explicitly include
# test_array.o here
test_array: test_array.o ${OBJECTS}
	g++ ${CXXFLAGS} -o $@ test_array.o ${OBJECTS}

# the test_copy program -- we need to explicitly include
# test_copy.o here
test_copy: test_copy.o ${OBJECTS}
	g++ ${CXXFLAGS} -o $@ test_copy.o ${OBJECTS}


# 'make clean' will erase all the intermediate objects
clean:
	rm -f *.o test_array test_copy
