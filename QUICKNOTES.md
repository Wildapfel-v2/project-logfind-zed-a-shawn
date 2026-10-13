**dev/01-glob-sandbox**

- I started evaluating how `glob` works only using the manual and trying out

- I find it works similiar to `ls`

- I noticed that why C ecosystem is so awesome... everthing is documented and accessible via `man` :D

**dev/02-prototype-without-glob-functionality**

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

**bugs**

***Very weird error. I have no glue^***

- ```bash
  /var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/dbg.h:29:41: error: jump into scope of identifier with variably modified type  
    29 |     log_err(M, ##__VA_ARGS__); errno=0; goto error; }
  ```

- `const int SIZE = 500;` is **not** a constant in C → using it as an array size makes a **VLA**.

- `dbg.h`'s `check`/`check_mem` do `goto error`, and C forbids jumping into the scope of a VLA.

- Fix: use `#define SIZE 500` or `enum { SIZE = 500 };` instead of `const int`.
