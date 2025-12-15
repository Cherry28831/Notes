# C++ Polymorphism - Multiple Forms

## 📚 Overview

This folder demonstrates polymorphism concepts in C++ - the ability for objects of different types to be treated as objects of a common base type while maintaining their specific behaviors.

## 📁 Files in This Folder

### `Polymorphism.cpp`

**Complete polymorphism demonstration with examples**

#### Polymorphism Types Chart:

```
                                       POLYMORPHISM
                                   /                 \
                        COMPILE-TIME                  RUNTIME
                       (Static/Early)               (Dynamic/Late)
                             |                            |
                      +------+------+              +------+------+
                      |             |              |             |
                FUNCTION       OPERATOR         FUNCTION       OBJECT
               OVERLOADING    OVERLOADING      OVERRIDING   POLYMORPHISM
                      |             |              |             |
              - Same name    - Same op         - Virtual     - Base ptr
              - Diff args    - Diff              functions   - Derived
              - Resolved       behavior        - Same          objects
                at compile   - Custom            signature   - Runtime
                               types           - Different     binding
                                                 impl        - v-table
```

#### Core Concepts:

**Compile-time Polymorphism**

- **Function Overloading**: Same function name, different parameters
- **Operator Overloading**: Custom behavior for operators on user-defined types
- **Resolution**: Compiler decides which function/operator to call
- **Performance**: No runtime overhead, faster execution

**Runtime Polymorphism**

- **Virtual Functions**: Base pointer calling derived class methods
- **Dynamic Binding**: Method determined at runtime using v-table
- **Object Polymorphism**: Same interface, different behavior based on actual object

**Examples Covered**

- **Area Class**: Function overloading for circle vs rectangle area calculation
- **Complex Class**: Operator overloading for + operator on complex numbers
- **Animal Hierarchy**: Virtual functions with Dog and Cat derived classes

**Key Features**

- **Function Overloading**: calculateArea(int) vs calculateArea(int, int)
- **Operator Overloading**: Complex number addition using + operator
- **Virtual Functions**: Animal pointer calling Dog's or Cat's speak() method
- **Method Overriding**: Each animal type has its own speak() implementation
- **Polymorphic Arrays**: Vector of Animal pointers holding different derived objects

**Real-world Benefits**

- **Code Reusability**: Same interface for different implementations
- **Extensibility**: Add new derived classes without changing existing code
- **Maintainability**: Changes in base class affect all derived classes
- **Flexibility**: Handle different object types through common interface

---
