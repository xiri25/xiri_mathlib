CFLAGS=-Wall -Wextra
LDFLAGS_TEST=-lm -g
SRC_FILES_TEST=tests/main.c \
			   random/random.c \
			   src/mathlib/vec2.c \
			   tests/vec2.c

.PHONY: all clean

all: test-gcc test-clang

test-gcc: $(SRC_FILES_TEST)
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS_TEST)

test-clang: $(SRC_FILES_TEST)
	clang $(CFLAGS) -o $@ $^ $(LDFLAGS_TEST)

run-test:
	./test-gcc
	./test-clang

clean:
	rm -f planetas 
