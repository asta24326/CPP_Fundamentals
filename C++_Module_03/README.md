# CPP03 Module - Inheritance

## Overview

CPP03 introduces **Object-Oriented Programming (OOP)** fundamentals through **class inheritance**. This module teaches how to create class hierarchies, understand different types of inheritance, and implement the Orthodox Canonical Form (OCF) for derived classes.

## Key Concepts

### 1. **Class Inheritance**
- Creating derived (child) classes from base (parent) classes
- Inheriting members and methods from parent
- Code reuse and hierarchical relationships

### 2. **Access Specifiers in Inheritance**

#### Public Inheritance (most common)
```cpp
class Dog : public Animal { };
```
- Public members → public
- Protected members → protected
- Private members → hidden

#### Protected Inheritance
```cpp
class Dog : protected Animal { };
```
- Public members → protected
- Protected members → protected
- Private members → hidden

#### Private Inheritance
```cpp
class Dog : private Animal { };
```
- All members → private (rarely used)

### 3. **Constructor Chaining**
- Derived constructor must call parent constructor via initializer list
- Default parent constructor called if not explicitly specified
- Order: Parent constructor first, then derived constructor

**Example:**
```cpp
Dog::Dog() : Animal() {  // Call parent constructor first
    type = "Dog";
}
```

### 4. **Copy Constructor in Inheritance**
- Must explicitly call parent copy constructor
- Without it: parent DEFAULT constructor called (data not copied)
- Use initializer list: `Dog::Dog(const Dog& other) : Animal(other)`

### 5. **Assignment Operator in Inheritance**
- Must call parent assignment operator
- Check `this != &other` for self-assignment
- Call parent operator: `Animal::operator=(other);`

### 6. **Destructor in Inheritance**
- Parent destructor called automatically after derived
- Order: Derived destructor → Parent destructor
- No need to explicitly call parent destructor

## Exercises

### Ex00: ClapTrap Base Class
- Implement basic class with OCF
- Member variables: name, hit points, energy, damage
- Methods: attack, takeDamage, beRepaired

### Ex01: ScavTrap Derived Class
- Inherit from ClapTrap
- Override constructor/destructor
- Special method: guardGate() (unique to ScavTrap)
- Different behavior for attack()

### Ex02: FragTrap Derived Class
- Second derived class from ClapTrap
- Implement OCF correctly
- Special method: highFivesGuys()
- Different attack behavior

### Ex03: DiamondProblem (Multiple Inheritance)
- Create class hierarchy with multiple inheritance paths
- Understand virtual inheritance if implemented
- Handle ambiguity in multiple inheritance

## Common Mistakes

❌ **Forgetting parent constructor call**
```cpp
Dog::Dog() {  // ❌ Parent default constructor called automatically
    type = "Dog";
}
```

✓ **Correct way**
```cpp
Dog::Dog() : Animal() {  // ✓ Explicitly call parent
    type = "Dog";
}
```

---

❌ **Not calling parent in copy constructor**
```cpp
Dog::Dog(const Dog& other) {
    // ❌ Animal members NOT copied!
}
```

✓ **Correct way**
```cpp
Dog::Dog(const Dog& other) : Animal(other) {
    // ✓ Animal members copied via parent copy constructor
}
```

---

❌ **Trying to access private parent members**
```cpp
class Dog : public Animal {
public:
    void info() {
        std::cout << hp << std::endl;  // ❌ If hp is private
    }
};
```

✓ **Use protected instead**
```cpp
class Animal {
protected:  // ✓ Accessible in derived classes
    int hp;
};
```

## Compilation

```bash
cd cpp03/ex00  # Navigate to exercise
make           # Compile
./clapTrap     # Run
make clean     # Clean object files
make fclean    # Remove executable
make re        # Clean and rebuild
```

## Testing

Each exercise includes main() with test cases showing:
- Constructor/destructor calls
- Method behavior
- Copy operations
- Inheritance hierarchy

## Learning Outcomes

After completing CPP03, you should understand:
- ✓ How inheritance creates class hierarchies
- ✓ Access specifiers (public/protected/private)
- ✓ How to properly implement OCF in derived classes
- ✓ Parent-child constructor relationships
- ✓ Method overriding and behavior changes
- ✓ When to use inheritance vs composition

## Links

- [42 School](https://42.fr/)
- [CPP Reference](https://cppreference.com/)
- Next: [CPP04 - Polymorphism](../cpp04/README.md)