// Exception Handling: Mechanism to handle runtime errors gracefully
// Definition: An exception is an unexpected problem during program execution
// that causes the program to terminate suddenly with errors
// 
// Purpose: Handle runtime errors so normal program flow can be maintained
// Keywords: try, throw, catch

// Exception Handling Keywords:
// try:   Block of code that may throw an exception
// catch: Block that handles specific exceptions thrown from try block
//        Multiple catch blocks can be written for different exception types
// throw: Keyword used to throw/raise an exception manually

// Why Exception Handling?
// Problem: Without exception handling, errors crash the program
// Example: int *p = new int[10000000000000000];  // Huge memory allocation
//          This causes bad_alloc exception and program crashes
// 
// In small programs (3 lines): Easy to find error
// In large programs (1000+ lines): Hard to identify where exception occurred
// Solution: Use try-catch to handle exceptions gracefully
// We can use the try keyword to do this
// try
// {
//     int *p = new int[10000000000000000];
//     cout << "Memory allocation is successful\n";
//     delete[] p;
// }
// catch (const exception &e)
// { // We can just directly mention the reason for the exception along with the line number
//     cout << "Exception Occurred due to line 21" << endl;
// }
// Here, we didn't even call the throw function, but the system throws it on its own, and code catches

// C++ Exception Hierarchy:
// std::exception (base class) is inherited by:
// - std::bad_alloc (IMPORTANT) - Memory allocation failures
// - std::bad_cast - Invalid dynamic_cast operations
// - std::bad_typeid - Invalid typeid operations
// - std::logic_error - Logic errors (programming mistakes)
// - std::runtime_error (IMPORTANT) - Runtime errors (external factors)

#include <iostream>
#include <string>
#include <exception> // Using this, we don't need to create the exception class
using namespace std;

// This is how an exception class looks (we can directly call the library):-
// class exception
// {
// protected:
//     string msg;

// public:
//     exception(string msg)
//     {
//         this->msg = msg;
//     }
//     string what()
//     {
//         return msg;
//     }
// };
// We can directly use bad alloc instead of exception in catch
// catch(const bad_alloc &e){
//     cout << "Exception: " << e.what() << endl;
// }

// Below is the runtime_error class which inherits from the exception class
// Use const for the word to be not tampered with
// class runtime_error : public exception
// {
// public:
//     runtime_error(const String msg) : exception(msg);
// }

// Custom Exception Class:
// We can create domain-specific exception classes for better error identification
// Benefits: More specific error handling, better code organization
class InvalidAmountError : public runtime_error
{
public:
    // Constructor calls parent runtime_error constructor with message
    InvalidAmountError(const string msg) : runtime_error(msg) {}
};

class Customer
{
    string name;
    int balance, account_number;

public:
    Customer(string name, int balance, int account_number)
    {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }
    void deposit(int amount)
    {
        // Exception-first approach: Check for invalid conditions first
        if (amount <= 0)
        {
            // Throw string literal exception
            throw "Amount should be greater than 0";
            
            // Alternative: Throw runtime_error object (more structured)
            // throw runtime_error("Amount should be greater than 0");
            
            // Alternative: Throw custom exception
            // throw InvalidAmountError("Amount should be greater than 0");
        }
        
        // Normal execution: Only runs if no exception is thrown
        balance += amount;
        cout << amount << " deposited successfully" << endl;
    }
    void withdraw(int amount)
    {
        // Multiple exception conditions
        if (amount <= 0)
        {
            throw "Invalid amount";  // Negative or zero amount
        }
        else if (amount > balance)
        {
            throw "Insufficient balance";  // Amount exceeds available balance
        }
        
        // Normal execution: Only runs if all validations pass
        balance -= amount;
        cout << amount << " withdrawn successfully" << endl;
    }
};

int main()
{
    Customer c1("Rahul", 1000, 1234567890);
    // c1.deposit(500);
    // c1.withdraw(200);
    // c1.withdraw(2000); Causes error
    // Exception Handling Demo
    try
    {
        c1.deposit(100);   // This will execute successfully
        c1.withdraw(6000); // This throws exception, jumps to catch block
        c1.deposit(100);   // This line will NOT execute (unreachable after exception)
    }
    // Exception Flow:
    // 1. When throw is encountered, current function terminates immediately
    // 2. Program searches for matching catch block
    // 3. Control transfers to appropriate catch block
    // 4. Remaining code in try block is skipped
    // Multiple Catch Blocks (handled in order of appearance)
    catch (const char *e)  // Catches string literal exceptions
    {
        cout << "String Exception: " << e << endl;
    }
    catch (const runtime_error &e)  // Catches runtime_error and derived classes
    {
        cout << "Runtime Error: " << e.what() << endl;
    }
    catch (const bad_alloc &e)  // Catches memory allocation errors
    {
        cout << "Memory Error: " << e.what() << endl;
    }
    catch (...)  // Default catch-all block (catches any unhandled exception)
    {
        cout << "Unknown exception occurred" << endl;
    }
    // Note: Only the FIRST matching catch block executes

    // Division by Zero Example
    cout << "\nEnter two numbers for division: ";
    int a, b;
    cin >> a >> b;
    
    try
    {
        // Check for division by zero before performing operation
        if (b == 0)
        {
            throw "Division by zero is not allowed";  // String exception
            // Alternative: throw 404;  // Integer exception
            // Alternative: throw runtime_error("Division by zero");
        }
        
        int result = a / b;
        cout << "Result: " << result << endl;
    }
    catch (const char *e)
    {
        cout << "Math Error: " << e << endl;
    }
    // Test Cases:
    // Input: 10, 2  -> Output: Result: 5
    // Input: 10, 0  -> Output: Math Error: Division by zero is not allowed
}