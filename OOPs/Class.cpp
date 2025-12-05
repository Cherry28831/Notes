#include <iostream>
using namespace std;

class Student
{
public:          // access modifier, if not mentioned, it is private by default
    string name; // private = can be accessed only within the class
    int age, roll;
    string grade;
};

int main()
{
    Student S1;
    S1.name = "Cherry";
    S1.age = 20;
    S1.roll = 101;
    S1.grade = "A";
    return 0;
}