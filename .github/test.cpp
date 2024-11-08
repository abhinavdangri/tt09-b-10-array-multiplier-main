#include <iostream>

using namespace std;

class A {
public:
    void x() {
        y();
        z();
    }
    
    void y() {
        cout << "A::y()" << endl;
    }
    
    virtual void z() {
        cout << "A::z()" << endl;
    }
}; // class A

class B: public A {
public:
    void y() {
        cout << "B::y()" << endl;
    }
    
    void z() {
        cout << "B::z()" << endl;
    }
}; // class B

class C: public B {
public:
    void z() {
        cout << "C::z()" << endl;
    }
}; // class C

int main() {
    cout << "Using A* aPtr = new B()\n";
    A* aPtr = new B();
    cout << "What does aPtr->y() print?\n";
    aPtr->y(); // What does this print?
    
    cout << "What does aPtr->z() print?\n";
    aPtr->z(); // What does this print?
    
    cout << "\nUsing B* bPtr = new B()\n";
    B* bPtr = new B();
    cout << "What does bPtr->x() print?\n";
    bPtr->x(); // What does this print?
    
    cout << "What does bPtr->y() print?\n";
    bPtr->y(); // What does this print?
    
    cout << "What does bPtr->z() print?\n";
    bPtr->z(); // What does this print?
    
    cout << "\nUsing B* bPtr = new C()\n";
    bPtr = new C();
    cout << "What does bPtr->z() print?\n";
    bPtr->z(); // What does this print?
}
