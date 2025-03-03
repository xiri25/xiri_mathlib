CFLAGS=-Wall -Wextra
LDFLAGS_TEST=-lm -g
SRC_FILES_TEST=tests/main.c \
			   random/random.c \
			   src/mathlib/vec2.c \
			   src/mathlib/vec3.c \
			   tests/vec2.c \
			   tests/vec3.c

.PHONY: all clean

all: test-gcc test-clang test-gcc-O1 test-clang-O1 test-gcc-O2 test-clang-O2 test-gcc-O3 test-clang-O3

test-gcc: $(SRC_FILES_TEST)
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS_TEST)

test-clang: $(SRC_FILES_TEST)
	clang $(CFLAGS) -o $@ $^ $(LDFLAGS_TEST)

test-gcc-O1: $(SRC_FILES_TEST)
	gcc $(CFLAGS) -O1 -o $@ $^ $(LDFLAGS_TEST)

test-clang-O1: $(SRC_FILES_TEST)
	clang $(CFLAGS) -O1 -o $@ $^ $(LDFLAGS_TEST)

test-gcc-O2: $(SRC_FILES_TEST)
	gcc $(CFLAGS) -O2 -o $@ $^ $(LDFLAGS_TEST)

test-clang-O2: $(SRC_FILES_TEST)
	clang $(CFLAGS) -O2 -o $@ $^ $(LDFLAGS_TEST)

test-gcc-O3: $(SRC_FILES_TEST)
	gcc $(CFLAGS) -O3 -o $@ $^ $(LDFLAGS_TEST)

test-clang-O3: $(SRC_FILES_TEST)
	clang $(CFLAGS) -O3 -o $@ $^ $(LDFLAGS_TEST)

run-test:
	./test-gcc
	./test-clang
	./test-gcc-O1
	./test-clang-O1
	./test-gcc-O3
	./test-clang-O2
	./test-gcc-O3
	./test-clang-O3

clean:
	rm -f test-*
