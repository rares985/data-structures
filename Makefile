CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17 -g
# CXXFLAGS += -Werror

INCLUDES=-Iinc

EXE=main
OBJ_DIR=obj/
SRC_DIR = src/


SRC = $(shell find $(SRC_DIR) -name '*.cpp' -printf "%f ")
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all

all: $(EXE)

$(EXE): main.cpp $(OBJ)
	echo $(SRC)
	echo $(OBJ)
	$(CXX) $(INCLUDES) $(CXXFLAGS) $^ -o $@

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(info Building objects...)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o $@ -c $<



clean:
	rm -rf *.o
	rm -rf obj/*.o
	rm -rf $(EXE)