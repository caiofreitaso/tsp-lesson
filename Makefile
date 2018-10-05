CPP_FILES := $(wildcard src/*.c)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.c=.o)))
LD_FLAGS := -mmmx \
-msse -msse2 -msse3 -malign-double -m64 -ftree-vectorize -ftree-vectorizer-verbose=2
CC_FLAGS := -mmmx \
-msse -msse2 -msse3 -malign-double -m64 -ftree-vectorize -ftree-vectorizer-verbose=2

#all: LD_FLAGS += -DOPT_NSGA2
#all: CC_FLAGS += -DOPT_NSGA2
all: add

add: debug main
#maingit add makefile src/* include/* model/* sys/* state/* hv/* irace/*

debug: LD_FLAGS += -ggdb
debug: CC_FLAGS += -ggdb
debug: $(OBJ_FILES)
	gcc $(LD_FLAGS) -o $@ $^

main: LD_FLAGS += -O3
main: $(OBJ_FILES)
	gcc $(LD_FLAGS) -o $@ $^

clean:
	rm main debug obj/*


obj/%.o: src/%.c
	gcc $(CC_FLAGS) -c -o $@ $<

-include $(OBJFILES:.o=.d)
