# C++ Inheritance - Human and Jobs Classes

## 📚 Overview
This folder demonstrates inheritance concepts in C++ using **Human** and **Jobs** classes to show how properties and characteristics can be derived from parent classes.

## 📁 Files in This Folder

### `Human_Inheritance.cpp`
**Basic inheritance concepts and access modifiers**

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

**Class Examples**
- **Human Class**: Base class with private (religion, color), protected (name, age, weight), public (methods)
- **Student Class**: Public inheritance - inherits protected members as protected
- **Teacher Class**: Protected inheritance - all inherited members become protected
- **Customer Class**: Private inheritance - all inherited members become private

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

### `Human_Single_Inheritance.cpp`
**Single inheritance with constructors and destructors**

#### Core Concepts:

**Single Inheritance**
- **Definition**: When a derived class inherits from a single base class
- **Example**: Human (name, age) → Student (inherits Human + rollno, fees)
- **Linear Relationship**: Takes place one after another in a single line

**Constructor Call Order**
- **Parent First**: Human default constructor called first
- **Then Child**: Student constructor called after Human constructor
- **Reason**: Child constructor automatically calls parent constructor
- **Parameterized**: Use initializer list `Student(name, age, rollno, fees) : Human(name, age)`

**Destructor Call Order (LIFO)**
- **Child First**: Student destructor called first
- **Then Parent**: Human destructor called after Student destructor
- **Reverse Order**: Opposite of constructor call order

**Method Inheritance**
- **Inherited Methods**: `s1.work()` - Student can call Human's public methods
- **Method Overriding**: Student's `display()` overrides Human's `display()`
- **Access Rules**: Protected members (name, age) accessible in derived class but not externally

**Key Features**
- **Code Reusability**: Student inherits Human's properties and methods
- **Constructor Chaining**: Automatic parent constructor call
- **Method Access**: Public methods from parent available in child
- **Overriding**: Child class can override parent methods

---
