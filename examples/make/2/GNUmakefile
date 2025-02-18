
# variables to note the compiler and options -- this makes it easier
# to change these as necessaey
CCOMP := g++
CFLAGS := -O

header_locations := .

header_options = $(foreach dir, $(header_locations), -I$(dir))

# the list of source files that need to be compiled to make our
# executable
cppsources += main.cpp compute.cpp print_result.cpp

# the list of object files that need to be created -- here we use a
# makefile function to automatically change each .cpp into a .o
cppobjects = $(cppsources:.cpp=.o)

# our default target
ALL: main

# a general rule to make a .o file from the corresponding .f90
%.o: %.cpp
	$(CCOMP) $(CFLAGS) $(header_options) -c $<

# the rule to make the executable -- note that it depends on all
# of the objects being made
main: $(cppobjects)
	$(CCOMP) -o main $(cppobjects)


# a special target that cleans up
clean:
	rm -f *.o 

# PHONY tells make that clean is not a real file, so it will ensure
# that if you type "make clean" this is always executed.  This is only
# a problem if, somehow, you create an actually file named "clean" in
# your directory -- then make will think that clean is up to date.
.PHONY: clean
