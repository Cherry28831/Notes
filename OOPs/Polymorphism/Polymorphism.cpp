// Polymorphism: This means many forms.
// Example: Male can be of many types: Father, Brother, Son, Husband, etc.

//                                       POLYMORPHISM
//                                   /                 \
//                        COMPILE-TIME                  RUNTIME
//                       (Static/Early)               (Dynamic/Late)
//                             |                            |
//                      +------+------+              +------+------+
//                      |             |              |             |
//                FUNCTION       OPERATOR         FUNCTION       OBJECT
//               OVERLOADING    OVERLOADING      OVERRIDING   POLYMORPHISM
//                      |             |              |             |
//              - Same name    - Same op         - Virtual     - Base ptr
//              - Diff args    - Diff              functions   - Derived
//              - Resolved       behavior        - Same          objects
//                at compile   - Custom            signature   - Runtime
//                               types           - Different     binding
//                                                 impl        - v-table

// Detailed Examples:
// Compile-time Polymorphism:
//   - Function Overloading: calculateArea(int) vs calculateArea(int, int)
//   - Operator Overloading: + operator for int vs + operator for Complex class
//   - Resolution: Compiler decides which function/operator to call based on parameters
//   - Performance: No runtime overhead, faster execution
//
// Runtime Polymorphism:
//   - Virtual Functions: Base pointer calling derived class methods
//   - Dynamic Binding: Actual method determined at runtime using v-table
//   - Flexibility: Can handle objects of different types through same interface

// Operator Overloading: Same operator working differently
// Example: int a = 5, b = 10. a + b = 11. But, string s1 = "Abc", s2 = "Efg". s1 + s2 = AbcEfg.
// We can do the same thing in classes.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Example 1: Function Overloading (Compile-time Polymorphism)
class Area
{
public:
    // Function Overloading: Same function name, different parameter lists
    // Compiler distinguishes based on number/type of parameters
    // Rule: Same function name with same parameters is not allowed

    // Version 1: Calculate circle area (1 parameter)
    int calculateArea(int r)
    {
        return 3.14 * r * r; // πr²
    }

    // Version 2: Calculate rectangle area (2 parameters)
    int calculateArea(int l, int b)
    {
        return l * b; // length × breadth
    }
};

// Example 2: Operator Overloading (Compile-time Polymorphism)
// Complex numbers: a + ib (where a=real part, b=imaginary part)
class Complex
{
    int real, img; // real: real number, img: imaginary number

public:
    // Constructor to initialize complex number
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    // Display complex number in a + ib format
    void display()
    {
        cout << real << " + i" << img << endl;
    }

    // Operator Overloading: Teaching the + operator how to work with Complex objects
    // Without this function: c1 + c2 would give ERROR (compiler doesn't know how to add Complex objects)
    // With this function: c1 + c2 works like normal addition
    // We can also overload most of the operators, like "<<" or ">>"
    // When you write: c1 + c2
    // Compiler converts it to: c1.operator+(c2)
    // This function gets called with c2 as parameter
    Complex operator+(Complex &c)
    {
        // Create new Complex object to store result
        Complex result(0, 0);

        // Add real parts: this object's real + parameter object's real
        result.real = real + c.real;

        // Add imaginary parts: this object's img + parameter object's img
        result.img = img + c.img;

        return result; // Return the sum as new Complex object
    }
    // Example: (3 + i2) + (4 + i6) = (3+4) + i(2+6) = 7 + i8
};

// Example 3: Runtime Polymorphism (Virtual Functions)
// Base class: Animal
class Animal
{
public:
    // Virtual function: Enables runtime polymorphism
    // 'virtual' keyword tells compiler to use dynamic binding
    // Without virtual: Early binding (compile-time decision)
    // With virtual: Late binding (runtime decision)
    // Creates v-table (virtual table) for dynamic method resolution
    virtual void speak()
    {
        cout << "HuHu";  // Default animal sound
    }
    
    // Pure virtual function (commented out):
    // virtual void speak() = 0;  // Makes Animal an abstract class
    // Abstract class: Cannot create objects, only pointers/references
    // Derived classes MUST implement pure virtual functions
};

// Derived class 1: Dog inherits from Animal
class Dog : public Animal
{
public:
    // Function Overriding: Same signature as base class virtual function
    // This overrides Animal's speak() method
    // No need to write 'virtual' again (but you can)
    void speak() override  // 'override' keyword ensures we're overriding correctly
    {
        cout << "Bark";  // Dog-specific sound
    }
    
    // Dog-specific method (not in Animal class)
    // This method is unique to Dog class
    void hi()
    {
        cout << "Hello\n";
    }
};

// Derived class 2: Cat inherits from Animal
class Cat : public Animal
{
public:
    // Function Overriding: Cat's version of speak()
    // Each derived class can have its own implementation
    void speak() override
    {
        cout << "Meow";  // Cat-specific sound
    }
};

int main()
{
    cout << "=== COMPILE-TIME POLYMORPHISM DEMO ===\n";
    
    // Function Overloading Demo
    Area a1;
    cout << "Circle area (r=4): " << a1.calculateArea(4) << "\n";        // Calls 1-parameter version
    cout << "Rectangle area (3x4): " << a1.calculateArea(3, 4) << "\n";   // Calls 2-parameter version
    // Compiler decides which function to call based on parameters at compile-time
    
    // This would cause compile-time error:
    // cout << a1.calculateArea("Cherry");  // No matching function for string parameter

    // Operator Overloading Demo
    cout << "\nOperator Overloading Demo:\n";
    Complex c1(3, 2), c2(4, 6);  // Create two complex numbers
    cout << "c1: "; c1.display();
    cout << "c2: "; c2.display();
    
    // Without operator overloading: c1 + c2 would give ERROR
    // With operator overloading: c1 + c2 works like built-in types
    Complex c3 = c1 + c2;  // Compiler converts this to: c1.operator+(c2)
    cout << "c1 + c2 = "; c3.display();
    // Result: (3+4) + i(2+6) = 7 + i8

    cout << "\n=== RUNTIME POLYMORPHISM DEMO ===\n";
    
    // Step 1: Create base pointer pointing to derived object
    Animal *a = new Dog();  // Base pointer, derived object
    // Why this works: Dog IS-A Animal (inheritance relationship)
    // Animal *a        - Creates a pointer variable 'a' of type Animal
    // new Dog()        - Creates a Dog object in heap memory
    // =                - Makes Animal pointer 'a' point to Dog object
    // Key Point: Base class pointer (Animal) holding derived class object (Dog)
    // This is allowed because Dog IS-A Animal (inheritance relationship)

    // Calling method through base pointer
    a->speak();
    // a->              - Arrow operator to access methods through pointer
    // speak()          - Calls the speak() method
    // What happens depends on whether speak() is virtual:
    // WITHOUT virtual: Calls Animal's speak() - Static binding (compile-time decision)
    //                  Output: "HuHu" (Animal's version)
    // WITH virtual:    Calls Dog's speak() - Dynamic binding (runtime decision)
    //                  Output: "Bark" (Dog's version)
    // Runtime Polymorphism: Same interface (speak()) but different behavior

    // Step 3: Polymorphism with arrays/vectors - Real power of polymorphism
    cout << "\nPolymorphism with multiple objects:\n";
    vector<Animal *> animals;  // Array of Animal pointers
    animals.push_back(new Dog());    // Add Dog object
    animals.push_back(new Cat());    // Add Cat object
    animals.push_back(new Animal()); // Add Animal object
    animals.push_back(new Dog());    // Add another Dog
    animals.push_back(new Cat());    // Add another Cat
    
    // Loop through all animals and call speak() - each calls its own version
    for(int i = 0; i < animals.size(); i++) {
        cout << "Animal " << i+1 << ": ";
        animals[i]->speak();  // Calls appropriate speak() based on actual object type
        cout << "\n";
    }
    // Output: Bark, Cat, HuHu, Bark, Cat
    // Same method call, different behaviors - this is polymorphism!

    // Step 4: Limitation - can't call derived-specific methods
    // a->hi(); // COMPILE ERROR!
    // Why a->hi() doesn't work:
    // - 'a' is Animal pointer, compiler only sees Animal methods
    // - hi() exists in Dog class, not Animal class
    // - Pointer type determines accessible methods, not object type
    
    // Solution: Cast to Dog pointer
    cout << "\nCasting to access Dog-specific method:\n";
    ((Dog*)a)->hi();  // Now we can call Dog-specific methods
    
    // Clean up memory
    delete a;
    for(Animal* animal : animals) {
        delete animal;
    }
    
    return 0;
}