// Inheritance: The capability of a class to derive properties
// and characteristics from another class.
// Real Life Example: Inheriting features from parents to child.
// We don't inherit every feature, we have different features too.

// Human class: String name. Int age, weight.
// Student class: String name. Int age, weight, fees, roll no.
// Teacher class: String name. Int age, weight, salary, id.
// There's duplicate code in Student and Teacher class which is already
// present in Human class. To avoid this duplication, we can use Inheritance.
// Parent/Base class: Human
// Child/Derived class: Student, Teacher

//          External Code         Within class         Derived class
// Public:      Yes                   Yes                 Yes
// Protected:   No                    Yes                 Yes
// Private:     No                    Yes                 No

// How to create derived class?
// Class Student: ______________ Human
//         Child: Access modifier
// Class ChildName: AccessModifier BaseClassName
// We use access modifier to set the visibility of base class members in derived class.
// If we data members are public in base class, they will be public in derived class too.
// If we set protected access modifier while inheriting, then public members of base class
// will become protected members of derived class.

// Private > Protected > Public (Strength wise)
// Inheritance Access Modifier Table:
//
// Base Class Member | Derived Class Access | Result in Derived Class
// ------------------|---------------------|------------------------
// public            | public              | public
// public            | protected           | protected
// public            | private             | private
// protected         | public              | protected
// protected         | protected           | protected
// protected         | private             | private
// private           | any                 | not accessible

#include <iostream>
using namespace std;

class Human
{
private:
    int a;
    int religion, color; // Why do we keep these in private?
    // Because these are personal details, not to be shared
    // These can't be accessed outside the class, as well as in derived class
    // string name;
    // int age, weight;

protected: // These can be accessed inside the class and in derived class
    int b;
    string name;
    int age, weight;
    void fun2()
    {
        a = 10;
        b = 20;
        c = 30;
    }

public: // These can be accessed from anywhere
    int c;
    // string name;
    // int age, weight;
    void fun3()
    {
        a = 10;
        b = 20;
        c = 30;
    }
};

class Student : public Human
{
    int rollno, fees;
};

class Teacher : protected Human
{
private:
    int id, salary;

public: // Can't access
    void fun(string n, int a, int w)
    {
        name = n;
        age = a;
        weight = w;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
    }
};

// Use private to hide data members from outside world
// Why? To protect sensitive data
class Customer : private Human
{
private:
    int id, amount;

public:
    // We inherited name, age, weight as private from Human class, and id, amount are Customer class members
    //  Which are private to Customer class only
    Customer(int i, int amt, string n, int a, int w)
    {
        id = i;
        amount = amt;
        name = n;
        age = a;
        weight = w;
    }

    void display()
    {
        cout << "Customer ID: " << id << endl;
        cout << "Amount: " << amount << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
    }
};

int main()
{
    Human h1;
    // h1.a = 10; Error h1.a is private
    // h1.b = 20; Error h1.b is protected
    h1.c = 30;
    h1.fun3(); // This will work as fun is public and inside the class
    // h1.fun2(); Error, h1.fun2 is protected and can be accessed inside the class or derived class only
    Student s1;
    // s1.name = "Cherry"; // Error if name is private/protected in base class
    // As, the class Student is public
    Teacher t1;
    t1.fun("ABC", 30, 70);
    t1.display();
    Customer c1(101, 5000, "XYZ", 25, 80);
    c1.display();
}