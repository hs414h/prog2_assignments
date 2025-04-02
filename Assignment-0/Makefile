# compiler
CXX = g++

# flags
CXXFLAGS = -Wall -std=c++23

# target
TARGET = bin/guess

# source
SRC = guess_the_number.cpp

# build rule
$(TARGET): | bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# create the build folder
bin:
	mkdir -p bin

# clean rule
clean:
	rm -rf $(TARGET)
