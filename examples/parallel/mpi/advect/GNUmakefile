HEADERS := $(wildcard *.H)
SOURCES := $(wildcard *.cpp)

OBJECTS := $(SOURCES:.cpp=.o)

ALL: advection

CXXFLAGS := -Wall -Wextra -Wshadow -std=c++23 -g

%.o : %.cpp ${HEADERS}
	mpic++ -c ${CXXFLAGS} $<

advection: ${OBJECTS} ${HEADERS}
	mpic++ -o $@ ${OBJECTS} -lstdc++exp


clean:
	rm -f *.o advection
