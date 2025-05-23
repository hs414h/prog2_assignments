CXX = g++
CXXFLAGS = -Wall -std=c++20

TARGET = bin/fun1

SRC = functions_part1.cpp

$(TARGET): bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

bin:
	mkdir -p bin

clean:
	rm -rf $(TARGET)