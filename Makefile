CXXFLAGS = -O3 -Wall -Wconversion -Werror -Wextra \
	   -Wformat=2 -Wno-unused-function -Wpointer-arith \
	   -Wstrict-overflow=1 -mtune=native
DEFINES	= -DMCNOODLE_ARTIFICIAL_GENERATOR=1 \
	  -DMCNOODLE_ASSUME_SAFE_PARAMETERS=1 \
	  -DMCNOODLE_OS_UNIX=1

INCLUDES = -Intl.d/unix.d/ntl-9.10.0/include
LIBRARIES = -lboost_random -lboost_serialization -lboost_system \
	    -l:libraries.d/ntl.a

OBJECT_FILES = mcnoodle.o mcnoodle-goppa.o

all:	$(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $(DEFINES) $(OBJECT_FILES) test.cc -o test \
	$(LIBRARIES)

mcnoodle.o: mcnoodle.cc mcnoodle.h
	$(CXX) $(CXXFLAGS) $(DEFINES) $(INCLUDES) -c mcnoodle.cc -o mcnoodle.o
clean:
	rm -f *.o
	rm -f test

distclean: clean

purge:
	rm -f *~*
