SOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)
OBJECTS := $(SOURCE:.cpp=.o)

MAINS := test_array.o timing.o
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

INCLUDEPATH= .

INCLUDES = $(foreach i, ${INCLUDEPATH}, -I$i)

DEBUG ?= FALSE

ifeq (${DEBUG}, TRUE)
   OPTS += -g
else
   OPTS += -DNDEBUG -O3
endif

%.o : %.cpp ${HEADERS}
	g++ ${CFLAGS} ${OPTS} ${INCLUDES} -c $<

test_array: test_array.o ${OBJECTS}
	g++ -o $@ test_array.o ${OBJECTS}

timing: timing.o $(OBJECTS)
	g++ -o $@ timing.o ${OBJECTS}

clean:
	rm -f *.o test_array
