# Shell

Building a shell in C.

## Guide

### The Core Functionality

1.  **The Read-Eval-Print Loop (REPL):**
    - Display a prompt like `chell> `.
    - Read user input from standard input.
    - Parse the input into cmd - args
    - Dummy command execution
    - Handle empty input and comments
2.  **Command Execution:**
    - Handle external commands calls
    - Handle built-in commands (like `exit`)

### Essential Shell Features

1.  **Parsing Arguments:**
    - Handle user input tokenization
2.  **Built-in `cd` Command:**
    - Since calling external cd won't work
3.  **`PATH` Environment Variable:**
    - When full executable path is not specified walkthrough PATH directories to find it
4.  **Basic I/O Redirection (`<`, `>`):**
    - Implement standard input redirection (`< filename`) and standard output redirection (`> filename`).
5.  **Background Processes (`&`):**
    - Allow commands to run in the background (e.g., `sleep 5 &`).
6.  **Pipelines (`|`):**
    - Implement command piping (e.g., `ls -l | grep .c`).

### Phase 3: Advanced Functionality and Robustness

1. **Signal Handling:**
   - Implement signal handler for `SIGINT`(Ctrl+C) and `SIGCHILD`
2. **More Built-in Commands:**
   - Implement `echo`, `env`, `setenv`, `unsetenv` (the latter two manage the shell's environment variables).
3. **More signals:**
   - Implement `SIGTSTP` (Ctrl+Z) to suspend foreground processes.
   - Manage a list of active jobs (processes, their states, and job IDs).
   - Implement `fg` (foreground) and `bg` (background) commands to move jobs between states.
4. **Command History:**
   - Store previously executed commands.
   - History navigation using arrows
5. **Error Handling:**
   - Improve error messages (`command not found`, `permission denied`, `syntax error`).
