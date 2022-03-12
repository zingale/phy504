
SOURCE := $(wildcard *.cpp)
OBJECTS := $(SOURCE:.cpp=.o)

INCLUDEPATH=.

%.o : %.cpp
	g++ ${CFLAGS} -I ${INCLUDEPATH} -c $<



test_array: ${OBJECTS}
	g++ -o $@ ${OBJECTS}
