# CPP04 Module - Polymorphism & Abstract Classes

## Overview

CPP04 introduces **Polymorphism** and **Abstract Classes** - advanced OOP concepts that enable flexible, maintainable code. This module teaches how to create virtual methods, implement pure virtual functions, manage dynamic memory in class hierarchies, and understand deep copying for complex objects.

## Key Concepts

### 1. **Virtual Methods & Polymorphism**

#### Without Virtual (Compile-time Binding - WRONG)
```cpp
Animal* ptr = new Dog();
ptr->makeSound();  // ❌ Calls Animal::makeSound(), not Dog::makeSound()!
```

#### With Virtual (Runtime Binding - CORRECT)
```cpp
virtual void makeSound() const;  // In Animal.hpp

Dog* ptr = new Dog();
ptr->makeSound();  // ✓ Calls Dog::makeSound()
```

**How it works internally:**
- Each object with virtual methods has hidden **vptr** (virtual pointer)
- Points to class's **vtable** (virtual method table)
- At runtime, correct method address is looked up in vtable
- Enables polymorphic behavior

### 2. **Abstract Classes**

#### What is Abstract?
- Class with **at least ONE pure virtual method** (`= 0`)
- **Cannot instantiate** (create objects)
- Serves as **interface/blueprint** for derived classes
- Derived classes MUST override all pure virtual methods

#### Pure Virtual Method
```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // ← Pure virtual (= 0)
    // No implementation needed here
};

Animal animal;  // ❌ COMPILE ERROR! Cannot instantiate abstract class
Dog dog;        // ✓ OK (Dog implements makeSound())
```

#### Why Abstract?
- Prevents "incomplete" objects from being created
- Forces derived classes to implement required methods
- Creates clear contract/interface

**Example:**
```cpp
class Shape {
public:
    virtual void draw() = 0;        // Must implement
    virtual double getArea() = 0;   // Must implement
};

Shape shape;    // ❌ COMPILE ERROR
Circle circle;  // ✓ OK (if Circle implements draw() and getArea())
```

### 3. **Virtual Destructor - CRITICAL**

#### WITHOUT Virtual Destructor
```cpp
class Animal {
public:
    ~Animal() { }  // Not virtual!
};

class Dog : public Animal {
public:
    ~Dog() { delete brain; }  // Never called!
};

Animal* ptr = new Dog();
delete ptr;  // ❌ Only Animal destructor called → memory leak!
```

#### WITH Virtual Destructor
```cpp
class Animal {
public:
    virtual ~Animal() { }  // Virtual!
};

class Dog : public Animal {
public:
    ~Dog() { delete brain; }  // ✓ Called!
};

Animal* ptr = new Dog();
delete ptr;  // ✓ Both Dog and Animal destructors called
```

**Rule:** If ANY virtual method exists → destructor MUST be virtual!

### 4. **Deep Copy vs Shallow Copy**

#### Shallow Copy (WRONG)
```cpp
Dog dog1;
Dog dog2 = dog1;  // Without deep copy in copy constructor

// Both point to SAME Brain object!
dog1.brain → 0x1000
dog2.brain → 0x1000  // SAME!

delete dog1;  // Deletes brain at 0x1000
delete dog2;  // ❌ CRASH! Trying to delete already deleted object
```

#### Deep Copy (CORRECT)
```cpp
Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);  // ← Create NEW Brain, copy data
}

Dog dog1;
Dog dog2 = dog1;

dog1.brain → 0x1000
dog2.brain → 0x2000  // DIFFERENT!

delete dog1;  // Deletes brain at 0x1000 ✓
delete dog2;  // Deletes brain at 0x2000 ✓
```

### 5. **Access Specifiers & Encapsulation**

```cpp
class Brain {
private:
    std::string ideas[100];  // ← Private data
    
public:
    void setIdea(int idx, std::string idea) {
        ideas[idx] = idea;  // ✓ Can access own members
    }
    
    std::string getIdea(int idx) const {
        return ideas[idx];
    }
};

class Dog : public Animal {
private:
    Brain* brain;  // ← Private
    
public:
    Brain* getBrain() const {  // ← Public accessor
        return brain;
    }
};

// Usage:
Dog dog;
dog.getBrain()->setIdea(0, "Chase ball");  // ✓ Access through getters
```

## Access Syntax

| Type | Syntax | Example |
|------|--------|---------|
| Object (stack) | `.` (dot) | `dog.method()` |
| Pointer | `->` (arrow) | `ptr->method()` |
| Dereference | `(*ptr).method()` | Same as arrow |

```cpp
Dog dog;              // Object on stack
Dog* ptr = new Dog(); // Pointer to heap object

dog.method();         // ✓ Dot for object
ptr->method();        // ✓ Arrow for pointer
(*ptr).method();      // ✓ Also works (less common)
```

## Exercises

### Ex00: Polymorphic Hierarchy
- **Classes:** Animal (base), Dog (derived), Cat (derived)
- **Concepts:** Virtual methods, proper destructors
- **Comparison:** WrongAnimal/WrongCat (without virtual) vs correct version
- **Demonstrates:** Why virtual destructors are critical

### Ex01: Dynamic Memory & Deep Copy
- **New:** Brain class containing `std::string ideas[100]`
- **Task:** Dog and Cat have `private Brain*`
- **Key Test:** Verify deep copy (modifications to copy don't affect original)
- **Memory Test:** Run valgrind to ensure no leaks
- **Demonstrates:** Deep copy necessity for classes with pointers

### Ex02: Abstract Class
- **Goal:** Make Animal class abstract (cannot instantiate)
- **Method:** Add pure virtual method `= 0`
- **Result:** `Animal animal;` causes compile error
- **Benefit:** Forces Dog/Cat to implement required methods
- **Demonstrates:** Abstract classes as interfaces/blueprints

## Common Mistakes

❌ **Not making destructor virtual**
```cpp
class Animal {
public:
    ~Animal() { }  // ❌ Missing virtual!
};
```

✓ **Correct**
```cpp
class Animal {
public:
    virtual ~Animal() { }  // ✓ Virtual
};
```

---

❌ **Shallow copy in copy constructor**
```cpp
Dog::Dog(const Dog& other) {
    brain = other.brain;  // ❌ Both point to same object!
}
```

✓ **Deep copy**
```cpp
Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);  // ✓ New object, copied data
}
```

---

❌ **Using dot for pointer**
```cpp
Dog* ptr = new Dog();
ptr.method();  // ❌ COMPILE ERROR
```

✓ **Using arrow**
```cpp
Dog* ptr = new Dog();
ptr->method();  // ✓ Correct
```

---

❌ **Trying to instantiate abstract class**
```cpp
class Animal {
public:
    virtual void makeSound() = 0;
};

Animal animal;  // ❌ COMPILE ERROR: abstract class
```

✓ **Create through derived class**
```cpp
Dog dog;        // ✓ OK (Dog implements makeSound())
Animal* ptr = new Dog();  // ✓ OK (through pointer)
```

## Memory Management

### Stack vs Heap

```cpp
// Stack - automatic cleanup
{
    Dog dog;     // Created
}               // Automatically destroyed, destructor called

// Heap - manual cleanup required
{
    Dog* ptr = new Dog();     // Created
    delete ptr;               // Must manually delete
}                             // ptr variable destroyed, but memory leaked if delete forgotten
```

### Valgrind (Memory Leak Detection)

```bash
valgrind ./executable
# Output should show:
# All heap blocks were freed — no leaks are possible ✓
```

## Learning Outcomes

After completing CPP04, you should understand:
- ✓ Virtual methods and runtime polymorphism
- ✓ How vtables enable dynamic dispatch
- ✓ Abstract classes as interfaces
- ✓ Pure virtual methods (`= 0`)
- ✓ Virtual destructors importance
- ✓ Deep copy vs shallow copy
- ✓ When and how to use pointers in classes
- ✓ Memory safety with dynamic allocation
- ✓ Access specifiers for encapsulation

## Compilation

```bash
cd cpp04/ex00  # Navigate to exercise
make           # Compile with -std=c++98 -Wall -Wextra -Werror
./Animal       # Run
valgrind ./Animal  # Check for memory leaks
make clean     # Clean object files
make fclean    # Remove executable
make re        # Clean and rebuild
```

## Visual Diagram: Polymorphism

```
Animal* animals[3];
animals[0] = new Dog();    ┐
animals[1] = new Cat();    ├─→ Array of base class pointers
animals[2] = new Dog();    ┘

for each animal in array:
    animal->makeSound();   ← Virtual method call
    
At RUNTIME (polymorphism):
- animals[0]->makeSound() ─→ Dog::makeSound() (Woof!)
- animals[1]->makeSound() ─→ Cat::makeSound() (Meow!)
- animals[2]->makeSound() ─→ Dog::makeSound() (Woof!)

WITHOUT virtual:
- ALL would call Animal::makeSound() (wrong!)
```

## Links

- [C++ Virtual Functions](https://cppreference.com/w/cpp/language/virtual)
- [Pure Virtual Functions](https://cppreference.com/w/cpp/language/abstract_class)
- [42 School](https://42.fr/)
- Previous: [CPP03 - Inheritance](../cpp03/README.md)

## Notes

This module is challenging because it introduces concepts that are:
- **Abstract** - hard to visualize (vtables, virtual dispatch)
- **Critical** - virtual destructors prevent memory leaks
- **Practical** - used everywhere in real C++ code

Take time to understand the underlying mechanisms, not just the syntax!