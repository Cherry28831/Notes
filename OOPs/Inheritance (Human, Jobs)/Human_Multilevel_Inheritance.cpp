// Multilevel Inheritance: Chain of classes where each class inherits from the previous one
// Structure: A <- B <- C <- D (A is base, B inherits A, C inherits B, D inherits C)
// Example: Person (name) <- Employee (salary) <- Manager (dept)
// Real-world: Animal <- Dog <- German Shepherd
// Each level adds new properties while inheriting all previous properties

#include <iostream>
using namespace std;

// Level 1: Base class - Person
// Contains basic human information
class Person
{
protected:
    string name; // Protected so derived classes can access

public:
    void introduce()
    {
        cout << "Hello my name is: " << name << endl;
    }
};

// Level 2: Employee inherits from Person
// Adds employment-related information
class Employee : public Person
{
protected:
    int salary; // Protected for further inheritance

public:
    void monthly_salary()
    {
        cout << "My monthly salary is: " << salary << endl;
    }
    // Employee has access to: name (from Person) + salary (own)
    // Employee can call: introduce() (from Person) + monthly_salary() (own)
};

// Level 3: Manager inherits from Employee (which inherits from Person)
// Adds management-specific information
class Manager : public Employee
{
public:
    string dept; // Department information

    // Constructor initializes all inherited and own properties
    Manager(string name, int salary, string dept)
    {
        this->name = name;     // From Person (via Employee)
        this->salary = salary; // From Employee
        this->dept = dept;     // Own property
    }

    void work()
    {
        cout << "I am working in " << dept << " department." << endl;
    }
    // Manager has access to: name (Person) + salary (Employee) + dept (own)
    // Manager can call: introduce() (Person) + monthly_salary() (Employee) + work() (own)
};

int main()
{
    Manager m1("John", 100000, "Sales");

    // Manager can access methods from all levels of inheritance:
    m1.work();           // Level 3: Manager's own method
    m1.introduce();      // Level 1: Inherited from Person (via Employee)
    m1.monthly_salary(); // Level 2: Inherited from Employee

    // Access control still applies:
    // m1.salary = 10;      // Error: salary is protected in Employee
    m1.dept = "Marketing"; // OK: dept is public in Manager

    // Multilevel inheritance allows Manager to use all inherited functionality
    // while adding its own specific features
    return 0;
}