# Creation of a simple command-line shell
![Printf-meme-you-can-never-be-too-serious]https://memegenerator.net/img/instances/54695180/due-to-having-a-windows-command-shell-nothing-to-bash-about.jpg)

> ## Swiss Army Knife
This project was coded on a `Debian 5.18.5-1kali6 x86_64 GNU/Linux` and compiled with `gcc Debian 11.3.0-5) 11.3.0.`

> ### Usage
In order to make use of this shell, make sure to compile the `*.c` files in this repository in this manner:
```bash
gcc -Wall -pedantic -Werror Wextra *.c -o hsh
```
It's safe to run commands now :)
```bash

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