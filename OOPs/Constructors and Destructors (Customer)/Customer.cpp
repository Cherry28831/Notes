// Constructor is a special function that is invoked automatically
// when an object of a class is created.
// Name of the constructor is same as the class name.
// It does not have any return type, not even void.
// It is used to initialize (default) the data members of the class.

// Example: Banking System. Class: Customer

#include <iostream>
using namespace std;

class Customer
{
    string name;
    int account_number;
    int balance;

    // Constructor Overloading: Multiple constructors with different parameters
    // can be defined in the same class, with same name.
public:
    // Default Constructor
    Customer()
    {
        cout << "Constructor called!" << endl;
        // or, we can initialize data members here
        name = "Unknown";
        account_number = 0;
        balance = 0;
    }

    // Parameterized Constructor
    Customer(string a, int b, int c)
    {
        name = a;
        account_number = b;
        balance = c;
    }

    // Inline Constructor. 2 Constructors can't have same number of parameters
    // Either keep this or the above Parameterized Constructor
    inline Customer(string a, int b, int c) : name(a), account_number(b), balance(c)
    {
    }

    // Parameterized Constructor here will consider the new parameters instead of
    // data members of the class, mentioned above.
    // Thats why we use this -> (pointer) to refer to the data members of the class.
    // Customer(string name, int account_number, int balance)
    // {
    //     name = name;
    //     account_number = account_number;
    //     balance = balance;
    // }

    Customer(string name, int account_number, int balance)
    {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
    }

    // Needs to be called in main function to display customer details
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    Customer c1;                        // Default Constructor called
    c1.display();                       // Displaying details initialized by default constructor
    Customer c2("Alice", 123456, 5000); // Parameterized Constructor called
    c2.display();                       // Displaying details initialized by parameterized constructor
    return 0;
}