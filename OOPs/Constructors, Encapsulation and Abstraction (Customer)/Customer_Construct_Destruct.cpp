// Constructor is a special function that is invoked automatically
// when an object of a class is created.
// Name of the constructor is same as the class name.
// It does not have any return type, not even void.
// It is used to initialize (default) the data members of the class.

// Destructor is also a special function that is invoked automatically
// when an object of a class is destroyed or goes out of scope.
// Both constructor and destructor are public members of the class.
// No return type for destructor as well.
// No parameters are allowed for destructor.
// Only one destructor is allowed in a class.
// We use this to release the resources allocated to the object
// We need not call the destructor explicitly. It is called automatically.

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
    // inline Customer(string a, int b, int c) : name(a), account_number(b), balance(c)
    // {
    // }

    // Parameterized Constructor here will consider the new parameters instead of
    // data members of the class, mentioned above.
    // Thats why we use this -> (pointer) to refer to the data members of the class.
    // Customer(string name, int account_number, int balance)
    // {
    //     name = name;
    //     account_number = account_number;
    //     balance = balance;
    // }

    // Customer(string name, int account_number, int balance)
    // {
    //     this->name = name;
    //     this->account_number = account_number;
    //     this->balance = balance;
    // }

    // Copy Constructor: We use a reference variable to avoid infinite recursion
    // Reference variable is used to refer to the object passed as argument
    // It is a type of pointer that points to the original variable
    Customer(Customer &B)
    {
        name = B.name;
        account_number = B.account_number;
        balance = B.balance;
    }

    // Needs to be called in main function to display customer details
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Customer2
{
    string name;
    int *balance;

public:
    Customer2(string name, int bal)
    {
        this->name = name;
        balance = new int;
        *balance = bal;
        cout << "Constructor called" << endl;
    }
    // Destructor can delete only those resources which were allocated dynamically using 'new'
    ~Customer2()
    {
        delete balance;
        cout << "Destructor called" << endl;
    }
};

int main()
{
    cout << "Customer 1" << endl;
    Customer c1;  // Default Constructor called
    c1.display(); // Displaying details initialized by default constructor
    cout << "Customer 2" << endl;
    Customer c2("Alice", 123456, 5000); // Parameterized Constructor called
    c2.display();                       // Displaying details initialized by parameterized constructor
    cout << "Customer 3" << endl;
    Customer c3(c2); // Copy Constructor called
    c3.display();    // Copy Constructor called. Displaying details copied from c2
    cout << "Customer 4" << endl;
    Customer c4;
    c4 = c3;
    c4.display();
    cout << "Customer 5" << endl;
    Customer2 c5("Bob", 3000);
    Customer2 *c6 = new Customer2("Charlie", 4000);
    delete c6; // Explicitly calling destructor for dynamically allocated object
    // Destructor will automatically be called for object c5 when it goes out of scope
    // If constructor is called as 1, 2, 3..., then destructor is called as 3, 2, 1...
    // Example: If there are 3 objects created in main function, when main function ends,
    // first destructor called will be of 3rd object, then 2nd object and finally of 1st object.
    // This is because the last created object is the first to go out of scope.
    // This is known as LIFO (Last In First Out) order.
    // This happens due to dependency.
    // The last created object may be dependent on the previous objects.
}