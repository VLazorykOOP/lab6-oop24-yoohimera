#include <iostream>
using namespace std;

// --------------------------
// Без віртуального успадкування
// --------------------------

class A1 {
public:
    int a1;
};

class B1 : public A1 {
public:
    int b1;
};

class C1 : public A1 {
public:
    int c1;
};

class D1 : public B1, public C1 {
public:
    int d1;
};

// --------------------------
// З віртуальним успадкуванням
// --------------------------

class A2 {
public:
    int a2;
};

class B2 : virtual public A2 {
public:
    int b2;
};

class C2 : virtual public A2 {
public:
    int c2;
};

class D2 : public B2, public C2 {
public:
    int d2;
};

// --------------------------
// main()
// --------------------------

int main() {
    // === Без virtual ===
    D1 object1;
    object1.B1::a1 = 1;
    object1.b1 = 2;
    object1.C1::a1 = 3;
    object1.c1 = 4;
    object1.d1 = 5;

    cout << "=== Without virtual inheritance ===" << endl;
    cout << "B1::a1 = " << object1.B1::a1 << endl;
    cout << "b1 = " << object1.b1 << endl;
    cout << "C1::a1 = " << object1.C1::a1 << endl;
    cout << "c1 = " << object1.c1 << endl;
    cout << "d1 = " << object1.d1 << endl;
    cout << "Size of object D1: " << sizeof(object1) << " bytes" << endl;

    // === З virtual ===
    D2 object2;
    object2.a2 = 10;
    object2.b2 = 20;
    object2.c2 = 30;
    object2.d2 = 40;

    cout << "\n=== With virtual inheritance ===" << endl;
    cout << "a2 = " << object2.a2 << endl;
    cout << "b2 = " << object2.b2 << endl;
    cout << "c2 = " << object2.c2 << endl;
    cout << "d2 = " << object2.d2 << endl;
    cout << "Size of object D2: " << sizeof(object2) << " bytes" << endl;

    return 0;
}
