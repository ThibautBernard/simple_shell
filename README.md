# SIMPLE SHELL **v1**
![Shell_Illustration](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1f/Tcsh_ejecutándose_en_escritorio_Mac_OSX.png/1200px-Tcsh_ejecutándose_en_escritorio_Mac_OSX.png)
## Context of this project
This project was the last project of the first timester of Holberton School, his purpose was to **re-write a shell in *only 16 days***, by group of 2. 
### [See our article](https://olivier-guyot-cu.medium.com/what-happened-when-you-type-ls-l-6e949275d268)
## Notions 
1. **Struct / typedef**
2. **Child Process**
3. **Linked list**
4. **Pointers of function**
5. **Working on same repository Github**
6. **Memory allocation**
7. **Respect of deadline**
8. **Project management**
9. **Design architecture**
### What learned with this project
   * **Who designed and implemented the original Unix operating system.**
   * **Who wrote the first version of the UNIX shell**
   * **Who invented the B programming language (the direct predecessor to the C programming language).**
   * **Who is Ken Thompson.**
   * **How does a shell work.**
   * **What is a pid and a ppid.**
   * **How to manipulate the environment of the current process**
   * **What is the difference between a function and a system call.**
   * **How to create processes.**
   * **What are the three prototypes of main.**
   * **How does the shell use the PATH to find the programs.**
   * **How to execute another program with the execve system call.**
   * **How to suspend the execution of a process until one of its children terminates.**
   * **What is EOF / “end-of-file”?**

## list of built-ins
1. **setenv**
    * Usage: setenv **[Variable]** **[Value]**
    * Initialize a new variable or update variable in environment
2. **unsetenv**
    * Usage: unsetenv **[Variable]**
    * Remove a variable in environment
3. **env**
    * Print the environment
4. **exit**
    * Usage: exit **[status]**
    * Exit all the processus
5. **cd**
    * Usage: cd
    * Change directory
## How to install
* ``` git clone https://github.com/ThibautBernard/simple_shell ```
## How to execute
* ``` gcc -Wall -Werror -Wextra -pedantic *.c -o hsh ```

## To launch the shell (interactive mode)
* ``` ./hsh ```
* ``` $ command_you_choose```

## To launch the shell (non interactive mode)
* ``` echo "command_you_choose" | ./hsh ```
* ``` result of the precedent command```

## How to change the prompt
``` 
vagrant@vagrant-ubuntu$ ./hsh
$ setenv PS1 test$
test$
test$ unsetenv PS1
$
$ exit
vagrant@vagrant-ubuntu$
 ``` 

## Examples : 
``` 
vagrant@vagrant-ubuntu$ ./hsh
$ pwd
/home/vagrant/simple_shell
$ /bin/pwd
/home/vagrant/simple_shell
$ ls -la
total 176
drwxrwxr-x 3 vagrant vagrant  4096 Mar 22 22:27 .
drwxrwxr-x 4 vagrant vagrant  4096 Mar 22 22:27 ..
drwxrwxr-x 7 vagrant vagrant  4096 Mar 21 21:05 shell.c
-rwxrwxr-x 1 vagrant vagrant 13986 Mar 22 20:45 check.c
-rw-rw-r-- 1 vagrant vagrant   369 Mar 22 20:47 _strtok.c
...
 ``` 
 
 ## All function in a tree
 
 ![Shell_Illustration](https://github.com/ThibautBernard/simple_shell/blob/main/versionB/Shell%20Function.png?raw=true)
 
 ***done by Olivier Guyot && Thibaut Bernard***

