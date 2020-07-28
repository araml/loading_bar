CC=gcc
FUZZ_CC=afl-gcc

FLAGS=-std=c11 -ggdb -Wall -Wunused-function -Wextra -Wundef --coverage

INCLUDE_DIRS =
INCLUDE= $(foreach p, $(INCLUDE_DIRS), -Isrc/$p)
INCLUDE += -Isrc/

SRC = loading_bar.c

OBJS = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(SRC))))
FOLDERS = $(sort $(addprefix $(BUILD)/, $(dir $(SRC))))

BUILD = build

.PHONY: loading_bar clean tests
all: loading_bar_dynamic
#static: loading_bar_static
dynamic: loading_bar_dynamic
tests: loading_bar_dynamic test

debug: FLAGS += -DDEBUG
debug: loading_bar

$(BUILD)/%.o: %.c
	$(CC) -c $^ -o $@ $(INCLUDE) $(FLAGS)

$(FOLDERS):
	mkdir -p build
#mkdir -p $@

loading_bar_static: $(FOLDERS) $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(FLAGS) $(INCLUDE) -o build/loading_bar

loading_bar_dynamic: $(FOLDERS) $(OBJS)
	gcc -shared $(OBJS) -lgcov -o build/liblbar.so

test:
	$(CC) tests/test_bar.c -lcmocka -Lbuild/ -llbar $(INCLUDE) -o build/test_bar
	./build/test_bar

clean:
	rm -rf build

vpath %.c src

