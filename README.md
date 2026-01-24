# Crafting Software

## Projects

### Shell

- **Description** minimal POSIX shell commands interpreter.
- **Focus Areas:** Operating Systems (processes, system calls, I/O redirection, signals, environment variables).
- **Language:** `C`

### Grep

- **Focus Areas:** File I/O, String manipulation, Regular Expressions (basic).
- **Description:** Create a command-line utility that searches for lines matching a pattern in one or more files. Start with simple substring matching, then introduce basic regular expression-like features.
- **Language:** `C`

### Memory Allocator

- **Focus:** Operating Systems (memory management), Data Structures (linked lists, free lists).
- **Description:** Implement your own version of `malloc` and `free` using `sbrk` or `mmap`. Explore different strategies like first-fit, best-fit, or segregated lists.
- **Language:** `C`

### Curl

- **Focus:** Networking (TCP, HTTP), I/O.
- **Description:** Build a command-line tool that can make HTTP GET requests and display the response. Handle headers, status codes, and perhaps redirects.
- **Language:** `C`

### Event Loop / Async Runtime

- **Description:** Implement a single-threaded event loop (reactor) that monitors multiple I/O sources (e.g., network sockets, files) for readiness and dispatches user-defined callbacks or tasks when events occur. Optionally, build an "executor" on top to manage coroutines/futures, demonstrating cooperative multitasking.
- **Focus Areas:** Operating Systems (I/O multiplexing: `select`/`poll`/`epoll`/`kqueue`, file descriptors), Networking (non-blocking I/O), Concurrency (event-driven programming, cooperative multitasking), Language Design (understanding how `async/await` works under the hood).
- **Language:** `Python`

### HTTP Server

- **Focus Areas:** Networking (TCP/IP), Concurrency, I/O multiplexing, HTTP Protocol.
- **Description:** Build a simple web server that can serve static files (HTML, CSS, JS, images) from a specified directory.
- **Language:** `Golang`

### Redis

- **Focus Areas:** Data Structures, In-memory Storage, Networking, Persistence (optional), Concurrency.
- **Description:** Implement a basic in-memory key-value store that supports `SET` and `GET` commands over a custom TCP protocol.
- **Language:** `Golang`

### DNS Server

- **Focus Areas:** Networking (UDP), Caching, DNS Protocol, Recursion.
- **Description:** Build a DNS resolver that can query authoritative servers, cache results, and serve them to clients. Start with basic A records.
- **Language:** `Golang`

### Git

- **Focus Areas:** File Systems, Hashing, Data Structures (DAGs/Trees), Version Control Concepts.
- **Description:** Reimplement core Git functionalities: `init`, `add`, `commit`, `cat-file`. Focus on the `.git` directory structure: objects (blobs, trees, commits), refs.
- **Language:** `Rust`

### SQLite

- **Focus Areas:** Databases, Storage, File Systems, B-Trees, Parsing, Query Execution.
- **Description:** Create a basic relational database that stores data in a single file. Implement a simple SQL parser (`CREATE TABLE`, `INSERT`, `SELECT`), B-tree indexing for primary keys, and transaction support.
- **Language:** `Rust`

### Interpreter

- **Focus Areas:** Compilers & Language Design, Data Structures (Abstract Syntax Trees), Parsing.
- **Description:** Build an interpreter for a very simple language that can handle arithmetic expressions, variables, and perhaps basic control flow (if/else).
- **Language:** `Zig`

### Compiler

- **Focus Areas:** Compilers & Language Design, Code Generation, Target Architecture (basic).
- **Description:** Extend your interpreter project. Take your simple language and compile it down to a basic intermediate representation (like bytecode) or even simple assembly (e.g., x86-64).
- **Language:** `Zig`

### 4. Regular Expression Engine

- **Focus Areas:** Compilers & Language Design (lexing, parsing, automata theory), Algorithms (graph traversal, string matching), Data Structures.
- **Description:** Build a basic regular expression engine that can match simple patterns (e.g., `.` for any character, `*` for zero or more, `?` for zero or one, character sets like `[a-z]`) against a string. This typically involves converting a regex pattern into an NFA (Nondeterministic Finite Automaton) or DFA (Deterministic Finite Automaton) and then simulating it.
- **Language:** `Rust` or `Zig`

### Rate Limiter

- **Focus Areas:** Concurrency, Data Structures, Basic Algorithms.
- **Description:** Implement a server-side rate limiter. A common approach is the Token Bucket algorithm, where requests consume "tokens," and tokens are generated at a fixed rate.
- **Language:** `Golang`

### BitTorrent

- **Focus Areas:** P2P Networking, File Sharing, Hashing, Concurrency, Network Protocols.
- **Description:** Build a basic BitTorrent client that can download a single file from a `.torrent` file. This involves connecting to a tracker, finding peers, and exchanging pieces of the file.
- **Language:** `Golang`

### Load Balancer

- **Focus:** Networking, Concurrency, Distributed Systems.
- **Description:** Implement a simple reverse proxy that distributes incoming client requests across multiple backend servers using strategies like round-robin or least connections.
- **Language:** `Golang`

### Container Runtime

- **Focus Areas:** Operating Systems (Namespaces, Cgroups, Union Filesystems), Process Management, Virtualization.
- **Description:** Build a minimal container runtime. Focus on:
  - **Namespaces:** Isolate processes (PID, network, mount).
  - **Cgroups:** Limit resource usage (CPU, memory).
  - **Root filesystem:** Change the root directory of a process (`pivot_root` or `chroot`).
- **Language:** `Golang`

### Text Editor

- **Focus:** Operating Systems (file I/O, terminal control), Data Structures (gap buffers, ropes for efficient editing).
- **Description:** Implement a line-oriented or screen-oriented text editor. Start with opening/saving files, basic cursor movement, and character insertion/deletion.
- **Language:** `Rust`

### Kafka

- **Focus Areas:** Distributed Systems, Networking, Persistent Storage, Concurrency, Replication.
- **Description:** Implement a simplified version of Kafka's core: a distributed, persistent, append-only log. Focus on producers writing to topics/partitions and consumers reading from them.
- **Language:** `Rust`

### Blockchain

- **Focus:** Cryptography (hashing), Data Structures (linked lists), Distributed Systems (basic consensus).
- **Description:** Create a very basic blockchain where each block contains a timestamp, data, the hash of the previous block, and its own hash. Implement proof-of-work (nonce finding).
- **Language:** `Rust`
