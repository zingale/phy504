# get all the sources and the headers
SOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create the list of objects by replacing the .cpp with .o for the
# sources
OBJECTS := $(SOURCE:.cpp=.o)

# we have 2 targets here, which means two main() functions.  We need
# to exclude these from the general list of sources / objects, so we
# filter them out
MAINS := test_array.o timing.o
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

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
test_array: test_array.o ${OBJECTS}
	g++ -o $@ test_array.o ${OBJECTS}

# the timing program -- likewise, explicitly include
# timing.o here
timing: timing.o $(OBJECTS)
	g++ -o $@ timing.o ${OBJECTS}

# 'make clean' will erase all the intermediate objects
clean:
	rm -f *.o test_array timing
