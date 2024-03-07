ALL: test_orbit

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.H)

OBJECTS = $(SOURCES:.cpp=.o)

CFLAGS := -Wall -Wextra -Wshadow -Wpedantic

%.o: %.cpp
	g++ ${CFLAGS} -c $<

test_orbit: ${OBJECTS} ${HEADERS}
	g++ -o $@ ${OBJECTS}
