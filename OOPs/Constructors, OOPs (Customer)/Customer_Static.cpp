// Static Data Member: They are attributes of classes or class members
// Only one copy of member created is are shared among all objects of the class.
// They are not tied to any specific object, but rather belong to the class itself.
// It is initialized only once, at the start of the program execution/before any object is created.

// We have Static Member Functions too, which can access only static data members
// If our static data member is in private, we can directly access it using this pointer.

// const keyword: Used to declare constants.
// A constant is a variable whose value cannot be changed once it has been assigned.
// It is a good practice to use const keyword wherever applicable to avoid accidental changes
// If we want to make sure that a member function does not modify any data members of the
// class, we can declare it as a const member function by adding the const keyword
// after the function declaration. This ensures that the function cannot change any
// member variables of the class.

// In this example, we will create a class Customer with static data member to keep
// track of the number of customers/objects created.

#include <iostream>
using namespace std;

class Customer
{
    string name;
    int account_number, balance;
    static int total_balance;

public:
    static int total_customer; // Static data member to keep track of total customers
    // Common for all objects of the class, and created only once.
    // It needs to be initialized outside the class definition, as 0.
    // Constructor to initialize values/data members
    // Kept this in public to access directly while creating object
    // If kept in private, we can create a static member function to access it.

    Customer(string n, int a, int b)
    {
        name = n;
        account_number = a;
        balance = b;
        total_customer++;
        total_balance += b;
    }

    // Static member function to access static data member when private
    // static void accessStaticMember()
    // {
    //     cout << "Total Customers (from static member function): " << total_customer << endl;
    // }
    // This function can't access non-static data members.

    static void accessTotalBalance()
    {
        cout << "Total Balance of all customers: " << total_balance << endl;
    }

    // Add amount to customer balance/object balance
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;       // customer balance updated
            total_balance += amount; // bank's total balance updated
        }
    }

    void withdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            total_balance -= amount;
        }
    }

    void display()
    {
        cout << name << " " << account_number << " " << balance << " " << total_customer << endl;
    }

    void display_total_customer()
    {
        cout << "Total Customers: " << total_customer << endl;
    }
};

int Customer::total_customer = 0; // Static data member initialization outside class
// :: Scope resolution operator used to define static data member outside class
// this is required because static members are not tied to any specific object,
// but rather belong to the class itself.
// All objects point to the same memory location for static members.
int Customer::total_balance = 0;

int main()
{
    // int total_customer = 0; Can't use this method to keep track of total customers
    Customer c1("Alice", 1001, 5000);
    c1.display_total_customer(); // Output would be: Total Customers: 1
    Customer c2("Bob", 1002, 3000);
    c1.display();
    c2.display();
    c1.display_total_customer(); // Output would be: Total Customers: 2
    // Output would be: Alice 1001 5000 2       Bob 1002 3000 2
    Customer c3("Cherry", 1003, 4000);
    c3.display();
    c1.display();
    c2.display();
    c1.display_total_customer(); // Output would be: Total Customers: 3
    // Output would be: Cherry 1003 4000 3      Alice 1001 5000 3       Bob 1002 3000 3
    Customer::accessTotalBalance(); // Accessing static member function without any object
    c1.deposit(1500);
    c2.withdraw(1000);
    c1.display();                  // Output would be: Alice 1001 6500 3
    c2.display();                  // Output would be: Bob 1002 2000 3
    Customer ::total_customer = 5; // Can directly access member of the class without any object
    c2.display_total_customer();   // Output would be: Total Customers: 5
    // Customer::accessStaticMember(); // Accessing static member function without any object
    Customer::accessTotalBalance();
}