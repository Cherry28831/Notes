# C++ Constructors and OOP Concepts - Customer Class

## 📚 Overview
This folder demonstrates constructors, destructors, and advanced OOP concepts in C++ using a **Customer** class from a banking system example.

## 📁 Files in This Folder

### `Customer_Construct_Destruct.cpp`
**Constructor types and destructor usage**

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

### `Customer_Static_Members.cpp`
**Static data members and functions**

#### Core Concepts:

**Static Data Member**
- **Definition**: Attributes that belong to the class itself, not to any specific object
- **Shared**: Only one copy created and shared among all objects of the class
- **Initialization**: Initialized only once at program start, before any object is created
- **Memory**: All objects point to the same memory location for static members
- **Examples**: `total_customer` (count), `total_balance` (sum of all balances)

**Static Member Declaration**
- **Inside Class**: `static int total_customer;` - declaration only
- **Outside Class**: `int Customer::total_customer = 0;` - initialization required
- **Scope Resolution**: `::` operator used to define static members outside class
- **Reason**: Static members are not tied to specific objects but belong to the class

**Static Member Functions**
- **Purpose**: Can access only static data members
- **Syntax**: `static void accessTotalBalance() { }`
- **Limitation**: Cannot access non-static data members
- **Access**: Can be called without creating any object (`Customer::accessTotalBalance()`)
- **Use Case**: Access private static members when needed

**Direct Access to Static Members**
- **Public Static**: `Customer::total_customer = 5;` - direct access without object
- **Private Static**: Use static member functions to access
- **Flexibility**: Can modify static data from anywhere in the program

**Banking Operations**
- **Deposit**: `deposit(amount)` - updates both individual and total balance
- **Withdraw**: `withdraw(amount)` - checks balance and updates both balances
- **Total Tracking**: `total_balance` keeps track of bank's total money
- **Real-time Updates**: Static variables update across all objects instantly

**Why Static Members?**
- ✅ Share common data across all objects
- ✅ Track class-level information (like total count/balance)
- ✅ Memory efficient - only one copy exists
- ✅ Accessible without creating objects
- ✅ Real-time synchronization across all instances

**Real-world Applications**
- **Banking**: Track total number of accounts
- **Gaming**: Track total players or score
- **Inventory**: Track total items in system

---

### `Customer_Encapsulation.cpp`
**Encapsulation and data hiding**

#### Core Concepts:

**Encapsulation**
- **Definition**: Bundling data and methods together while hiding internal implementation
- **Data Hiding**: Making data members private to prevent direct access
- **Controlled Access**: Using getter/setter methods to access private data
- **Security**: Protects data integrity and prevents unauthorized modifications

---

### `Customer_Abstraction.cpp`
**Abstraction concepts and data hiding**

#### Core Concepts:

**Abstraction**
- **Definition**: Displaying only essential information and hiding the details
- **Purpose**: User needs to know the interface, not the implementation
- **Data Storage**: No need to show how data is stored internally to the user
- **Function Usage**: User just needs to know how to use functions, not their internal workings

**Real-world Examples**
- **ATM Machine**: User deposits money without knowing GST is deducted internally
- **Instagram**: User posts pictures without knowing the internal algorithms
- **Math Functions**: `pow(2,3)` returns 8, user doesn't need to know the calculation method
- **Sort Function**: `sort(arr.begin(), arr.end())` works without user knowing the sorting algorithm
- **Banking**: `deposit(amount)` function hides balance storage and validation logic

**Code Example**
- **Hidden Details**: `name` and `balance` are private - user can't access directly
- **Public Interface**: `deposit(amount)` - user only needs to know this function exists
- **Internal Logic**: Amount validation (`if (amount > 0)`) is hidden from user
- **Usage**: `c1.deposit(2000)` - simple interface, complex logic hidden

**Benefits of Abstraction**
- ✅ **Simplicity**: User interacts with simple interface
- ✅ **Security**: Internal data and logic protected from unauthorized access
- ✅ **Maintainability**: Can change internal implementation without affecting user code
- ✅ **Efficiency**: Users focus on what they need, not how it works
- ✅ **Flexibility**: Only need to change the function implementation, not the declaration

**Implementation in C++**
- **Private Members**: Hide internal data (`name`, `balance`)
- **Public Methods**: Provide controlled access (`deposit()`)
- **Data Hiding**: User cannot directly modify balance
- **Interface Design**: Simple function calls hide complex operations

---
