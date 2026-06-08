# C++ - Module 00: OOP Basics & C++98 Foundations

An introductory project designed to transition from procedural programming in C to **Object-Oriented Programming (OOP)** under the strict **C++98** standard. This module establishes core proficiency in classes, namespaces, member functions, and standard I/O streams[cite: 1].

---

## 🛠️ Core Concepts
* **OOP Fundamentals:** Class architecture, encapsulation, and visibility specifiers (`public`/`private`).
* **Standard Streams:** Swapping C I/O (`printf`) for C++ streams (`std::cin`, `std::cout`) and `<iomanip>`.
* **Resource Safety:** Manual memory tracking and implementing strict double-inclusion header guards.
* **Constraints:** No `using namespace`, no STL containers/algorithms, and zero usage of `malloc`/`free`.

---

## 📂 Project Structure

### [ex00] Megaphone
A warm-up application focusing on standard output streams and string modification, converting input arguments into uppercase.

### [ex01] My Awesome PhoneBook
A complete contact management system holding up to 8 entries with a circular overwrite behavior. Features clean column formatting via `<iomanip>` and handles input validation cleanly without dynamic allocation.

### [ex02] The Job Of Your Dreams *(Optional)*
A code reconstruction exercise practicing reverse-engineering. Rebuilds a missing account handling class using only a legacy header and matching dynamic execution logs.

---

## 🚀 Compilation & Usage
Compile any exercise directory using the provided `Makefile` configured with strict flags:
```bash
make -C ex01/ && ./ex01/phonebook
