CPP_FILES := $(wildcard src/*.c)
TEST_FILES := $(wildcard test/*.c)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.c=.o)))
INCLUDE_OBJ_FILES := $(filter-out obj/main.o, $(OBJ_FILES))
TEST_OUTPUT := $(addprefix test/,$(notdir $(TEST_FILES:.c=.o)))
LD_FLAGS := -Wall -Werror -mmmx \
-msse -msse2 -msse3 -malign-double -m64 -ftree-vectorize -ftree-vectorizer-verbose=2
CC_FLAGS := -Wall -Werror -mmmx \
-msse -msse2 -msse3 -malign-double -m64 -ftree-vectorize -ftree-vectorizer-verbose=2

#all: LD_FLAGS += -DOPT_NSGA2
#all: CC_FLAGS += -DOPT_NSGA2
all: add test

add: debug main
#maingit add makefile src/* include/* model/* sys/* state/* hv/* irace/*

debug: LD_FLAGS += -ggdb
debug: CC_FLAGS += -ggdb
debug: $(OBJ_FILES)
	gcc $(LD_FLAGS) -o $@ $^

main: LD_FLAGS += -O3
main: $(OBJ_FILES)
	gcc $(LD_FLAGS) -o $@ $^

test: $(INCLUDE_OBJ_FILES) $(TEST_OUTPUT)

test/%.o: test/%.c
	gcc $(LD_FLAGS) -o $@ $(INCLUDE_OBJ_FILES) $<

clean:
	rm main debug obj/* test/*.o

obj/%.o: src/%.c
	gcc $(CC_FLAGS) -c -o $@ $<

-include $(OBJFILES:.o=.d)
