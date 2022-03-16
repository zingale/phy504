SOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)
OBJECTS := $(SOURCE:.cpp=.o)

INCLUDEPATH= .

INCLUDES = $(foreach i, ${INCLUDEPATH}, -I$i)

DEBUG ?= FALSE

ifeq (${DEBUG}, TRUE)
   OPTS +=
else
   OPTS += -DNDEBUG
endif

%.o : %.cpp ${HEADERS}
	g++ ${CFLAGS} ${OPTS} ${INCLUDES} -c $<

test_array: ${OBJECTS}
	g++ -o $@ ${OBJECTS}

clean:
	rm -f *.o test_array
