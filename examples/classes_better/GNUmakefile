ALL: test_solar_system

# find all of the source files and header files

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create a list of object files by replacing .cpp with .o

OBJECTS := $(SOURCES:.cpp=.o)


CFLAGS := -Wall -Wextra -Wpedantic -Wshadow -g

# a recipe for making an object file from a .cpp file
# Note: this makes every header file a dependency of every object file,
# which is not ideal, but it is safe.

%.o : %.cpp ${HEADERS}
	g++ ${CFLAGS} -c $<

# explicitly write the rule for linking together the executable

test_solar_system: ${OBJECTS}
	g++ -o $@ ${OBJECTS}


clean:
	rm -f *.o test_solar_system
