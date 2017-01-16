CC=clang
ifndef CC_VEC
CC_VEC=clang
endif

CFLAGS=-O3 --save-temps
#CFLAGS_VEC=-O3 --save-temps
CFLAGS_VEC:=$(CFLAGS)
CFLAGS+=-fblocks

# x86
#CFLAGS += -mfma -mavx

# for take a look generated code
CFLAGS += --save-temps

all: test test_tile test_vec test_gcd test_gcd_tile test_gcd_vec

test_gcd_vec: test_gcd.o vec.o
	$(CC) -o test_gcd_vec test_gcd.o vec.o -ldispatch -lBlocksRuntime

test_gcd_tile: test_gcd.o tile.o
	$(CC) -o test_gcd_tile test_gcd.o tile.o -ldispatch -lBlocksRuntime

test_gcd: test_gcd.o naive.o
	$(CC) -o test_gcd test_gcd.o naive.o -ldispatch -lBlocksRuntime

test_vec: test.o vec.o
	$(CC) -o test_vec test.o vec.o

test_tile: test.o tile.o
	$(CC) -o test_tile test.o tile.o

test: test.o naive.o
	$(CC) -o test test.o naive.o

vec.o: vec.c
	$(CC_VEC) $(CFLAGS_VEC) -c vec.c

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o *.bc *.s *.i test test_tile test_vec test_gcd test_gcd_tile test_gcd_vec
