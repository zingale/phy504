ALL: test_ode

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.H)

OBJECTS = $(SOURCES:.cpp=.o)

CXXFLAGS := -Wall -Wextra -Wshadow -Wpedantic -std=c++23

%.o: %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -c $<

test_ode: ${OBJECTS} ${HEADERS}
	g++ -o $@ ${OBJECTS}

clean:
	rm -f *.o test_ode
