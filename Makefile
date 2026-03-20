CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Itests/include
LDFLAGS = 
LDLIBS = -lm 

SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build

SRCS = $(SRC_DIR)/array_of_person.c $(SRC_DIR)/concatenation.c \
       $(SRC_DIR)/map.c $(SRC_DIR)/where.c \
	   $(SRC_DIR)/test_person.c $(SRC_DIR)/person_typeinfo.c \
	   $(SRC_DIR)/ conclusion.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB = build/libapp.a
TARGET = build/program

.PHONY: all clean

all: $(TARGET)

$(TARGET): src/main.c $(LIB)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(LIB) $(TARGET)