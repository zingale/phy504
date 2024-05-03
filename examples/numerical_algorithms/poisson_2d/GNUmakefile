ALL: poisson

# get all the sources and the headers
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.H)

# create the list of objects by replacing the .cpp with .o for the
# sources
OBJECTS = $(SOURCES:.cpp=.o)

# we have multiple targets here, which means multiple main()
# functions.  We need to exclude these from the general list of
# sources / objects, so we filter them out
MAINS := test_orbit.o test_lorenz.o test_lambda.o

OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

CXXFLAGS := -Wall -Wextra -Wshadow -Wpedantic -std=c++17 -g -O2 -DNDEBUG

ifeq (${PROFILE}, TRUE)
   CXXFLAGS += -pg
endif

%.o: %.cpp ${HEADERS}
	g++ ${CXXFLAGS} -c $<

%: %.cpp ${HEADERS} ${OBJECTS}
	g++ ${CXXFLAGS} -o $@ $< ${OBJECTS}

clean:
	rm -f *.o poisson

