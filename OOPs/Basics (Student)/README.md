# C++ OOP Basics - Student Class Examples

## 📚 Overview
This folder demonstrates fundamental Object-Oriented Programming concepts in C++ using a **Student** class. The examples progress from basic public access to advanced encapsulation with validation.

## 📁 Files in This Folder

### `Student_Public.cpp`
**Basic class structure with public members**

#### What it demonstrates:
- **Class**: User-defined data type that holds its own data members and member functions
- **Object**: Instance of a class (Student S1 is an object of class Student)
- **Public Access Modifier**: Members are accessible from outside the class
- **Direct Access**: Can directly assign and access member variables without restrictions
- **Default Access**: If access modifier is not mentioned, it is private by default

---

### `Student_GetSet.cpp`
**Encapsulation with getter/setter methods**

#### What it demonstrates:
- **Private Members**: Data members are private by default, cannot be accessed directly from outside
- **Setter Functions**: Used to set values of private members with validation (e.g., checking for empty names)
- **Getter Functions**: Used to retrieve values of private members
- **Validation**: Adding constraints like default values or range restrictions (demonstrated with name validation)
- **Security**: Setting constraints to access sensitive data (grade requires PIN 123)
- **Encapsulation Benefit**: Using getters/setters allows adding validation and constraints while accessing data, unlike public members where anyone can access without restrictions

---



