SOURCES = $(wildcard *.cpp)

EXES = $(SOURCES:.cpp=)

ALL: $(EXES)

CXXFLAGS := -std=c++17 -Wall -Wextra -Wshadow -Wpedantic -fopenmp

%: %.cpp
	g++ ${CXXFLAGS} -o $@ $<

clean:
	rm -f ${EXES}
