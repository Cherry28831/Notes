# C++ OOP Basics - Student Class Examples

## 📚 Overview
This folder demonstrates fundamental Object-Oriented Programming concepts in C++ using a **Student** class. The examples progress from basic public access to advanced encapsulation with validation.

## 📁 Files in This Folder

### `Student_Public.cpp`
**Basic class structure with public members**

#### Core Concepts:

**Class & Object**
- **Class**: User-defined data type that holds its own data members and member functions
- **Object**: Instance of a class (Student S1 is an object of class Student)

**Memory Management**
- **Class Memory**: Class occupies no space in memory until an object is created
- **Empty Class Size**: 1 byte to give unique address to each object
- **Object Size**: Sum of size of all data members (with data padding)
  - `Student S1 = string(24) + int(4) + int(4) + string(24) = 56 bytes` (may vary by compiler)

**Data Padding**
- **Purpose**: Memory alignment to make size multiple of 4/8 bytes (32-bit or 64-bit system)
- **Why?**: For faster cycles and faster reading of data in memory chunks
- **Examples**:
  - `char(1) + int(4) = 8 bytes` (not 5)
  - `char + int + char = 12 bytes` (not 6 or 9)
- **Order Matters**: Order of data members affects final object size due to padding

**Access Modifiers**
- **Public**: Members are accessible from outside the class
- **Private**: Members are accessible only within the class
- **Protected**: Members are accessible within the class and by derived class
- **Default**: If not mentioned, it is private by default

**Real-world Examples**
- **Instagram User**: Class with private (password, email) and public (username, bio) members
- **Bank Customer**: Class with private (account number, balance, PIN) and public (name, branch) members

---

### `Student_GetSet.cpp`
**Encapsulation with getter/setter methods**

#### Core Concepts:

**Encapsulation**
- **Private Members**: Data members are private by default, cannot be accessed directly from outside
- **Controlled Access**: Use getter/setter functions to access and modify private members

**Setter Functions**
- **Purpose**: Set values of private members with validation
- **Example**: `setName()` checks for empty strings before setting the name
- **Benefits**: Add constraints like default values or range restrictions

**Getter Functions**
- **Purpose**: Retrieve values of private members
- **Security Example**: `getGrade(int pin)` requires PIN (123) to access grade
- **Flexibility**: Can add logic or constraints to data retrieval

**Why Use Getters/Setters?**
- ✅ Add validation and constraints while accessing/setting data
- ✅ Protect sensitive information with authentication
- ✅ Prevent direct access to private data
- ✅ Unlike public members where anyone can access without restrictions

**Dynamic Memory Allocation**
- **Pointer to Object**: `Student *S = new Student;` creates object in heap memory
- **Arrow Operator**: `S->setName("Apple")` - pointer access to member functions
- **Dereferencing**: `(*S).setAge(21)` - alternative way to access members via pointer

**Static vs Dynamic Memory Allocation**
- **Static**: Memory allocated at compile time (e.g., `Student S1;`)
- **Dynamic**: Memory allocated at runtime using `new` keyword (e.g., `Student *S = new Student;`)

**Stack vs Heap Memory**
- **Stack Memory**: Used for static allocation, faster access, limited size
- **Heap Memory**: Used for dynamic allocation, slower access, larger size
- **Allocation**: Use `new` keyword to allocate in heap (`int *ptr = new int;`)
- **Deallocation**: Use `delete` keyword to free heap memory (`delete ptr;`)

---
