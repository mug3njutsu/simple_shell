# Creation of a simple command-line shell
![Printf-meme-you-can-never-be-too-serious](https://memegenerator.net/img/instances/54695180/due-to-having-a-windows-command-shell-nothing-to-bash-about.jpg)

> ## Swiss Army Knife
This project was coded on a `Debian 5.18.5-1kali6 x86_64 GNU/Linux` and compiled with `gcc (Debian 11.3.0-5) 11.3.0.`

> ### Usage
In order to make use of this custom function, make sure to compile the `*.c` files in this repository in this manner:
```bash
gcc -Wall -pedantic -Werror Wextra *.c -o hsh
```

> ### Description
A command-line shell helps us run commands on a unix machine, in this case i was using a Debian distro.
This is a simple recreation of the default shell that you'll find on any of the unix operating systems.

> ### Syscalls implemented
* access
* execve
* exit
* fflush
* fork
* malloc
* signal
* stat
* lstat
* fstat