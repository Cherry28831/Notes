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
