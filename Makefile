GPP = g++
CLANG = clang++
CFLAGS = --std=c++11 -march=native -Wall -g
O2FLAG = -O2
O3FLAG = -O3
OFASTFLAG = -Ofast
ADDFLAGS = -lpthread
OBJS = 

all: main-o2-gpp main-o2-clang main-o3-gpp main-o3-clang main-ofast-gpp main-ofast-clang

main-o2-gpp: main.cc $(OBJS)
	$(GPP) $(CFLAGS) $(O2FLAG) $^ -o $@ $(ADDFLAGS)

main-o2-clang: main.cc $(OBJS)
	$(CLANG) $(CFLAGS) $(O2FLAG) $^ -o $@ $(ADDFLAGS)

main-o3-gpp: main.cc $(OBJS)
	$(GPP) $(CFLAGS) $(O3FLAG) $^ -o $@ $(ADDFLAGS)

main-o3-clang: main.cc $(OBJS)
	$(CLANG) $(CFLAGS) $(O3FLAG) $^ -o $@ $(ADDFLAGS)

main-ofast-gpp: main.cc $(OBJS)
	$(GPP) $(CFLAGS) $(OFASTFLAG) $^ -o $@ $(ADDFLAGS)

main-ofast-clang: main.cc $(OBJS)
	$(CLANG) $(CFLAGS) $(OFASTFLAG) $^ -o $@ $(ADDFLAGS)

clean:
	rm -f *.o *-gpp *-clang
