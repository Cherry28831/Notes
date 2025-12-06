#include <iostream>
using namespace std;

class Student
{
    string name;
    int age, roll;
    string grade;

public:
    // Function Setters to set the value of private members
    // But, why do we need setter and getter functions?
    // Other use of this is to add validation while setting values
    // For example, we can add a default value if the name is not entered
    // or we can restrict age to be within a certain range
    void setName(string n)
    {
        if (n.size() == 0)
        {
            cout << "Invalid Name";
            return;
        }
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }
    void setRoll(int r)
    {
        roll = r;
    }
    void setGrade(string g)
    {
        grade = g;
    }
    // Function Getters to get the value of private members
    void getName()
    {
        cout << name << endl;
    }
    void getAge()
    {
        cout << age << endl;
    }
    void getRoll()
    {
        cout << roll << endl;
    }
    // Setting a constraint to access grade only with a pin
    string getGrade(int pin)
    {
        if (pin == 123)
        {
            return grade;
        }
        return " ";
    }
};

int main()
{
    Student S1;
    S1.setName("");
    S1.setAge(20);
    S1.setRoll(101);
    S1.setGrade("A");
    // Cannot access private members directly
    // cout << S1.name << " " << S1.age << " " << S1.roll << " " << S1.grade << endl;
    // This will give error
    S1.getName();
    S1.getAge();
    S1.getRoll();
    cout << S1.getGrade(123) << endl;
    // Or we can directly print in getter functions
    Student *S = new Student; // Dynamic Memory Allocation
    S->setName("Apple");      // S is a pointer that points to object of class Student
    (*S).setAge(21);          // Dereferencing pointer S to access member functions
    S->getName();
    return 0;
}

// Anyone can access data if they were public, but using getters and setters
// functions we can add validation and constraints while accessing and setting data
// Object: An entity that has state and behavior, anything that exists in physical world
// Student S1 is an object of class Student

// Static v/s Dynamic Memory Allocation
// Static Memory Allocation: Memory is allocated at compile time
// Dynamic Memory Allocation: Memory is allocated at runtime using new keyword
// Stack Memory v/s Heap Memory
// Stack Memory: Used for static memory allocation, faster access, limited size
// Heap Memory: Used for dynamic memory allocation, slower access, larger size
// We use new keyword to allocate memory in heap (int *ptr = new int; *ptr = 10;)
// We use delete keyword to free memory allocated in heap (delete ptr;)