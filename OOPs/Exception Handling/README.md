# C++ Exception Handling - Error Management

## 📚 Overview
This folder demonstrates exception handling in C++ - a mechanism to handle runtime errors gracefully so that normal program flow can be maintained instead of crashing.

## 📁 Files in This Folder

### `Exception_Handling.cpp`
**Complete exception handling demonstration with banking example**

#### Core Concepts:

**Exception Handling Keywords**
- **try**: Block of code that may throw an exception
- **catch**: Block that handles specific exceptions from try block
- **throw**: Keyword used to manually throw/raise an exception

**Basic Syntax**
```cpp
try {
    if (error_condition)
        throw "Error message";
    // Normal code execution
} 
catch (const char* e) {
    cout << "Exception: " << e << endl;
}
```

**Exception Flow**
1. Code executes normally in try block
2. When exception occurs, throw statement terminates current function
3. Program searches for matching catch block
4. Control transfers to appropriate catch block
5. Remaining code in try block is skipped
6. Program continues after catch block

**C++ Exception Hierarchy**
- **std::exception** (base class)
  - **std::bad_alloc** - Memory allocation failures
  - **std::runtime_error** - External factors (file not found, network errors)
  - **std::logic_error** - Programming mistakes (invalid arguments)

**Exception Types Demonstrated**
- **String Literals**: Simple error messages like `throw "Invalid amount"`
- **Standard Classes**: Using `runtime_error("message")` for structured errors
- **Custom Classes**: `InvalidAmountError` class for domain-specific errors
- **System Exceptions**: `bad_alloc` for memory allocation failures

**Banking Example with Exception Handling**
```cpp
class Customer {
    int balance;
public:
    void deposit(int amount) {
        if (amount <= 0)
            throw "Amount should be greater than 0";
        balance += amount;
    }
    
    void withdraw(int amount) {
        if (amount <= 0)
            throw "Invalid amount";
        if (amount > balance)
            throw "Insufficient balance";
        balance -= amount;
    }
};

// Usage:
try {
    customer.deposit(100);   // Success
    customer.withdraw(6000); // Throws exception
    customer.deposit(50);    // This won't execute
}
catch (const char* e) {
    cout << "Error: " << e << endl;
}
```

**Multiple Catch Blocks**
Catch blocks are processed in order - first match wins:
```cpp
try {
    // Code that might throw different exceptions
}
catch (const char* e) {                    // String exceptions
    cout << "String Error: " << e << endl;
}
catch (const runtime_error& e) {           // Runtime error objects
    cout << "Runtime Error: " << e.what() << endl;
}
catch (...) {                              // Catch-all
    cout << "Unknown exception occurred" << endl;
}
```

**Real-world Applications**
- **Banking Operations**: Validating deposits and withdrawals
- **Memory Management**: Handling allocation failures gracefully
- **File Operations**: Managing file access errors
- **Mathematical Operations**: Preventing division by zero
- **Network Operations**: Handling connection failures

**Why Exception Handling?**

**Problems without Exception Handling:**
- Program crashes on errors
- Difficult to identify error location in large programs
- No graceful recovery from errors
- Poor user experience

**Benefits with Exception Handling:**
- Program continues running after handling errors
- Specific error messages for different problems
- Clean separation of error handling from normal logic
- Better debugging and maintenance
- Improved user experience

**Exception vs Traditional Error Checking**
Traditional approach uses return codes and if-statements for every operation. Exception handling separates error handling from normal program flow, making code cleaner and more maintainable.

**Best Practices Demonstrated**
- **Exception-first Validation**: Check for errors before normal processing
- **Specific Exception Types**: Use appropriate exception classes for different errors
- **Multiple Catch Blocks**: Handle different error types with specific responses
- **Custom Exception Classes**: Create domain-specific error types for better organization
- **Resource Management**: Ensure proper cleanup even when exceptions occur
- **Clear Error Messages**: Provide meaningful information about what went wrong

**Key Takeaways**
Exception handling is essential for robust C++ applications. It provides a structured way to handle errors, improves code maintainability, and enhances user experience by preventing crashes and providing meaningful error messages.

---