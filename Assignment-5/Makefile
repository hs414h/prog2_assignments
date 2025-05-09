CXX = g++
CXXFLAGS = -Wall -std=c++20

TARGET = bin/primef

SRC = prime_factorisation.cpp

$(TARGET): bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

bin:
	mkdir -p bin

clean:
	rm -rf $(TARGET)