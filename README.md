# STLIB: A library of standard data structures for C

## STLIB currently implements the following datastructures:
- Vectors
- Hashtables
- Linked lists (doubly linked)
- Sets
- Stacks
- Queues
- Binary Search Trees

## To include in your own projects:
### Option 1: Static linking:
- Step 1: Clone the github repo

    ` git clone https://github.com/BUZZKILL1549/stlib.git ` 

- Step 2: Link it to your Makefile

    Example Project Structure:
    ```
     my_project/
        │
        ├── src/
        │   └── main.c
        ├── libs/
        │   └── stlib/          ← your library
        └── Makefile
    ```

    Example Makefile:
    ```
    CC = clang
    CFLAGS = -Wall -Wextra -Ilibs/stlib/include
    LDFLAGS = libs/stlib/libstlib.a

    SRC = src/main.c
    OUT = my_program.exe

    all: $(OUT)

    $(OUT): $(SRC)
        $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

    run: $(OUT)
        ./$(OUT)
    ```

    Then you can just include and use it as you would any normal header.

### Option 2: System-wide install
Currently not supported. I'll change this once it is.

### Option 3: Github inclusion
You can add this library as a repository as well:

``` git submodule add https://github.com/BUZZKILL1549/stlib libs/stlib```

After this, you just have to add your libs folder into your Makefile flag:

```
CFLAGS = -Ilibs/stlib/include
LDFLAGS = libs/stlib/libstlib.a
```

To update the library after this:

``` git submodule update --remote --merge ```