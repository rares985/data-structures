CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -g
# CXXFLAGS += -Werror

INCLUDES=-Iinc

EXE=main
OBJ_DIR=obj/

.PHONY: all

SRC := $(wildcard src/.cpp)
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(EXE)

$(EXE): main.cpp $(OBJ)
	$(CXX) $(INCLUDES) $(CXXFLAGS) $^ -o $@

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf obj/*.o
	rm -rf $(EXE)