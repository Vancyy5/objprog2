CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -march=native
SRCS = main.cpp funkcijos.cpp laikas.cpp
HEADERS = funkcijos.h laikas.h
OBJS = $(SRCS:.cpp=.o)
TARGET = main
TEMP_FILES = failinis.txt studentai.txt rezultataiT.txt

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

funkcijos.o: funkcijos.cpp funkcijos.h laikas.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

laikas.o: laikas.cpp laikas.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

main.o: main.cpp funkcijos.h laikas.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET) $(TEMP_FILES)

run: $(TARGET)
	./$(TARGET)

