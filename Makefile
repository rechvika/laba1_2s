CC = gcc

CFLAGS = -Wall -Wextra -Iinclude -Itests/include

SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build
TESTS_DIR = tests
TESTS_SRC_DIR = tests/src

SRCS = $(SRC_DIR)/array_of_person.c \
       $(SRC_DIR)/concatenation.c \
       $(SRC_DIR)/map.c \
       $(SRC_DIR)/where.c \
       $(SRC_DIR)/serialize.c \
       $(SRC_DIR)/typeinfo.c \
       $(SRC_DIR)/test_person.c \
       $(SRC_DIR)/conclusion.c

TEST_SRCS = $(TESTS_SRC_DIR)/tests_array.c \
            $(TESTS_SRC_DIR)/tests_base.c \
            $(TESTS_SRC_DIR)/tests_data.c \
            $(TESTS_SRC_DIR)/tests_operations.c \
            $(TESTS_SRC_DIR)/tests_other.c \
            $(TESTS_SRC_DIR)/tests_polimorf.c \
            $(TESTS_SRC_DIR)/tests_serialize.c \
            $(TESTS_SRC_DIR)/tests_typeinfo.c \
            $(TESTS_SRC_DIR)/assertions.c \
            $(TESTS_SRC_DIR)/testing.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:$(TESTS_SRC_DIR)/%.c=$(OBJ_DIR)/tests/%.o)

TARGET = $(BUILD_DIR)/program.exe
TEST_TARGET = $(BUILD_DIR)/tests.exe

.PHONY: all clean test run

all: $(TARGET)

run: $(TARGET)
	build/program.exe

$(TARGET): $(SRC_DIR)/main.c $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ 

test: $(TEST_TARGET)
	build/tests.exe

$(TEST_TARGET): $(TEST_SRCS) $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)