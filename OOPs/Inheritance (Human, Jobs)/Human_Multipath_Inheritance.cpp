// Multipath Inheritance (Diamond Problem):
// Also known as Diamond Inheritance due to its diamond-shaped structure
// Occurs when a class inherits from two classes that both inherit from the same base class
//
// Example Hierarchy:
// Human (name) is the base class
// Engineer and Youtuber classes both inherit from Human
// CodeTeacher inherits from both Engineer and Youtuber
//
// The Problem:
// CodeTeacher gets duplicate copies of Human's members (name)
// This creates ambiguity: which Human's name should be accessed?
// Compiler doesn't know whether to use Engineer's Human or Youtuber's Human
//
// The Solution:
// Virtual inheritance ensures only one copy of Human class exists
// Both Engineer and Youtuber use 'virtual public Human'
// This eliminates duplicate copies and resolves ambiguity

// Diamond Problem Structure:
//       Human (Grandparent)
//      /              \
//  Engineer        Youtuber (Parents)
//      \              /
//    CodeTeacher (Child)
//
// Memory Layout Comparison:
// Without virtual inheritance:
//   CodeTeacher contains TWO separate Human objects
//   Problem: Ambiguous access to Human members
//
// With virtual inheritance:
//   CodeTeacher contains ONE shared Human object
//   Solution: Clear, unambiguous access to Human members
//
// Virtual Inheritance Syntax:
// class Engineer : public virtual Human    // 'virtual' keyword is key
// class Youtuber : public virtual Human    // Both parents use virtual inheritance
// class CodeTeacher : public Youtuber, public Engineer  // Child inherits normally
//
// Key Benefits:
// 1. Eliminates ambiguity in member access (no more confusion)
// 2. Saves memory by having single copy of base class
// 3. Resolves diamond inheritance conflicts automatically
// 4. Maintains logical inheritance hierarchy
//
// Important Constructor Rule:
// The most derived class (CodeTeacher) must explicitly call
// the virtual base class (Human) constructor in its initializer list

#include <iostream>
using namespace std;

class Human
{
public:
    string name;
    void display()
    {
        cout << "My name is " << name << endl;
    }
};

class Engineer : public virtual Human
{
public:
    string specialization;
    void work()
    {
        cout << "I have a specialization in " << specialization << endl;
    }
};

class Youtuber : public virtual Human
{
public:
    int subscribers;
    void content()
    {
        cout << "I have " << subscribers << " subscribers" << endl;
    }
};

// Child class: CodeTeacher inherits from both Engineer and Youtuber
// Demonstrates diamond inheritance with virtual base class
class CodeTeacher : public Youtuber, public Engineer
{
public:
    string salary;

    CodeTeacher()
    {
    }

    CodeTeacher(string name, string spec, int subs, int salary)
    {
        this->name = name;     // No ambiguity due to virtual inheritance
        specialization = spec; // From Engineer class
        subscribers = subs;    // From Youtuber class
        this->salary = salary; // Own property
    }
};

int main()
{
    CodeTeacher ct("John", "C++", 10000, 100000);

    // Virtual inheritance allows clear access to Human methods
    ct.display(); // No ambiguity - calls Human's display()
    ct.work();    // From Engineer class
    ct.content(); // From Youtuber class

    // Without virtual inheritance, ct.display() would cause compilation error
    // With virtual inheritance, there's only one Human object to access

    return 0;
}