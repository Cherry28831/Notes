// Abstraction: Displaying only essential information and hiding the details
// No need to know how data is stored, just need to know how to use it
// In ATM, we just need to know how to use it, not how it gives us money
// In Insta, we need to know how to post a picture, not how it works internally
// User just needs to know the interface, not the implementation
// Why do we need it? To reduce complexity and increase efficiency
// And to increase security of data, so that no one else can steal/access it

#include <iostream>
using namespace std;

class Customer
{
    string name;
    int balance;

public:
    Customer(string n, int b)
    {
        name = n;
        balance = b;
    }

    // No need to show how balance is stored internally to the user
    //  Example: ATM machine. No need to show that GST is cut while depositing money
    //  User just deposits money and doesn't know money is deducted as GST
    //  Example: int ans = pow(2,3); User just knows that it gives 8
    //  User doesn't know how pow function is implemented internally (math function)
    //  Same goes for sort(arr.begin(), arr.end());
    //  Another benefit: We just need to only change this function
    //  Not the way we declare it in main function
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }
};

int main()
{
    Customer c1("Alice", 5000);
    c1.deposit(2000); // User just needs to know how to use deposit function
    return 0;
}