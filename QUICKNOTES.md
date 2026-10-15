## Comments

**dev/00-archive/prototype-without-glob-functionality-first-apporach**

- Zed suggest to start first without the glob functionality, thats why i build some dummy-data and will first develop a simpler program

- *use this alias for faster compile and run:*

- ```bash
  alias cr="make /var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/ex26_main && /var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/ex26_main"
  ```

- *maybe use this to quicker open in konsole*

- ```bash
  cd Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/
  clear
  ```

- *quicknote:* int \*locs = (int*) malloc(N_DUMMIES * sizeof(int)) correct way to initialize the a locs, because its shared between function (out of scope)

- I moved this to archive (previously first apporach to Prototypeing)

**dev/01-testing-functionality/glob**

- I started evaluating how `glob` works only using the manual and trying out

- I find it works similiar to `ls`

- I noticed that why C ecosystem is so awesome... everthing is documented and accessible via `man` :D

**dev/01-testing-functionality/pattern**

- Either I need to implement myself, but i found the `strstr` fucntion in `<string.h>` which seems to do the exact behaviour I want

- I evaluated, `strstr` returns the first occurence, let me validate if this just the pointer postion accroding to the location in the text (or haystack xD)

  - its either a pointer to the position of the first occurence

  - or a nul pointer

**dev/01-testing-functionality/nextline**

- the `FILE *` struct has read pointer which I should manipulate/use

- dont touch the opaque from developer (what ever underscore \_\_function) 

  - ```c
    // I tried: 
    *fp->_IO_read_ptr = *test;
    ```

- Solutions

  - **`fgetpos` / `fsetpos`** — save/restore the position using an opaque `fpos_t` token. Portable, and the library handles all internal buffer bookkeeping for you.

**dev/02-prototype-without-glob-functionality**

- This should turn into the actual protoype, I will build the program using the `readline/readlines` and the `strstr`

- *Compile*

- ```bash
  gcc -c string_utils.c -o string_utils.o    # intermediate object
  gcc string_utils.o main.c -o main          # actual program
  ```

- make an alias

- ```bash
  alias cr="gcc -c string_utils.c -o string_utils.o && gcc string_utils.o main.c -o main && ./main "
  ```

- make an alias for testing patterns args via commandline

- ```bash
  alias crpattern="gcc -c string_utils.c -o string_utils.o && gcc string_utils.o main.c -o main && ./main hose test dev quantum"
  ```

## Bugs

***Very weird error. I have no glue yet***

- ```bash
  /var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/dbg.h:29:41: error: jump into scope of identifier with variably modified type  
    29 |     log_err(M, ##__VA_ARGS__); errno=0; goto error; }
  ```

- `const int SIZE = 500;` is **not** a constant in C → using it as an array size makes a **VLA**.

- `dbg.h`'s `check`/`check_mem` do `goto error`, and C forbids jumping into the scope of a VLA.

- Fix: use `#define SIZE 500` or `enum { SIZE = 500 };` instead of `const int`.
