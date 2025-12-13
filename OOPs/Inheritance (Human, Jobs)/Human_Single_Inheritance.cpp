// Single Inheritance: When a derived class inherits from a single base class
// Human: name, age         Student: inherit from Human, roll no., fees.
// This takes place one after another in a single line.

#include <iostream>
using namespace std;

class Human
{
protected:
    string name;
    int age;

public:
    Human()
    {
        cout << " Human default constructor called" << endl;
    }

    void work()
    {
        cout << "I am working \n";
    }

    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    ~Human()
    {
        cout << " Human destructor called" << endl;
    }
};

class Student : public Human
{
    int rollno, fees;

public:
    Student()
    {
        cout << "Student default constructor called" << endl;
    }
    // Student(string name, int age, int rollno, int fees)
    // {
    //     this->name = name;
    //     this->age = age;
    //     this->rollno = rollno;
    //     this->fees = fees;
    // }

    Student(string name, int age, int rollno, int fees) : Human(name, age)
    {
        this->rollno = rollno;
        this->fees = fees;
    }

    void display() // To check if name and age is present or not
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Fees: " << fees << endl;
    }

    ~Student()
    {
        cout << " Student destructor called" << endl;
    }
};

int main()
{
    Student s1("Alice", 20, 101, 5000);
    s1.work(); // Inherited method from Human class
    // It works, because work is public in Human and Student inherits publicly from Human
    // But we cannot directly access name and age because it is protected in Human class
    Student s2;
    // Output: Human default constructor called
    //         Student default constructor called
    // Human default constructor is called first because Student's constructor calls Human's constructor first
    // Destructor will be called in the reverse order
    // Output: Student destructor called
    //         Human destructor called
    Student s3("Bob", 22, 102, 6000);
    s3.display(); // This will print the output from the inherited class, instead of the base class
    // Because it checks if the display is present or not in Student class
    // If it is not present in Student class, it doesn't have to check in Human class
    return 0;
}