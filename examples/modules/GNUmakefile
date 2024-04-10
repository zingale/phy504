MODULEFILES := example.cpp
SOURCEFILES := main.cpp

MODULEOBJS := $(MODULEFILES:.cpp=.o)
SOURCEOBJS := $(SOURCEFILES:.cpp=.o)

%.o : %.cpp
	g++ -std=c++20 -fmodules-ts -c $<

main: ${MODULEOBJS} ${SOURCEOBJS}
	g++ -std=c++20 --modules-ts -o $@ ${MODULEOBJS} ${SOURCEOBJS}

clean:
	rm -rf *.o main gcm.cache


