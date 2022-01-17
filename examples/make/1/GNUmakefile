# by default, make will try to build the first target it encounters.
# here we make up a dummy name "ALL" (note: this is not a special make
# name, it is just commonly used).
ALL: main

# explicitly list the rules for making each of the object files
main.o: main.cpp
	g++ -I. -c main.cpp

compute.o: compute.cpp
	g++ -I. -c compute.cpp

print_result.o: print_result.cpp
	g++ -I. -c print_result.cpp


# explicitly write the rule for linking together the executable
main: main.o compute.o print_result.o
	g++ -o main main.o compute.o print_result.o
