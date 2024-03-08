ALL: test_orbit

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.H)

OBJECTS = $(SOURCES:.cpp=.o)

CFLAGS := -Wall -Wextra -Wshadow -Wpedantic

%.o: %.cpp ${HEADERS}
	g++ ${CFLAGS} -c $<

test_orbit: ${OBJECTS} ${HEADERS}
	g++ -o $@ ${OBJECTS}

clean:
	rm -f *.o test_orbit
