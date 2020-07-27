CC=gcc
FUZZ_CC=afl-gcc

FLAGS=-std=c11 -ggdb -Wall -Wunused-function -Wextra -Wundef --coverage

INCLUDE_DIRS =
INCLUDE= $(foreach p, $(INCLUDE_DIRS), -Isrc/$p)
INCLUDE += -Isrc/

SRC = main.c loading_bar.c

OBJS = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(SRC))))
FOLDERS = $(sort $(addprefix $(BUILD)/, $(dir $(SRC))))

BUILD = build

.PHONY: loading_bar clean test
all: loading_bar
test: test

debug: FLAGS += -DDEBUG
debug: loading_bar

$(BUILD)/%.o: %.c
	$(CC) -c $^ -o $@ $(INCLUDE) $(FLAGS)

$(FOLDERS):
	mkdir -p build
#mkdir -p $@

loading_bar: $(FOLDERS) $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(FLAGS) $(INCLUDE) -o build/loading_bar

test:
	$(CC) tests/test_bar.c src/loading_bar.c -lcmocka $(INCLUDE) -o build/test_bar
	./build/test_bar

clean:
	rm -rf build

vpath %.c src

