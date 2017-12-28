CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
MAIN = main.cpp
MAINOBJ = $(MAIN:.cpp=.o)
MAINEXEC = $(MAIN:.cpp=)
VPATH = . 
SRCS = chol.cpp internal.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(MAINEXEC)

$(MAINEXEC): $(MAINOBJ) $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(MAINOBJ): _internal_routines.h _chol.h _matrix_t.h

$(OBJS): _internal_routines.h _chol.h _matrix_t.h

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

test:
	rm -rf *.txt
	./$(MAINEXEC)

.PHONY: test

clean:
	rm -rf $(MAINOBJ) $(MAINEXEC) *.txt

.PHONY: clean
