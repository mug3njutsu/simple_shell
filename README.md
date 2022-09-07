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
➜  simple_shell git:(main) echo "/bin/ls" | ./hsh
__alias.c      dict.c            getline.h    _isquote.c           quote.h
alias.h        dict.h            __help.c     _isspace.c           README.md
arrdup.c       dict_to_env.c     history.h    _isspecial_double.c  remove_comments.c
arrjoin.c      __env.c           hsh          list.c               __setenv.c
atou.c         env.h             hsh.c        list.h               _signal.c
builtins.c     env_to_dict.c     hsh.h        main.h               split_cmd.c
builtins.h     error.c           info.c       man_1_simple_shell   str.c
__cd.c         error.h           info.h       mem.c                string.h
cmdlist.c      __exec.c          input.c      num_to_str.c         strjoin.c
cmd_to_list.c  execute.c         _isalnum.c   parse.c              strn.c
cmdtree.c      __exit.c          _isalpha.c   path.c               tokens.c
command.h      expand_aliases.c  _isdigit.c   path.h               tokens.h
ctype.h        expand_vars.c     _isident.c   _quote.c             types.h
dequote.c      getline.c         _isnumber.c  quote.c              __unsetenv.c
➜  simple_shell git:(main) ./hsh 
l33tsh3ll$ ls
__alias.c      dict.c            getline.h    _isquote.c           quote.h
alias.h        dict.h            __help.c     _isspace.c           README.md
arrdup.c       dict_to_env.c     history.h    _isspecial_double.c  remove_comments.c
arrjoin.c      __env.c           hsh          list.c               __setenv.c
atou.c         env.h             hsh.c        list.h               _signal.c
builtins.c     env_to_dict.c     hsh.h        main.h               split_cmd.c
builtins.h     error.c           info.c       man_1_simple_shell   str.c
__cd.c         error.h           info.h       mem.c                string.h
cmdlist.c      __exec.c          input.c      num_to_str.c         strjoin.c
cmd_to_list.c  execute.c         _isalnum.c   parse.c              strn.c
cmdtree.c      __exit.c          _isalpha.c   path.c               tokens.c
command.h      expand_aliases.c  _isdigit.c   path.h               tokens.h
ctype.h        expand_vars.c     _isident.c   _quote.c             types.h
dequote.c      getline.c         _isnumber.c  quote.c              __unsetenv.c
```
```bash
➜  simple_shell git:(main) ✗ ./hsh 
l33tsh3ll$ exit 98
➜  simple_shell git:(main) ✗ echo $?
98
```
```bash
➜  simple_shell git:(main) ✗ ./hsh 
l33tsh3ll$ ls /var;ls /var
backups  cache  games  lib  local  lock  log  mail  opt  run  spool  tmp  www
backups  cache  games  lib  local  lock  log  mail  opt  run  spool  tmp  www
l33tsh3ll$ ls /hbtn;ls /var
ls: cannot access '/hbtn': No such file or directory
backups  cache  games  lib  local  lock  log  mail  opt  run  spool  tmp  www
l33tsh3ll$ ls /var;ls /hbtn;ls /var;ls /var
backups  cache  games  lib  local  lock  log  mail  opt  run  spool  tmp  www
ls: cannot access '/hbtn': No such file or directory
backups  cache  games  lib  local  lock  log  mail  opt  run  spool  tmp  www
backups  cache  games  lib  local  lock  log  mail  opt  run  spool  tmp  www
```
```bash
➜  simple_shell git:(main) ✗ ./hsh 
l33tsh3ll$ ls /var
backups  cache  games  lib  local  lock  log  mail  opt  run  spool  tmp  www
l33tsh3ll$ echo $?
0
l33tsh3ll$ echo $$
6434
l33tsh3ll$ echo $PATH
/home/mug3njutsu/.poetry/bin:/home/mug3njutsu/.rbenv/plugins/ruby-build/bin:/home/mug3njutsu/.rbenv/shims:/home/mug3njutsu/.rbenv/bin:/home/mug3njutsu/.rbenv/shims:/home/mug3njutsu/.rbenv/bin:/usr/local/sbin:/usr/sbin:/sbin:/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/home/mug3njutsu/.dotnet/tools:/usr/lib/postgresql/10/bin:/home/mug3njutsu/.cargo/bin/
```
```bash
➜  simple_shell git:(main) ✗ ./hsh 
l33tsh3ll$ echo $$ # ls -la
6605
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