CFLAGS=-Wall -Wextra
LDFLAGS_BENCHMARK=-lm -g
SRC_FILES_BENCHMARK=main.c \
				../random/random.c \
			    ../src/mathlib/vec2.c \
			    ../src/mathlib/vec3.c

BENCHMARK_TARGETS = \
    benchmark-gcc \
    benchmark-clang \
    benchmark-gcc-O1 \
    benchmark-clang-O1 \
    benchmark-gcc-O2 \
    benchmark-clang-O2 \
    benchmark-gcc-O3 \
    benchmark-clang-O3 \
    benchmark-gcc-mavx \
    benchmark-clang-mavx \
    benchmark-gcc-O1-mavx \
    benchmark-clang-O1-mavx \
    benchmark-gcc-O2-mavx \
    benchmark-clang-O2-mavx \
    benchmark-gcc-O3-mavx \
    benchmark-clang-O3-mavx

.PHONY: all clean run-benchmark

all: $(BENCHMARK_TARGETS)

benchmark-gcc: $(SRC_FILES_BENCHMARK)
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-clang: $(SRC_FILES_BENCHMARK)
	clang $(CFLAGS) -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-gcc-O1: $(SRC_FILES_BENCHMARK)
	gcc $(CFLAGS) -O1 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-clang-O1: $(SRC_FILES_BENCHMARK)
	clang $(CFLAGS) -O1 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-gcc-O2: $(SRC_FILES_BENCHMARK)
	gcc $(CFLAGS) -O2 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-clang-O2: $(SRC_FILES_BENCHMARK)
	clang $(CFLAGS) -O2 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-gcc-O3: $(SRC_FILES_BENCHMARK)
	gcc $(CFLAGS) -O3 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-clang-O3: $(SRC_FILES_BENCHMARK)
	clang $(CFLAGS) -O3 -o $@ $^ $(LDFLAGS_BENCHMARK)


benchmark-gcc-mavx : $(SRC_FILES_BENCHMARK)
	gcc $(CFLAGS) -mavx -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-clang-mavx : $(SRC_FILES_BENCHMARK)
	clang $(CFLAGS) -mavx -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-gcc-O1-mavx : $(SRC_FILES_BENCHMARK)
	gcc $(CFLAGS) -mavx -O1 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-clang-O1-mavx : $(SRC_FILES_BENCHMARK)
	clang $(CFLAGS) -mavx -O1 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-gcc-O2-mavx : $(SRC_FILES_BENCHMARK)
	gcc $(CFLAGS) -mavx -O2 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-clang-O2-mavx : $(SRC_FILES_BENCHMARK)
	clang $(CFLAGS) -mavx -O2 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-gcc-O3-mavx : $(SRC_FILES_BENCHMARK)
	gcc $(CFLAGS) -mavx -O3 -o $@ $^ $(LDFLAGS_BENCHMARK)

benchmark-clang-O3-mavx : $(SRC_FILES_BENCHMARK)
	clang $(CFLAGS) -mavx -O3 -o $@ $^ $(LDFLAGS_BENCHMARK)

run-benchmark:
	./benchmark-gcc
	./benchmark-clang
	./benchmark-gcc-O1
	./benchmark-clang-O1
	./benchmark-gcc-O2
	./benchmark-clang-O2
	./benchmark-gcc-O3
	./benchmark-clang-O3
	./benchmark-gcc-mavx
	./benchmark-clang-mavx
	./benchmark-gcc-O1-mavx
	./benchmark-clang-O1-mavx
	./benchmark-gcc-O2-mavx
	./benchmark-clang-O2-mavx
	./benchmark-gcc-O3-mavx
	./benchmark-clang-O3-mavx

clean:
	rm -f benchmark-*
