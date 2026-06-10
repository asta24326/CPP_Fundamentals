# C++ Module 01 — Memory allocation, pointers to members, references and switch statements

Part of the 42 C++ modules series. This module covers heap vs stack allocation, references, pointers to member functions, and switch statements — all written in C++98.

## Compilation

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Exercises

### ex00 — BraiiiiiiinnnzzzZ
Introduces the `Zombie` class with heap and stack allocation. Implements `newZombie()` (heap, returned to caller) and `randomChump()` (stack, local scope). The destructor prints a message to confirm proper cleanup.

### ex01 — Moar brainz!
Allocates an array of `N` zombies in a single `new[]` call via `zombieHorde()`. Explores array allocation and the importance of `delete[]` to avoid memory leaks.

### ex02 — HI THIS IS BRAIN
Demonstrates that pointers and references both hold memory addresses. A string, a pointer to it, and a reference to it all print the same address — demystifying C++ references.

### ex03 — Unnecessary violence
Implements `Weapon`, `HumanA`, and `HumanB` classes to explore when to use a reference vs a pointer to a member. `HumanA` always holds a weapon (reference); `HumanB` may not (pointer).

### ex04 — Sed is for losers
A command-line tool that takes a filename, a search string `s1`, and a replacement string `s2`, then writes a new `<filename>.replace` file with every occurrence of `s1` replaced by `s2`. Uses `std::fstream` — `std::string::replace` is forbidden.

### ex05 — Harl 2.0
A `Harl` class that dispatches to `debug()`, `info()`, `warning()`, or `error()` via an array of **pointers to member functions** — no if/else chains allowed.


## Key concepts

- Stack vs heap allocation (`new` / `delete` / `delete[]`)
- References vs pointers
- Pointers to member functions
- `std::fstream` for file I/O
- `switch` statements
- Include guards and header independence

## Rules

- Standard library allowed; C++11, Boost, `*printf`, `*alloc`, and `free` are **forbidden**
- `using namespace` and `friend` keywords are **forbidden**
- No STL containers or algorithms until Module 08/09
- No function implementations in header files (except templates)
- No memory leaks