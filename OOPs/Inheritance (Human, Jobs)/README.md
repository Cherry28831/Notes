# C++ Inheritance - Human and Jobs Classes

## 📚 Overview
This folder demonstrates inheritance concepts in C++ using **Human** and **Jobs** classes to show how properties and characteristics can be derived from parent classes.

## 📁 Files in This Folder

### `Customer_Inheritance.cpp`
**Inheritance concepts and implementation**

#### Inheritance Hierarchy:

```
                    ┌─────────────────┐
                    │     Human       │
                    │  (Base Class)   │
                    │                 │
                    │ - name: string  │
                    │ - age: int      │
                    │ - weight: int   │
                    └─────────┬───────┘
                              │
                              │ inherits
                              │
              ┌───────────────┼───────────────┐
              │               │               │
              ▼               ▼               ▼
    ┌─────────────────┐ ┌─────────────────┐ ┌─────────────────┐
    │    Student      │ │    Teacher      │ │   Other Jobs    │
    │ (Derived Class) │ │ (Derived Class) │ │ (Derived Class) │
    │                 │ │                 │ │                 │
    │ Inherited:      │ │ Inherited:      │ │ Inherited:      │
    │ - name: string  │ │ - name: string  │ │ - name: string  │
    │ - age: int      │ │ - age: int      │ │ - age: int      │
    │ - weight: int   │ │ - weight: int   │ │ - weight: int   │
    │                 │ │                 │ │                 │
    │ Additional:     │ │ Additional:     │ │ Additional:     │
    │ - fees: int     │ │ - salary: int   │ │ - specific      │
    │ - roll_no: int  │ │ - id: int       │ │   attributes    │
    └─────────────────┘ └─────────────────┘ └─────────────────┘
```

#### Core Concepts:

**Inheritance**
- **Definition**: The capability of a class to derive properties and characteristics from another class
- **Real-life Analogy**: Like inheriting features from parents to child (but not every feature)
- **Purpose**: Avoid code duplication and establish relationships between classes
- **Problem Solved**: Eliminates duplicate code in Student and Teacher classes

**Code Structure Example**
- **Human Class**: `string name`, `int age`, `int weight` (common properties)
- **Student Class**: Inherits Human properties + `int fees`, `int roll_no` (specific properties)
- **Teacher Class**: Inherits Human properties + `int salary`, `int id` (specific properties)
- **Benefit**: No need to rewrite `name`, `age`, `weight` in each class

**Access Specifiers in Inheritance**

| Access Specifier | External Code | Within Class | Derived Class |
|------------------|---------------|--------------|---------------|
| **Public**       | ✅ Yes        | ✅ Yes       | ✅ Yes        |
| **Protected**    | ❌ No         | ✅ Yes       | ✅ Yes        |
| **Private**      | ❌ No         | ✅ Yes       | ❌ No         |

**Inheritance Syntax**
- **Format**: `class ChildName : AccessModifier BaseClassName`
- **Example**: `class Student : public Human`
- **Purpose**: Access modifier sets visibility of base class members in derived class

**Inheritance Access Modifier Rules**
*Strength Order: Private > Protected > Public*

| Base Class Member | Derived Class Access | Result in Derived Class |
|-------------------|---------------------|-------------------------|
| **public**        | public              | public                  |
| **public**        | protected           | protected               |
| **public**        | private             | private                 |
| **protected**     | public              | protected               |
| **protected**     | protected           | protected               |
| **protected**     | private             | private                 |
| **private**       | any                 | not accessible          |

**Code Example - Human Class**
```cpp
class Human {
private:
    int a;  // Can't be accessed outside class or in derived class
    
protected:
    int b;  // Can be accessed inside class and in derived class
    void fun2() { /* protected function */ }
    
public:
    int c;  // Can be accessed from anywhere
    void fun3() { /* public function */ }
};
```

**Complete Class Examples**

**Human Class (Base)**
```cpp
class Human {
private:
    int religion, color;  // Personal details - kept private for security
    
protected:
    string name;
    int age, weight;     // Accessible in derived classes
    
public:
    int c;              // Accessible everywhere
};
```

**Student Class (Public Inheritance)**
```cpp
class Student : public Human {
    int rollno, fees;
    // Inherits: name, age, weight as protected
    // Inherits: c as public
};
```

**Teacher Class (Protected Inheritance)**
```cpp
class Teacher : protected Human {
private:
    int id, salary;
    
public:
    void fun(string n, int a, int w) {
        name = n;    // Can access protected members
        age = a;
        weight = w;
    }
    // All inherited members become protected
};
```

**Customer Class (Private Inheritance)**
```cpp
class Customer : private Human {
private:
    int id, amount;
    
public:
    Customer(int i, int amt, string n, int a, int w) {
        id = i; amount = amt;
        name = n; age = a; weight = w;  // Can access in constructor
    }
    // All inherited members become private
};
```

**Access Examples**
- `h1.a = 10;` ❌ Error - private member
- `h1.b = 20;` ❌ Error - protected member (not accessible externally)
- `h1.c = 30;` ✅ Works - public member
- `h1.fun3();` ✅ Works - public function
- `h1.fun2();` ❌ Error - protected function
- `s1.name = "Cherry";` ❌ Error - protected in Student class

**Why Different Access Levels?**
- **Private**: Hide sensitive data (religion, color) from outside world and derived classes
- **Protected**: Share common attributes (name, age, weight) with derived classes only
- **Public**: Provide interface functions accessible to everyone
- **Private Inheritance**: Used when you want to use base class functionality internally (Customer example)

**Types of Inheritance**
- **Single Inheritance**: One child class inherits from one parent class
- **Multiple Inheritance**: One child class inherits from multiple parent classes
- **Multilevel Inheritance**: Chain of inheritance (A → B → C)
- **Hierarchical Inheritance**: Multiple child classes inherit from one parent class (shown above)
- **Hybrid Inheritance**: Combination of multiple inheritance types

**Benefits of Inheritance**
- ✅ **Code Reusability**: Avoid writing duplicate code
- ✅ **Maintainability**: Changes in parent class automatically reflect in child classes
- ✅ **Extensibility**: Add new features to existing classes
- ✅ **Organization**: Model real-world hierarchical relationships
- ✅ **Memory Efficiency**: Shared properties stored once in base class

**Real-world Examples**
- **Human → Jobs**: Basic human properties inherited by specific job roles
- **Vehicle → Car/Bike**: Common vehicle features inherited by specific types
- **Animal → Dog/Cat**: Basic animal characteristics inherited by species
- **Employee → Manager/Developer**: Common employee attributes inherited by roles

---
