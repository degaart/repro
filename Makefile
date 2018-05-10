.SUFFIXES:
.PHONY: all clean

CPPFLAGS:=-g
CFLAGS:=-std=gnu99
CXXFLAGS:=-std=gnu++11
LDFLAGS:=-g -Wl,-search_paths_first -Wl,-headerpad_max_install_names

all: Build Build/repro

Build:
	@mkdir -p Build

Build/repro: Build/repro.cpp.o Build/libreprolib.a
	@c++ -o $@ $(LDFLAGS) $^

Build/repro.cpp.o: src/repro.cpp
	@c++ -o $@ -c $(CXXFLAGS) $^

Build/libreprolib.a: Build/reprolib.c.o Build/reprolib.cpp.o
	@ar qc $@ $^
	@ranlib $@

Build/reprolib.c.o: reprolib/reprolib.c reprolib/reprolib.h
	@cc -o $@ -c $(CFLAGS) $<

Build/reprolib.cpp.o: reprolib/reprolib.cpp reprolib/reprolib.hpp reprolib/reprolib.h
	@c++ -o $@ -c $(CXXFLAGS) $<

clean:
	@rm -rf Build
