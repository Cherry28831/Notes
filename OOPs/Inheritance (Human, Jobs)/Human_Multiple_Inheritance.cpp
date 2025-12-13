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
//   TeacherGamer
//
// Issue: TeacherGamer gets TWO copies of Person's members (ambiguity)
// Solution: Virtual Inheritance
// class Teacher : virtual public Person     class YouTuber : virtual public Person
// This ensures only ONE copy of Person exists in TeacherGamer
// Without virtual inheritance: TeacherGamer.name is ambiguous (which name?)
// With virtual inheritance: TeacherGamer.name is clear (single copy)

#include <iostream>
using namespace std;
