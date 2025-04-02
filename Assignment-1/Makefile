# compiler
CXX = g++

# flags
CXXFLAGS = -Wall -std=c++23

# target output name (executable)
TARGET = bin/qsolver

# source file
SRC = quadratic_equation_solver.cpp

# build rule
$(TARGET): bin
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# create bin folder
bin:
	mkdir -p bin

# Clean rule
clean:
	rm -rf $(TARGET)
