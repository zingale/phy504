MODULEFILES := example.cpp
SOURCEFILES := main.cpp

MODULEOBJS := $(MODULEFILES:.cpp=.o)
SOURCEOBJS := $(SOURCEFILES:.cpp=.o)

ALL: main

%.o : %.cpp
	g++ -std=c++20 -fmodules-ts -c $<

system_headers:
	g++ -std=c++20 -fmodules-ts -x c++-system-header iostream

main: system_headers ${MODULEOBJS} ${SOURCEOBJS}
	g++ -std=c++20 --modules-ts -o $@ ${MODULEOBJS} ${SOURCEOBJS}

clean:
	rm -rf *.o main gcm.cache


