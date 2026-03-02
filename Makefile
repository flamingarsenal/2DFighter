# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# Project structure
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = build/game

# Asset directories
ASSETS = assets
BUILD_ASSETS = build/assets

# Default target
all: $(BIN) copy_assets

# Link object files into final binary
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(LDFLAGS)

# Compile source files into object files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Copy assets (sprites, audio, etc.) into build folder
copy_assets:
	mkdir -p $(BUILD_ASSETS)
	cp -r $(ASSETS)/* $(BUILD_ASSETS)/ || true

# Clean build artifacts
clean:
	rm -f src/*.o $(BIN)
	rm -rf $(BUILD_ASSETS)

# Run the game (build + execute)
run: all
	./$(BIN)
