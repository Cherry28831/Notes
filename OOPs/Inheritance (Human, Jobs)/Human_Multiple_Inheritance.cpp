// Multiple Inheritance: A class inherits from more than one base class
// Structure: class Child : public Parent1, public Parent2
// Example: Youtuber class and Teacher class are present. We have another class which inherits both, and has extra properties of Gamer.
// Real-world: A person can be both a Teacher and a YouTuber

// Benefits: Combines functionality from multiple sources
// Drawbacks: Diamond problem, complexity, ambiguity issues

// DIAMOND PROBLEM in Multiple Inheritance:
// Problem occurs when two base classes inherit from the same grandparent class
// Structure:
//     Person (name)
//    /            \
// Teacher       YouTuber
//    \            /
//         Gamer
//
// Issue: TeacherGamer gets TWO copies of Person's members (ambiguity)
// Solution: Virtual Inheritance
// class Teacher : virtual public Person     class YouTuber : virtual public Person
// This ensures only ONE copy of Person exists in TeacherGamer
// Without virtual inheritance: TeacherGamer.name is ambiguous (which name?)
// With virtual inheritance: TeacherGamer.name is clear (single copy)

#include <iostream>
using namespace std;

// Base class 1: Engineer
// Contains engineering-related properties and methods
class Engineer
{
private:
    void money() // Private method - not accessible to derived classes
    {
        cout << "I make money" << endl;
    }

public:
    Engineer()
    {
        cout << "Hello Engineer" << endl;
    }
    string specialization; // Public member - accessible to derived classes
    void work()
    {
        cout << "I have a specialization in " << specialization << endl;
    }
};

// Base class 2: Youtuber
// Contains YouTube channel-related properties and methods
class Youtuber
{
public:
    int subscribers; // Number of subscribers
    Youtuber()
    {
        cout << "Hello Youtuber" << endl;
    }
    void subscribe()
    {
        cout << "I have " << subscribers << " subscribers" << endl;
    }
};

// Derived class inheriting from both Engineer and Youtuber
// Demonstrates multiple inheritance - combines both base classes
class CodeTeacher : public Engineer, public Youtuber
{
public:
    string name; // Own property specific to CodeTeacher

    // Default constructor - calls both base class constructors
    CodeTeacher()
    {
        cout << "Hello Coder";
    }

    // Parameterized constructor - initializes all properties
    CodeTeacher(string n, string spec, int sub)
    {
        name = n;              // Own property
        specialization = spec; // From Engineer class
        subscribers = sub;     // From Youtuber class
    }

    // Method that uses functionality from both base classes
    void show()
    {
        cout << "My name is " << name << endl;
        work();      // Method from Engineer class
        subscribe(); // Method from Youtuber class
    }
};

int main()
{
    // Create CodeTeacher object with parameters for all properties
    CodeTeacher c1("Cherry", "C++", 10000);
    c1.show(); // Uses methods from both base classes
    c1.work(); // Direct access to Engineer's public method
    // c1.money(); // Error: Can't access Engineer's private members

    // Constructor call order demonstration
    CodeTeacher c2; // Output: Hello Engineer, Hello Youtuber, Hello Coder

    // Constructor Order Rule:
    // Order depends on inheritance declaration: public Engineer, public Youtuber
    // If declared as: public Youtuber, public Engineer
    // Output would be: Hello Youtuber, Hello Engineer, Hello Coder

    // Destructor Order:
    // Destructors are called in REVERSE order of constructors
    // ~CodeTeacher, ~Youtuber, ~Engineer
    return 0;
}