# get all the sources and the headers
SOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create the list of objects by replacing the .cpp with .o for the
# sources
OBJECTS := $(SOURCE:.cpp=.o)

# tell the compiler where to look for our headers
INCLUDEPATH := .
INCLUDES := $(foreach i, ${INCLUDEPATH}, -I$i)

# by default, debug mode will be disabled
DEBUG ?= FALSE

ifeq (${DEBUG}, TRUE)
   OPTS += -g
else
   OPTS += -DNDEBUG -O3
endif

# general rule for compiling a .cpp file to .o
%.o : %.cpp ${HEADERS}
	g++ ${CFLAGS} ${OPTS} ${INCLUDES} -c $<

# the test_array program -- we need to explicitly include
# test_array.o here
test_array: ${OBJECTS}
	g++ -o $@ ${OBJECTS}

# 'make clean' will erase all the intermediate objects
clean:
	rm -f *.o test_array
