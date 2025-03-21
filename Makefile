CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -march=native
LDFLAGS = 


SOURCES = main.cpp laikas.cpp funkcijos.cpp strategija1.cpp strategija2.cpp strategija3.cpp


HEADERS = funkcijos.h laikas.h funkcijos.h strategija1.h strategija2.h strategija3.h lib.h


OBJECTS = $(SOURCES:.cpp=.o)


EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@


funkcijos.o: funkcijos.cpp funkcijos.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)


test_files:
	mkdir -p test_files

.PHONY: all clean