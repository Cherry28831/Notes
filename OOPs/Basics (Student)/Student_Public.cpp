// Class: User defined data type that holds its own data members and member functions
// Object: Instance of a class
// Class occupies no space in memory until an object is created
// Empty class size is 1 byte to give unique address to each object
// Access Modifies in C++
// 1. Public: Members are accessible from outside the class.
// 2. Private: Members are accessible only within the class.
// 3. Protected: Members are accessible within the class and by derived class.

#include <iostream>
using namespace std;

class Student
{
public: // access modifier, if not mentioned, it is private by default
    string name;
    int age, roll;
    string grade;
    // If we declare any member as private, we can use Getter and Setter functions
    // to access and set the value of private members.
    // Getter function to get the value of private member
    // Setter function to set the value of private member
};

int main()
{
    Student S1;
    S1.name = "Cherry";
    S1.age = 20;
    S1.roll = 101;
    S1.grade = "A";
    cout << S1.name << " " << S1.age << " " << S1.roll << " " << S1.grade << endl;
    return 0;
}
// Size of object S1 is sum of size of all its data members
// Size of string name + Size of int age + Size of int roll + Size of string + Size of string grade
// Size of object S1 = 24 + 4 + 4 + 24 = 56 bytes (may vary based on compiler)
// We have data padding between data members to make it multiple of 8 bytes / 4 bytes
// It takes 4 or 8 because memory can only read in chunks of 4 or 8 bytes (32 bit or 64 bit system)
// Even if we have char c and int b in class, the size will be 8 bytes instead of 5 bytes
// Why do we use Padding? For faster cycles and faster reading of data
// If we have char c, int a, char b in class, the size will be 12 bytes instead of 6 or 9 bytes
// because of padding between data members to make it multiple of 4 bytes
// order of data members also matters for size of object
// Use greedy approach to minimize padding
// Place larger data members first followed by smaller data members

// Example: Instagram. User: Class and you and many others are an object of that class.
// You have private data members like password, email, phone number etc.
// You have public data members like username, bio, posts etc.
// Example: Bank Account. Class: Customer. Object: Your bank account.
// You have private data members like account number, balance, pin etc.
// You have public data members like name, branch, account type etc.