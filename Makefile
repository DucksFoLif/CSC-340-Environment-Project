# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Target executable name
TARGET = project_executable

# Source files
SRCS = $(wildcard *.cpp)

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# Run the project
run: all
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET) *.o
