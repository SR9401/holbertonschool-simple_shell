# ***Simple Shell***



## *Description*

**Simple Shell** is a basic Unix-like command-line shell written in C. It supports a limited set of built-in commands and can execute external programs found in the system's PATH.

## *Compilation Command*

To compile `simple shell`, use the following commande :

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## *Requiements*

The project was developped and tested in the following environment: 
- Ubuntu 20.04 LTS
- GCC (GNU Compiler Collection)
- Git for source code management

### *Installation*

Clone the repository and compile the program:
```sh
git clone https://github.com/SR9401/holbertonschool-simple_shell.git
```
```sh
cd holbertonschool-simple_shell
```
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the shell:
```
./hsh
```
## *Exemple*
```sh
juleslgc@VENTURA:~/holbertonschool-simple_shell$ ./hsh
$ ls
fork_exec_wait.c  main.h  mypid   pid.c   av.c  exec.c  find_path.c
$ 
```

## *Man Page*

## *Flowchart*

## *Authors*

[Shakib ROJAS]() 
&
[Jules VENTURA]()