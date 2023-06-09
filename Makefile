CC = g++
CFLAGS = -Wall -std=c++11

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
MAIN_OBJ = $(BUILD_DIR)/main.o
EXEC = trabalho

all: $(EXEC)

$(EXEC): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(MAIN_OBJ): src/main.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXEC)