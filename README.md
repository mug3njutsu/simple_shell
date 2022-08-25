# Creation of a simple command-line shell
![Spamming the command-line :P](https://memegenerator.net/img/instances/62332220/embrace-the-power-of-the-command-line.jpg)

> ## Swiss Army Knife
This project was coded on a `Debian 5.18.5-1kali6 x86_64 GNU/Linux` and compiled with `gcc Debian 11.3.0-5) 11.3.0.`

> ### Usage
In order to make use of this shell, make sure to compile the `*.c` files in this repository in this manner:
```bash
gcc -Wall -pedantic -Werror Wextra *.c -o hsh
```
It's safe to run commands now :)
```bash
➜  simple_shell git:(main) ./hsh 
l33tsh3ll$ whoami
mug3njutsu
l33tsh3ll$ ls
__builtins__.c   cleanexit.c  hsh     man_1_simple_shell  README.md
checkbuiltins.c  exec.c       main.h  pathlinkage.c       string.c
l33tsh3ll$ ls /var
backups  cache  lib  local  lock  log  mail  opt  run  spool  tmp  www
l33tsh3ll$ echo "3l33t"
"3l33t"
l33tsh3ll$ 
```

> ### Description
A command-line shell helps us run commands on a unix machine, in this case i was using a Debian distro.
This is a simple recreation of the default shell that you'll find on any of the unix operating systems.

> ### Allowed funcs & Syscalls
* access
* chdir
* close
* closedir
* execve
* exit
* _exit 
* fflush
* fork
* free
* getcwd
* getline
* getpid
* isatty
* kill
* malloc
* open
* opendir
* perror
* read
* readdir
* signal
* stat 
* lstat 
* fstat 
* strtok
* wait
* waitpid
* wait3
* wait4
* write