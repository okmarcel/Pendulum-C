CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I./include
LDFLAGS = $(shell sdl2-config --libs)
CFLAGS += $(shell sdl2-config --cflags)

SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/pendulum

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean