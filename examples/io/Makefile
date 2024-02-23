SOURCES = $(wildcard *.cpp)

EXES = $(SOURCES:.cpp=)

ALL: $(EXES)

CXXFLAGS := -std=c++17 -Wall -Wextra

%: %.cpp
	g++ ${CXXFLAGS} -o $@ $<

clean:
	rm -f ${EXES}
