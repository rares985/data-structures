CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17 -g -Wno-unused-function
# CXXFLAGS += -Werror

INCLUDES=-Iinc

EXE=tests
EXE_CPP=$(EXE).cpp
OBJ_DIR=obj/
SRC_DIR = src/
UT_DIR := gtest


SRC = $(shell find $(SRC_DIR) -name '*.cpp' -printf "%f ")
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all

all: $(EXE)

$(EXE): $(EXE_CPP) $(OBJ)
	$(CXX) $(INCLUDES) $(CXXFLAGS) $^ -o $@

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(info Building objects...)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o $@ -c $<

test: $(TEST_CPP) $(OBJ) $(TEST_OBJ)
	$(MAKE) -C $(UT_DIR) $@


testclean:
	$(MAKE) -C $(UT_DIR) $@



clean:
	rm -rf *.o
	rm -rf obj/*.o
	rm -rf $(EXE)