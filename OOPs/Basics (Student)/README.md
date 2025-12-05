# C++ OOP Basics - Student Class Examples

## 📚 Overview
This folder demonstrates fundamental Object-Oriented Programming concepts in C++ using a **Student** class. The examples progress from basic public access to advanced encapsulation with validation.

## 📁 Files in This Folder

### `Student_Public.cpp`
**Basic class structure with public members**

#### Key Concepts:
- Class definition and object creation
- Public access modifier
- Direct member access

#### Code Structure:
```cpp
class Student {
public:
    string name;
    int age, roll;
    string grade;
};
```

#### What it demonstrates:
- Simple class with public data members
- Direct assignment and access to member variables
- Basic object instantiation

---

### `Student_GetSet.cpp`
**Encapsulation with getter/setter methods**

#### Key Concepts:
- Private data members
- Getter and setter functions
- Data validation and security

#### Code Structure:
```cpp
class Student {
private:
    string name;
    int age, roll;
    string grade;
    
public:
    void setName(string n);    // Setter with validation
    string getGrade(int pin);  // Getter with PIN protection
};
```

#### What it demonstrates:
- **Data Hiding**: Private members cannot be accessed directly
- **Input Validation**: `setName()` checks for empty strings
- **Controlled Access**: `getGrade()` requires PIN (123) for access
- **Error Handling**: Returns appropriate messages for invalid inputs

---

## 🎯 Learning Progression

### 1. **Public Access** (`Student_Public.cpp`)
- Learn basic class syntax
- Understand object creation
- See direct member access

### 2. **Encapsulation** (`Student_GetSet.cpp`)
- Understand data hiding principles
- Learn getter/setter pattern
- Implement validation logic

---

## 💡 Key Concepts Explained

### **Class vs Object**
- **Class**: Blueprint/template (like a house plan)
- **Object**: Instance of class (like an actual house)

### **Access Modifiers**
- **Public**: Accessible from anywhere
- **Private**: Only accessible within the class
- **Protected**: Accessible within class and derived classes

### **Why Use Getters/Setters?**
1. **Validation**: Check data before setting (empty name check)
2. **Security**: Control access with authentication (PIN protection)
3. **Flexibility**: Add logic without breaking existing code
4. **Debugging**: Track data changes

---

## 🚀 How to Run

```bash
# Compile
g++ Student_Public.cpp -o student_public
g++ Student_GetSet.cpp -o student_getset

# Execute
./student_public
./student_getset
```

---

## 📝 Important Notes

### From `Student_GetSet.cpp`:
- **Validation Example**: Empty name input shows "Invalid Name"
- **Security Feature**: Grade access requires PIN (123)
- **Encapsulation Benefit**: Cannot directly access private members
- **Real-world Application**: Similar to banking systems with account protection

### Best Practices Demonstrated:
- ✅ Keep sensitive data private
- ✅ Validate all inputs
- ✅ Provide controlled access methods
- ✅ Handle invalid cases gracefully
- ✅ Use meaningful function names