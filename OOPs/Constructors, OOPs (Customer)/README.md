# C++ Constructors and Destructors - Customer Class

## 📚 Overview
This folder demonstrates constructors and destructors in C++ using a **Customer** class from a banking system example.

## 📁 Files in This Folder

### `Customer.cpp`
**Constructor types and usage**

#### Core Concepts:

**Constructor**
- **Definition**: Special function invoked automatically when an object is created
- **Name**: Same as the class name
- **Return Type**: No return type, not even void
- **Purpose**: Initialize (default) the data members of the class

**Default Constructor**
- **Syntax**: `Customer() { }`
- **Purpose**: Initializes data members with default values
- **Example**: Sets name to "Unknown", account_number to 0, balance to 0
- **Invocation**: Called automatically when object is created without parameters (`Customer c1;`)

**Parameterized Constructor**
- **Syntax**: `Customer(string a, int b, int c) { }`
- **Purpose**: Initializes data members with user-provided values
- **Invocation**: Called when object is created with parameters (`Customer c2("Alice", 123456, 5000);`)

**Inline Constructor**
- **Syntax**: `inline Customer(string a, int b, int c) : name(a), account_number(b), balance(c) { }`
- **Purpose**: Compact way to initialize members using initializer list
- **Note**: Two constructors can't have same number and type of parameters
- **Choice**: Use either inline or regular parameterized constructor, not both with same signature

**Constructor Overloading**
- **Definition**: Multiple constructors with different parameters in the same class
- **Same Name**: All constructors have the same name as the class
- **Different Parameters**: Distinguished by number and type of parameters

**this Pointer**
- **Purpose**: Refers to the current object's data members
- **Usage**: `this->name = name;` - distinguishes between parameter and data member
- **When Needed**: When parameter names are same as data member names
- **Example**:
  ```cpp
  Customer(string name, int account_number, int balance) {
      this->name = name;  // this->name refers to class member
  }
  ```

**Copy Constructor**
- **Syntax**: `Customer(Customer &B) { }`
- **Purpose**: Creates a new object as a copy of an existing object
- **Reference Variable**: Used to avoid infinite recursion
- **Usage**: `Customer c3(c2);` - copies c2 into c3
- **How it works**: Copies all data members from the passed object

**Destructor**
- **Definition**: Special function invoked automatically when object is destroyed or goes out of scope
- **Syntax**: `~ClassName() { }`
- **Name**: Same as class name with `~` prefix
- **Return Type**: No return type
- **Parameters**: No parameters allowed
- **Limit**: Only one destructor per class
- **Purpose**: Release resources allocated to the object (especially dynamic memory)
- **Automatic Call**: Called automatically, no need to call explicitly
- **Dynamic Memory**: Can delete only resources allocated dynamically using `new`

**Destructor Call Order (LIFO)**
- **Order**: Last In First Out - reverse order of object creation
- **Example**: If objects created as 1, 2, 3, destructors called as 3, 2, 1
- **Reason**: Last created object may be dependent on previous objects
- **Scope**: When function ends, last created object goes out of scope first

**Dynamic Object Deletion**
- **Creation**: `Customer2 *c6 = new Customer2("Charlie", 4000);`
- **Explicit Deletion**: `delete c6;` - explicitly calls destructor
- **Use Case**: Control when destructor is called for heap-allocated objects

**Real-world Example**
- **Banking System**: Customer class with name, account_number, and balance
- **Default Customer**: Created with unknown details
- **Registered Customer**: Created with specific account details
- **Customer2 Class**: Demonstrates destructor with dynamic memory (balance pointer)

---
