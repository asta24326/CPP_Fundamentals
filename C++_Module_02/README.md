# 42 School: C++ — Module 02

This repository contains my solutions for **C++ Module 02** from the 42 Common Core curriculum. The entire project is written strictly in accordance with the **C++98 standard**.

## 🎯 Core Concepts of Module 02

The main objective of this module is to master **Ad-hoc polymorphism** (operator overloading), arithmetic conversions using bitwise operations, and the implementation of the **Orthodox Canonical Class Form**.

### 🌟 The Orthodox Canonical Class Form
From this module onwards, every single class must be structured to safely handle memory management, deep copies, and object lifecycles. Each class includes four mandatory components:
1. **Default Constructor** — initializes the object with default values.
2. **Copy Constructor** — creates a brand new instance as a deep copy of an existing object.
3. **Copy Assignment Operator (`=`)** — overloads the `=` operator to safely copy data between two already existing instances.
4. **Destructor** — cleans up resources when the object's lifecycle ends.

---

## 📂 Exercises Overview

### [ex00] My First Class in Orthodox Canonical Form
- **Concept:** Implementation of a basic `Fixed` class representing a fixed-point number.
- **Details:** Uses an integer to store the raw value and a static constant integer (`literal 8`) to represent the number of fractional bits. Focuses on tracking the exact execution order of constructors and destructors.

### [ex01] Towards a more useful fixed-point number class
- **Concept:** Bitwise arithmetic and floating-point conversion.
- **Details:** Adds new parameterized constructors that take constant integers and floats, converting them into the internal fixed-point representation using bit-shifting (`<<` and `>>`). Overloads the standard output insertion operator (`<<`) to allow seamless printing via `std::cout`.

### [ex02] Now we're talking
- **Concept:** Full operator overloading (Ad-hoc polymorphism).
- **Details:** Turns the `Fixed` class into a fully functional math asset by overloading:
  - **6 Comparison operators:** `>`, `<`, `>=`, `<=`, `==`, `!=`.
  - **4 Arithmetic operators:** `+`, `-`, `*`, `/`.
  - **4 Increment/Decrement operators:** Pre-increment, post-increment, pre-decrement, post-decrement (`++`, `--`).
  - **Static utility functions:** Overloaded `min` and `max` functions (working with both mutable and constant references).

### [ex03] BSP (Binary Space Partitioning) — *Optional / Bonus*
- **Concept:** Applied geometry using fixed-point math.
- **Details:** Implementation of a 2D geometric algorithm (`bsp`) that evaluates whether a `Point` lies strictly inside a triangle formed by three vertices (`Point const a, b, c`). Returns `false` if the point lies on the edges or vertices.

---

## 🚀 How to Build and Run

Every exercise features an independent `Makefile` containing the mandatory compilation flags (`-Wall -Wextra -Werror -std=c++98`).

### Compilation
Navigate into any exercise directory (e.g., `ex02/`) and run:
```bash
make

Execution
Run the compiled binary to execute the main test pipeline:

Bash
./fixed
Memory Safety Check
To guarantee that the overloaded operators do not cause any memory allocation mishaps or leaks:

On macOS:

Bash
leaks --atExit -- ./fixed
On Linux:

Bash
valgrind --leak-check=full ./fixed
Developed by asharafe