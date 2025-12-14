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

### `Human_Multilevel_Inheritance.cpp`
**Chain of inheritance across multiple levels**

#### Core Concepts:

**Multilevel Inheritance**
- **Definition**: Chain of classes where each class inherits from the previous one
- **Structure**: Person → Employee → Manager (A → B → C)
- **Example**: Animal → Dog → German Shepherd

**Inheritance Chain**
- **Level 1**: Person (name, introduce())
- **Level 2**: Employee inherits Person + adds (salary, monthly_salary())
- **Level 3**: Manager inherits Employee + adds (dept, work())

**Access Accumulation**
- **Manager gets**: name + salary + dept + introduce() + monthly_salary() + work()
- **Each level**: Builds upon previous level's functionality
- **Protected members**: Accessible through inheritance chain

**Key Benefits**
- **Hierarchical structure**: Models real-world relationships
- **Cumulative functionality**: Each level adds to previous capabilities
- **Code organization**: Clear separation of concerns at each level

---

### `Human_Multiple_Inheritance.cpp`
**Inheriting from multiple base classes simultaneously**

#### Core Concepts:

**Multiple Inheritance**
- **Definition**: A class inherits from more than one base class
- **Structure**: `class Child : public Parent1, public Parent2`
- **Example**: CodeTeacher inherits from both Engineer and Youtuber

**Constructor Call Order**
- **Order**: Based on inheritance declaration sequence
- **Example**: `Engineer, Youtuber` → Engineer constructor first, then Youtuber
- **Destructor**: Called in reverse order of constructors

**Diamond Problem**
- **Issue**: When two base classes inherit from same grandparent
- **Result**: Child gets duplicate copies of grandparent members
- **Solution**: Virtual inheritance (`virtual public`)
- **Benefit**: Ensures single copy of grandparent class

**Access Rules**
- **Public members**: Accessible from both base classes
- **Private members**: Not accessible even through inheritance
- **Method calls**: Can use methods from all base classes

**Key Features**
- **Combined functionality**: Access methods from multiple sources
- **Complex relationships**: Models real-world multi-role scenarios
- **Careful design**: Requires attention to avoid ambiguity

---

### `Human_Hierarchical_Inheritance.cpp`
**One base class with multiple derived classes**

#### Core Concepts:

**Hierarchical Inheritance**
- **Definition**: One parent class with multiple child classes
- **Structure**: Human → Student, Teacher (1-Parent, M-Children)
- **Comparison**: Opposite of multiple inheritance (M-Parents, 1-Child)

**Class Structure**
- **Base Class**: Human (name, age, display())
- **Derived Class 1**: Student adds (rollNo, course)
- **Derived Class 2**: Teacher adds (salary)

**Method Overriding**
- **Base method**: Human's display() shows basic info
- **Student override**: Adds roll number and course details
- **Teacher override**: Adds salary information

**Constructor Patterns**
- **Student**: Uses initializer list `Human(n, a)`
- **Teacher**: Manually sets inherited properties
- **Best Practice**: Use initializer list for base class constructors

**Key Benefits**
- **Code reusability**: Common properties in base class
- **Consistent interface**: All derived classes share base functionality
- **Easy maintenance**: Base class changes affect all derived classes
- **Polymorphism support**: Can treat derived objects as base type

---
