# Project `Simple Shell`

This `README.md` will contain the necessary files for the `Simple Shell` project. This is our end oa trimester group project, and we will be working in pairs. Our team consists of Anne-Cécile Besse (Arc) and Enes Gemici. 

To begin with, we decided to devide the work:

- Arc will: 
  - write the documentation (`REAMDE.md`)

- Enes will:
  - write do the Flowchart.
  - the MANPAGE redaction and implement

 - Teamwork:

Note : This `README.md` will be updated several times as the project progresses.

## Summary

- [Project `Simple Shell`](#project-simple-shell)
	- [Summary](#summary)
	- [Introduction](#introduction)
		- [Mandatory tasks](#mandatory-tasks)
		- [Placeholder for potential advanced tasks](#placeholder-for-potential-advanced-tasks)
	- [Requierements](#requierements)
		- [Operating System:](#operating-system)
		- [Compilation flags](#compilation-flags)
		- [General requirements and restrictions for the projects](#general-requirements-and-restrictions-for-the-projects)
		- [Allowed Functions and system calls+](#allowed-functions-and-system-calls)
	- [Glossary (in alphabetical order)](#glossary-in-alphabetical-order)
	- [What is a Unix Shell?](#what-is-a-unix-shell)
		- [Types of Shells](#types-of-shells)
		- [Shell configuration](#shell-configuration)
		- [System Calls](#system-calls)
		- [Interactive and Non-Interactive Modes](#interactive-and-non-interactive-modes)
	- [Manpage `Simple Shell`](#manpage-simple-shell)
		- [How we tested our project.](#how-we-tested-our-project)
		- [Some tests to try:](#some-tests-to-try)
	- [Flowchart](#flowchart)
	- [Conclusion](#conclusion)
	- [Author](#author)

## Introduction

In this project, we will develop a fundamental Unix command-line interpreter, resembling a traditional  Unix shell, but simpler (which give the name "Simple Shell").

### Mandatory tasks

Our objectives for the mandatory taks are:

1. **Code Quality:** Adhere to Betty Coding style guidelines to ensure cleanr, readable code.

2. **Basi Shell Implementaion:**  Create a simple shell that:
	- Displays a prompt and processes single-word commands.
	- Handles errors, including unrecognized commands and **end-of-file** confitions (Ctrl+D).
	- Repeats the prompt after each command execution (going back to the line to allow the user to type again.)

3. **More Functionalities:** Extene the shell to handle commands with arguments and manage executable paths correctly 

4. **Built-in Commands:** Implement basi built-in commands, including `exit` to terminate the shell and `env` to display environment variables.

### Placeholder for potential advanced tasks

## Requierements

Before begining, ensure that you have the following requirements:

### Operating System:

  - Ubuntu 22.04 LTS (of compatible version)

- **Softwares**:

  - **Visual Studio Code:** Ensure you have the latest version installed (You can find it [here](https://code.visualstudio.com/))

  - **GCC (GNU Compiler Collection):** Requiered for compiling the project. You can install it on your **Visual Code** using this: 
  
```sh
sudo apt-get install gcc
```
  
  - **Betty Style:** A style guide for the C programming language used by the Holberton School and ensuring a well structured and readable code. Ensure you have the Betty linter installed:

```sh
git clone https://github.com/holbertonschool/Betty.git
cd Betty
./install.sh
```

  - **Valgrind:** A tool for memiiry debugging, memory leak detection, and profiling. Install it using:

```sh
sudo apt-get install valgrind
``` 

- **Version Control**

**Git:** Ensure you have Git installed for version control:

```sh
sudo apt-get install git
```

### Compilation flags

This project must be compiled with the following flags:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

- **`-Wall`:** Enables all standard compiler warnings.

- **`-Werror`:** Treats all warnings as errors, stopping compilation.

- **`-Wextra`:** Enables additional warnings not covered by **`-Wall`**.

- **`-pedantic`:** Enforces strict ISO C compliance.

- **`-std=gnu89`:** Uses the GNU89 standard for C, allowing GNU extensions to the ANSI C standard

- **`Wno-format`:** Disables format warnings.

### General requirements and restrictions for the projects

- Allowed editors: `vi`, `vim`, `emacs`
- All files shouls end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory (hello you are in there!)
- Code should use the `Betty` style. It will be checked using [Betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl)
- The simple Shell should **not** have any memory leaks.
- No more than 5 functions per file.
- All headers files shouls be include guarded
- System calls **only** when needed.
- Unless specified otherwise, the program **must have the exact same output** as `sh` (`/bin/sh`) as well as the exact same error output.
- Only difference is when printing an error. The name of the program must be equivalent to the `argv[0]` (See below)

*Example of error with `sh`:*

```bash
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

*Same error with our program `hsh`:*

```bash
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

### Allowed Functions and system calls+

all functions from `string.h` and the functions and system calls below:

  - `access` (man 2 access)
  - `chdir` (man 2 chdir)
  - `close` (man 2 close)
  - `closedir` (man 3 closedir)
  - `execve` (man 2 execve)
  - `exit` (man 3 exit)
  - `_exit` (man 2 _exit)
  - `fflush` (man 3 fflush)
  - `fork` (man 2 fork)
  - `free` (man 3 free)
  - `getcwd` (man 3 getcwd)
  - `getline` (man 3 getline)
  - `getpid` (man 2 getpid)
  - `isatty` (man 3 isatty)
  - `kill` (man 2 kill)
  - `malloc` (man 3 malloc)
  - `open` (man 2 open)
  - `opendir` (man 3 opendir)
  - `perror` (man 3 perror)
  - `printf` (man 3 printf)
  - `fprintf` (man 3 fprintf)
  - `vfprintf` (man 3 vfprintf)
  - `sprintf` (man 3 sprintf)
  - `putchar` (man 3 putchar)
  - `read` (man 2 read)
  - `readdir` (man 3 readdir)
  - `signal` (man 2 signal)
  - `stat` (__xstat) (man 2 stat)
  - `lstat` (__lxstat) (man 2 lstat)
  - `fstat` (__fxstat) (man 2 fstat)
  - `strtok` (man 3 strtok)
  - `wait` (man 2 wait)
  - `waitpid` (man 2 waitpid)
  - `wait3` (man 2 wait3)
  - `wait4` (man 2 wait4)
  - `write` (man 2 write)

## Glossary (in alphabetical order)

**B**

  - **Bourne Shell (sh):** A Unix shell developed by Stephen Bourne, introduced in 1979 with UNIX Version 7. It introduced more advanced features such as here documents and command substitution.

  - **Bourne-Again Shell (bash):** An enhanced version of the Bourne Shell developed as part of the GNU Project. It is the default interactive shell for most Linux systems.

**C**

  - **`chdir()`:** A system call that changes the current working directory of a process.

  - **C Shell (`csh`):** A Unix shell modeled after the C programming language, developed by Bill Joy. It introduced features like command history, aliases, and job control.

  - **Configuration File:** A file used to set up and customize the behavior of a shell. It typically includes commands to initialize environment variables and shell settings.

**D**

  - **Debian Almquist Shell (`dash`):** A modern replacement for `ash` used in Debian and Ubuntu, known for its efficiency and POSIX compliance.

**F**

  - **`fork()`:** A system call that creates a new process by duplicating the calling process. It is used to launch new commands in a shell.

**G**

  - **Globbing:** A shell feature that allows users to specify filenames using wildcard characters (e.g., `*`, `?`) for pattern matching.

**I**

  - **Input/Output Redirection:** A shell feature that allows users to direct the input or output of a command to/from files or other commands.
  - **Interactive Mode:** A mode in wich the shell waits for user input, processes commands as they are entered, and provides immediate feedback. Features command history, autocompletion, and a prompt.
  - **Non-Interactive Mode:** A mode in which the shell executes commands from a script or a file without user interaction. Useful for automation and batch processing

**K**

  - **KornShell (`ksh`):** A Unix shell written by David Korn, based on the Bourne Shell. It includes advanced features like associative arrays and string manipulation.

  - **MirBSD Korn Shell (`mksh`):** A descendant of the OpenBSD Korn Shell and public domain Korn Shell, developed as part of MirOS BSD.

**M**

  - **Modern Shells:** Refers to contemporary Unix shells such as Bourne-Again Shell (`bash`), Z Shell (`zsh`), and others that have evolved from earlier shells.

**P**

  - **`pipe()`:** A system call that creates a communication channel between processes, enabling the output of one process to be used as input for another.

  - **`pipe` (in shell):** A mechanism to pass the output of one command as the input to another command using the `|` symbol.

**S**

  - **Shell:** A command-line interpreter that provides a user interface for interacting with Unix-like operating systems. It serves as both an interactive command language and a scripting language.

  - **System Call:** A function provided by the operating system kernel that allows programs to request low-level services or interact directly with hardware. Key system calls include `fork()`, `exec()`, `wait()`, `pipe()`, `chdir()`, `open()`, `read()`, `write()`, and `close()`.

**T**

  - **Thompson Shell (`sh`):** The first Unix shell, introduced in 1971 by Ken Thompson. It was minimalistic, supporting basic input/output redirection and pipes.

**Z**

  - **Z Shell (`zsh`):** A modern shell with extensive features, backward compatible with bash, and the default shell in some distributions like Kali Linux and macOS.

 

## What is a Unix Shell?

**Definition:**

A Unix Shell is a command-line interpreter that provides a command-line user interface for Unix-like operating systems. It serves as both an interactive command language and a scripting language, allowing users to control system operations through shell scripts.

**Basic Concepts**

  - **Interaction:** User typically interact with a Unix shell via a terminal emulator, but direct connections via hardware or **Secure Shell (SSH)** are common for server systems.

  - **Features:** All Unix shells provide filename wildcarding, piping, here documents, command substitution, variables, and control structures for condition-testing and iteration. 

### Types of Shells

1. **Thompson Shell (`sh`)**

	- **Author:** Ken Thompson
	- **First version:** November 1971
	- **Innovations:** Introduced `input/output` redirection and pipes to connect the `output` of one command to the `input` of another.
	- **Design:** Minimalistic, lacking support for comments or environment variables. Commands `if` and `goto` are separate, and pipre and redirection handling were refined in later versions.


2. **Bourne Shell (`sh`)**

	- **Author:** Stephen Bourne
	- **First version:** 1979 with Unix Version 7
	- **Innovations:** Added features like `here documents`, `command substitution`, and more extensive control structures.
	- **Modern Variants:**
    	- **Almiquist Shell (`ash`):** Use in resource-constrained environments.
    	- **Busybox:** Includes `ash` and `hush` for small and embedded systems.
    	- **Debian Almquist Shell (`dash`):** A modern replacement for `ash` in Debian and Ubuntu.
    	- **Bourne-Again Shell (`bash`):** Provides a superset of Bourne Shell functionalities and is the default shell for most Linux systems.
    	- **KornShell (`ksh`), MirBSD Korn Shell (`mksh`), Z shell (`zsh`):** Each offers extensions and improvements over the Bourne Shell.


3. **C Shell (csh)**

	- **Author:** Bill Joy
	- **First Version:** Developed at the University of California, Berkely, and widely distributed with BSD Unix.
	- **Innovations:** Introduced features for interactive work such as command history, aliases, directory stacks, and job control. Evolved into TENEX C Shell (`tcsh`) with enhancements.

### Shell configuration

Shells read configuration files to customize their behavior. Here is an overview of configuration files for popular shells:

| **Configuration File** | **sh**  | **ksh** | **csh** | **tcsh** | **bash** | **zsh** |
|------------------------|---------|---------|---------|----------|----------|---------|
| `/etc/profile`         | yes     | yes     | yes     | yes      | yes      | yes 	   |
| `~/.profile`           | yes     | yes     | yes     | yes      | yes      | yes 	   |
| `~/.bash_profile`      |         |         |         |          | yes      |     	   |
| `~/.bashrc`            |         |         |         |          | yes      |     	   |
| `~/.zshrc`             |         |         |         |          |          | yes 	   |


### System Calls

**Definition:**

**System calls** are functions provided by the operating system kernel that allow programs to interact directly with hardware or request low-level services. Here is an overview of key sustems calls and their usage in Unix shells.

**Key System Calls**

   - **`fork()`:** Creates a new process by duplicating the calling process. Used to launch commands in a shell.
   - **`exec()`:** Replaces the current process image with a new process image. Used to execute commands in a shell.
   - **`wait()`:** Waits for child processes to terminate. Used to synchronize process execution.
   - **`pipe()`:** Creates a communication channel between processes, allowing redirection of one process's output to another's input.
   - **`chdir()`:** Changes the current working directory of the process.
   - **`open()`, `read()`, `write()`, `close()`:** Basic file operations.
  
**Why Avoid Direct System Calls?**

- **Complexity:** Direct use of system calls can make code more complexe and harder to maintain.
- **Portability:** System calls can vary between operating systems. Scripts using these calls directly may not be portable across different Unix versions or distributions.
- **Security:** Errors in using system calls can introduce security vulnerabilities.
- **Abstraction:** Unix shells provide abstractions that simplify system interaction, such as rediction, pipes, and environment variables, Using these abstractions is often safer and easier than direct system call usage.

### Interactive and Non-Interactive Modes

**Interactive Mode:**

  - **Definition:**
	
	In **interactive mode**, the shell waits for user input, processes commands as they are entered, and provides immediate feedback.

  - **Features:**

    - **Command History:** Users can navigate through previously executed commands.
    - **Autocompletion:** The shell can auto-complete file names and commands.
    - **Prompt:** The shell displays a prompt indicating that it is ready to accept commands.
  
  - **Use Case:** 
  
  This mode is commonly used in terminal sessions where users manually enter commands to interact with the system.  

**Non-Interactive Mode:**

  - **Definition:**

  In **non-interactive mode**, the shell executes commands from a script or a file without user interaction. It reads commands from a script or input file and processes them in sequence.

  - **Features:**
    
	- **Script Execution:** Useful for automating tasks such as system maintenance, software installation, and backups.
	- **No Prompt:** There is a no prompt for user input; commands are executed in the background.

  - **Use Case:**

  This mode is ideal for running automated scripts or batch processing tasks where user interaction is not required.  

**Conclusion**

Unix shells play a crucial role in interacting with Unix-like operating systems, offering robust features for users and system administrators. While underlying system calls are fundamental to shell operation, it is generally preferable to use the abstractions provided by the shells for routine tasks to simplify development, enhance portability, and ensure security.

## Manpage `Simple Shell`

A "Manpage" is short for "Manual Page". This is a command scripted to display the manual page of `Simple Shell`, explaining the command and how to use it, while being in bash. Xavier wrote one for us and here is how to install it on you local visual code.

**Step 1: Creating the Directory Structure**

First, it's requiered to create the necessary directories if they don't already exist.

```sh
sudo mkdir -p /usr/local/man/man3
```

**Step 2: Install the manpage**

After creating the directory structure, installing the manpage with `sudo`to ensure to have the necessary permissions:

```sh
sudo install -o root -m 0644 
```

Little breakdown about what this all about:

  - **`-o root`:** Specifies the owner of the file (root in this case).

  - **`-m 0644`:** Sets the permissions of the file (readable and writable by the owner, readable by others).

  - **`man_3_printf`:** The source file for the manpage.

  - **placeholder:** The destination path for the installed manpage.


**Step 3: Update the manpage database**

You already have a manpage database holding the man of other commands. You need to update it so that `man` can find the new manpage:

```sh
sudo mandb
```

**Step 4: Try it**

```sh
man placeholder
```

### How we tested our project.

In this section, we are going to focus on the construction of the script itself and especially how we tested it, more than explaining how it works (it has already been explained in previous section).

So, to provide a safe environnement to test our functions without messing everything up, we created both of us a separate branch.

We adjusted or implemented the changes what we wanted to try, then compiled everything together like this:

```sh
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format placeholder
```

to test if it works.



**Testing with Valgrind:**

To ensure there are no memory leaks or other issues, we used Valgrind for testing at each step. Here’s a brief example command to check for memory-related problems:

```sh
valgrind --leak-check=full ./placeholder
```

*Valgrind Output*
```
==11799== 
==11799== HEAP SUMMARY:
==11799==     in use at exit: 0 bytes in 0 blocks
==11799==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==11799== 
==11799== All heap blocks were freed -- no leaks are possible
==11799== 
==11799== For lists of detected and suppressed errors, rerun with: -s
==11799== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

This allowed us to verify if our function operated correctly and efficiently, ensuring reliable performance in various scenarios.

### Some tests to try:

Here are some simple test to try:

## Flowchart


## Conclusion



## Author

Anne-Cécile Besse (Arc)
Enes Gemici