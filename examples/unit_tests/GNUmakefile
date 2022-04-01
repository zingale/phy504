# by default, make will try to build the first target it encounters.
# here we make up a dummy name "ALL" (note: this is not a special make
# name, it is just commonly used).

ALL: unit_test_vector2d

# find all of the source files and header files

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create a list of object files by replacing .cpp with .o

OBJECTS := $(SOURCES:.cpp=.o)

# a recipe for making an object file from a .cpp file
# Note: this makes every header file a dependency of every object file,
# which is not ideal, but it is safe.

%.o : %.cpp ${HEADERS}
	g++ -c $<

# explicitly write the rule for linking together the executable

unit_test_vector2d: ${OBJECTS}
	g++ -o $@ ${OBJECTS}

testing: unit_test_vector2d
	./unit_test_vector2d > /dev/null
	@if [ $$? == 0 ]; then echo "tests passed"; fi

