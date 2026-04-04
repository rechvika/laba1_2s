CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Itests/include
LDFLAGS = -Lbuild -L.
LDLIBS = -lapp

SRC_DIR = src
OBJ_DIR = obj
TESTS_OBJ_DIR = obj/tests
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

TEST_SRCS = $(TESTS_SRC_DIR)/assertions.c \
            $(TESTS_SRC_DIR)/testing.c \
            $(TESTS_SRC_DIR)/tests_array.c \
            $(TESTS_SRC_DIR)/tests_base.c \
            $(TESTS_SRC_DIR)/tests_data.c \
            $(TESTS_SRC_DIR)/tests_operations.c \
            $(TESTS_SRC_DIR)/tests_other.c \
            $(TESTS_SRC_DIR)/tests_polimorf.c \
            $(TESTS_SRC_DIR)/tests_serialize.c \
            $(TESTS_SRC_DIR)/tests_typeinfo.c \
            $(TESTS_SRC_DIR)/main_test.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST_OBJS = $(TEST_SRCS:$(TESTS_SRC_DIR)/%.c=$(TESTS_OBJ_DIR)/%.o)

APP_LIB = build/libapp.a
TARGET = build/test_model
APP_TARGET = build/app
APP_MAIN = src/main.c

.PHONY: all clean run test

all: $(TARGET) $(APP_TARGET)

run: $(APP_TARGET)
	./$(APP_TARGET)

test: $(TARGET)
	./$(TARGET)

$(TARGET): $(TEST_OBJS) $(APP_LIB)
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(APP_TARGET): $(APP_MAIN) $(APP_LIB)
	@mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(APP_LIB): $(OBJS)
	@mkdir -p build
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTS_OBJ_DIR)/%.o: $(TESTS_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TESTS_OBJ_DIR) build