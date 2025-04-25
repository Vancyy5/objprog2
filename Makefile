CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2
DEPS = zmogus.h funkcijos.h laikas.h
OBJ = main.o funkcijos.o zmogus.o laikas.o
TEMP_FILES = failinis.txt studentai.txt rezultataiT.txt

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(TARGET) $(TEMP_FILES)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run