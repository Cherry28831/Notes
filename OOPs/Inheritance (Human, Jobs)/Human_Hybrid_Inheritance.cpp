// Hybrid Inheritance: Combination of different inheritance types in one program
// This example combines: Multiple inheritance + Hierarchical inheritance
// Structure: Student is inherited by both Boy and Girl (Hierarchical)
//           Boy inherits from Student + Male (Multiple)
//           Girl inherits from Student + Female (Multiple)
// Real-world: Complex family tree or organizational structure

#include <iostream>
using namespace std;

// Base class 1: Student
// Will be inherited by both Boy and Girl (Hierarchical inheritance)
class Student
{
public:
    void print()
    {
        cout << "I am a student\n";
    }
};

// Base class 2: Male
// Will be inherited by Boy class only
class Male
{
public:
    void Mprint()
    {
        cout << "I am a male\n";
    }
};

// Base class 3: Female
// Will be inherited by Girl class only
class Female
{
public:
    void Fprint()
    {
        cout << "I am a female\n";
    }
};

// Derived class 1: Boy
// Multiple inheritance - inherits from both Student and Male
class Boy : public Student, public Male
{
public:
    void Bprint()
    {
        cout << "I am a boy\n";
    }
    // Boy has access to: print() from Student, Mprint() from Male, Bprint() own
};

// Derived class 2: Girl
// Multiple inheritance - inherits from both Student and Female
class Girl : public Student, public Female
{
public:
    void Gprint()
    {
        cout << "I am a girl\n";
    }
    // Girl has access to: print() from Student, Fprint() from Female, Gprint() own
};

int main()
{
    // Create Girl object - has access to Student and Female methods
    Girl g1;
    g1.print();  // From Student class
    g1.Fprint(); // From Female class
    g1.Gprint(); // Own method
    
    cout << "\n";
    
    // Create Boy object - has access to Student and Male methods
    Boy b1;
    b1.print();  // From Student class
    b1.Mprint(); // From Male class
    b1.Bprint(); // Own method
    
    return 0;
}