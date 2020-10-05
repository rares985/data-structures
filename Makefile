CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
CFLAGS+=-Iinc -Ipublic
LDFLAGS=-ldata-structures -L/home/uidn4121/shared/personal/data-structures
.DEFAULT_GOAL := main

LIBNAME=libdata-structures.so

SLL_TEST_EXE=sll_test
DLL_TEST_EXE=dll_test

TEST_EXES=$(SLL_TEST_EXE) $(DLL_TEST_EXE)

all: main

main: main.c $(LIBNAME)
	$(CC) $(CFLAGS) main.c -o $@ $(LDFLAGS)


$(LIBNAME): data-structures.o
	$(CC) $(CFLAGS) -shared -Wl,-soname,$(LIBNAME) *.o -o $@

data-structures.o: src/*.c
	@echo "Creating the shared library..."
	$(CC) $(CFLAGS) -c -fpic -fPIC $^


test: $(TEST_EXES)

$(SLL_TEST_EXE): test/$(SLL_TEST_EXE).c $(LIBNAME)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(DLL_TEST_EXE): test/$(DLL_TEST_EXE).c $(LIBNAME)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)	

clean:
	rm main *.o *.so
