CXX = g++
CXXFLAGS = -Wall -std=c++20

TARGET = bin/strings

SRC = string_manipulation.cpp

$(TARGET): bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

bin:
	mkdir -p bin

clean:
	rm -rf $(TARGET)