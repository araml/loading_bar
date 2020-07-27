CC=gcc
FUZZ_CC=afl-gcc

FLAGS=-std=c11 -ggdb -Wall -Wunused-function -Wextra -Wundef --coverage

INCLUDE_DIRS =
INCLUDE= $(foreach p, $(INCLUDE_DIRS), -Isrc/$p)

SRC = main.c

OBJS = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(SRC))))
FOLDERS = $(sort $(addprefix $(BUILD)/, $(dir $(SRC))))

BUILD = build

.PHONY: loading_bar clean
all: loading_bar

debug: FLAGS += -DDEBUG
debug: loading_bar

$(BUILD)/%.o: %.c
	$(CC) -c $^ -o $@ $(INCLUDE) $(FLAGS)

$(FOLDERS):
	mkdir -p build
#mkdir -p $@

loading_bar: $(FOLDERS) $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(FLAGS) $(INCLUDE) -o build/loading_bar

clean:
	rm -rf build

vpath %.c src

