CC = "gcc"
SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
INC := -lSDL2

main: $(OBJ_FILES)
	$(CC) -o $@ $^ $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c -o $@ $<

clean:
	rm $(OBJ_FILES)
	rm ./main