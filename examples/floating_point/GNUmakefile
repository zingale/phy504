SOURCES = $(wildcard *.cpp)

EXES = $(SOURCES:.cpp=)

ALL: $(EXES)

CXXFLAGS := -std=c++17 -Wall -Wextra -Wshadow -Wpedantic -g

undefined_stacktrace: undefined_stacktrace.cpp
	g++ -g -std=c++23 -o $@ $< -lstdc++_libbacktrace
%: %.cpp
	g++ ${CXXFLAGS} -o $@ $<

clean:
	rm -f ${EXES}
