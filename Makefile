CC = clang
AR = llvm-ar
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/vector.c src/hashtable.c src/linkedlist.c
OBJ = $(SRC:.c=.o)
LIB = libstlib.a

ifeq ($(OS),Windows_NT)
    RM = del /Q
else
    RM = rm -f
endif

$(LIB): $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) src\\vector.o src\\hashtable.o src\\linkedlist.o libstlib.a 2>nul || true