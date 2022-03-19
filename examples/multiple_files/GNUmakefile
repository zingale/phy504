# by default, make will try to build the first target it encounters.
# here we make up a dummy name "ALL" (note: this is not a special make
# name, it is just commonly used).

ALL: planet_sort_split

# explicitly list the rules for making each of the object files

planet_sort_split.o: planet_sort_split.cpp planet.H
	g++ -c planet_sort_split.cpp

planet.o: planet.cpp planet.H
	g++ -c planet.cpp

# explicitly write the rule for linking together the executable

planet_sort_split: planet_sort_split.o planet.o
	g++ -o planet_sort_split planet_sort_split.o planet.o
