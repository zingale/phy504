ALL: test_orbit test_lorenz

# get all the sources and the headers
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.H)

# create the list of objects by replacing the .cpp with .o for the
# sources
OBJECTS = $(SOURCES:.cpp=.o)

# we have multiple targets here, which means multiple main()
# functions.  We need to exclude these from the general list of
# sources / objects, so we filter them out
MAINS := test_orbit.o test_lorenz.o
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

CXXFLAGS := -Wall -Wextra -Wshadow -Wpedantic -std=c++23

%.o: %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -c $<

%: %.cpp ${HEADERS} ${OBJECTS}
	g++ ${CXXFLAGS} -o $@ $< ${OBJECTS}

clean:
	rm -f *.o test_ode
