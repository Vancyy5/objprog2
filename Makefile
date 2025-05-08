CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2

# Google Test paths (update if needed)
GTEST_DIR = external/googletest/googletest
GTEST_INCLUDE = $(GTEST_DIR)/include
GTEST_SRC = $(GTEST_DIR)/src/gtest-all.cc

# Your project files
DEPS = zmogus.h funkcijos.h laikas.h
OBJ = main.o funkcijos.o zmogus.o laikas.o
TEMP_FILES = failinis.txt studentai.txt rezultataiT.txt
TEST_OBJ = testai.o funkcijos.o zmogus.o laikas.o gtest-all.o

TARGET = main
TEST_TARGET = run_tests

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)


gtest-all.o: $(GTEST_SRC)
	$(CXX) -I$(GTEST_INCLUDE) -I$(GTEST_DIR) -c $< -o $@

testai.o: testai.cpp $(DEPS)
	$(CXX) -I$(GTEST_INCLUDE) -I$(GTEST_DIR) -Isrc -c $< -o $@


test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) -o $@ $^ -pthread

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET) $(TEMP_FILES)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run test
