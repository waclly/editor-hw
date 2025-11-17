CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

TARGETS = checker validator

all: $(TARGETS)

checker: checker.cpp simple_validator.hpp
	$(CXX) $(CXXFLAGS) -o checker checker.cpp

validator: main.cpp simple_validator.hpp
	$(CXX) $(CXXFLAGS) -o validator main.cpp

clean:
	rm -f $(TARGETS)

.PHONY: all clean
