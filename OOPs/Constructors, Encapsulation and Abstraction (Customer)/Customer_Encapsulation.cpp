// Encapsulation: Wrapping up of data and information in a single unit
// While allowing access to only required data and information
// We encapsulate data members and member functions in a class
// The variables of a class are hidden (private) from other classes and
// can be accessed only through member functions of their own class
// This is called data hiding
// We do this so that user doesn't accidentally add wrong data to data members
// We change content using function so that the data isn't directly accessed
// and changed, instead checked and validated through functions

#include <iostream>
using namespace std;

class Customer
{
    string name;
    int balance;
    int age;

public:
    Customer(string a, int b, int c)
    {
        name = a;
        balance = b;
        age = c;
    }

    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully. New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid amount to deposit" << endl;
        }
    }

    void update_age(int age)
    {
        if (age > 0 && age < 100)
        {
            this->age = age;
        }
    }

    void display()
    {
        cout << "Name: " << name << ", Age: " << age << ", Balance: " << balance << endl;
    }
};

int main()
{
    Customer c1("Alice", 5000, 30);
    // c1.balance = 5000; // This will give error as balance is private
    // We cannot access private data members outside the class directly
    // If we want to deposit, and accidentally add a negative amount
    // It will reduce the balance, which is not correct
    // That's why we don't need direct access to data members
    // For them to not get corrupted
    c1.display();
    c1.deposit(2000); // Correct way to deposit amount
    c1.deposit(-500); // Invalid amount to deposit
    // c1.balance += -1000; // This will give error as balance is private
    c1.update_age(35); // Update age using member function
    c1.update_age(-5); // This won't get added to the original value, as it is not in range
    c1.display();
    return 0;
}