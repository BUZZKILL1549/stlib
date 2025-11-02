CC = clang
AR = llvm-ar
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/vector.c src/hashtable.c src/linkedlist.c src/stack.c src/queue.c src/set.c src/bst.c
OBJ = $(SRC:.c=.o)
LIB = libstlib.a

ifeq ($(OS),Windows_NT)
    EXEEXT = .exe
    RM = del /Q
else
    EXEEXT =
    RM = rm -f
endif

EXAMPLES := $(patsubst %.c,%$(EXEEXT),$(wildcard examples/*.c))

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

examples: $(EXAMPLES)

examples/%$(EXEEXT): examples/%.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< $(LIB)

clean:
	$(RM) src\\*.o examples\\*$(EXEEXT) examples\\*.o libstlib.a 2>nul || true
