// Class: User defined data type that holds its own data members and member functions
// Object: Instance of a class
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