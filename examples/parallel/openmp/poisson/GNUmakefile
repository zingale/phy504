SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

EXES = $(SOURCES:.cpp=)

ALL: $(EXES)

CXXFLAGS := -std=c++17 -Wall -Wextra -Wshadow -Wpedantic -fopenmp -O2

%: %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -o $@ $<

clean:
	rm -f ${EXES}
