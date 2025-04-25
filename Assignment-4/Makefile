CXX = g++

CXXFLAGS = -Wall -std=c++20

TARGET = bin/arraysp2

SRC = arrays_part2.cpp

$(TARGET): bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

bin:
	mkdir -p bin

clean:
	rm -rf $(TARGET)