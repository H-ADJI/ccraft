# Shell

Building a shell in C.

## Guide

### The Core Functionality

1.  **The Read-Eval-Print Loop (REPL):**
    - [x] Display a prompt like `chell> `.
    - [x] Read user input from standard input.
      - Using getline to read up to a newline character
      - Using getchar to read each character (more manual)
    - [x] Parse the input into a list of cmd - args
      - tokenize using white spaces
2.  **Command Execution:**
    - [x] Handle external commands calls
      - command execution using fork - execvp
      - wait for command termination using waitpid
    - [x] Handle built-in commands (to manage shell process state)
      - exit
      - cd

### Essential Shell Features

3.  **Comments**
    - [ ] Ignore comments
4.  **Built-in `cd` Command:**
    - Since calling external cd won't work
5.  **`PATH` Environment Variable:**
    - When full executable path is not specified walkthrough PATH directories to find it
6.  **Basic I/O Redirection (`<`, `>`):**
    - Implement standard input redirection (`< filename`) and standard output redirection (`> filename`).
7.  **Background Processes (`&`):**
    - Allow commands to run in the background (e.g., `sleep 5 &`).
8.  **Pipelines (`|`):**
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
6. **handle strings**
   - Handle string user input tokenization

## References

[code crafters github](https://github.com/codecrafters-io/build-your-own-x?tab=readme-ov-file#build-your-own-shell)
