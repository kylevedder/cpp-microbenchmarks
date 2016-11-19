GPP = g++
CLANG = clang++
CFLAGS = --std=c++11 -Wall -g
ADDFLAGS = -lpthread
OBJS = 

all: main-gpp main-clang

main-gpp: main.cc $(OBJS)
	$(GPP) $(CFLAGS) $^ -o $@ $(ADDFLAGS)

main-clang: main.cc $(OBJS)
	$(CLANG) $(CFLAGS) $^ -o $@ $(ADDFLAGS)

clean:
	rm -f *.o *-gpp *-clang
