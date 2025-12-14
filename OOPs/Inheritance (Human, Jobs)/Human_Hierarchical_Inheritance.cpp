// Hierarchical Inheritance: One base class with multiple derived classes
// Structure: One parent class, multiple children classes
// Example: Human (base) -> Student, Teacher, Staff (derived classes)
// Comparison: Multiple Inheritance (M-Parents, 1-Child) vs Hierarchical (1-Parent, M-Children)
// Real-world: Animal -> Dog, Cat, Bird (all animals but different types)

#include <iostream>
using namespace std;

// Base class: Human
// Contains common properties shared by all derived classes
class Human
{
protected:
    string name; // Protected - accessible to derived classes
    int age;

public:
    // Default constructor
    Human()
    {
        name = "No Name";
        age = 0;
    }

    // Parameterized constructor
    Human(string n, int a)
    {
        name = n;
        age = a;
    }

    // Base class display method
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class 1: Student inherits from Human
// Adds student-specific properties and methods
class Student : public Human
{
private:
    int rollNo;    // Student-specific property
    string course; // Student-specific property

public:
    // Constructor calls Human's parameterized constructor
    Student(string n, int a, int r, string c) : Human(n, a)
    {
        rollNo = r;
        course = c;
    }

    // Overridden display method - adds student-specific info
    void display()
    {
        cout << "Name: " << name << endl;      // From Human class
        cout << "Age: " << age << endl;        // From Human class
        cout << "Roll No: " << rollNo << endl; // Own property
        cout << "Course: " << course << endl;  // Own property
    }
};

// Derived class 2: Teacher inherits from Human
// Adds teacher-specific properties and methods
class Teacher : public Human
{
private:
    int salary; // Teacher-specific property

public:
    // Constructor manually sets inherited properties
    // Note: Could use Human(n, age) initializer list for better practice
    Teacher(int sal, string n, int age)
    {
        salary = sal;
        name = n;        // Accessing protected member from Human
        this->age = age; // Accessing protected member from Human
    }

    // Overridden display method - adds teacher-specific info
    void display()
    {
        cout << "Name: " << name << endl;     // From Human class
        cout << "Age: " << age << endl;       // From Human class
        cout << "Salary: " << salary << endl; // Own property
    }
};

int main()
{
    // Create Student object - uses Human's parameterized constructor
    Student s1("Rahul", 20, 1, "CSE");
    cout << "Student Details:" << endl;
    s1.display(); // Calls Student's overridden display method

    cout << "\nTeacher Details:" << endl;
    // Create Teacher object - manually initializes Human properties
    Teacher t1(100000, "Raj", 50);
    t1.display(); // Calls Teacher's overridden display method
    return 0;
}

// Hierarchical Inheritance Benefits:
// 1. Code reusability - common properties in base class
// 2. Consistent interface - all derived classes share base functionality
// 3. Easy maintenance - changes in base class affect all derived classes
// 4. Polymorphism support - can treat all derived objects as base type