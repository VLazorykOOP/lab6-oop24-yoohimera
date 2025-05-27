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
    D1 obj1;
    obj1.B1::a1 = 1;
    obj1.b1 = 2;
    obj1.C1::a1 = 3;
    obj1.c1 = 4;
    obj1.d1 = 5;

    cout << "=== Без віртуального успадкування ===" << endl;
    cout << "B1::a1 = " << obj1.B1::a1 << endl;
    cout << "b1 = " << obj1.b1 << endl;
    cout << "C1::a1 = " << obj1.C1::a1 << endl;
    cout << "c1 = " << obj1.c1 << endl;
    cout << "d1 = " << obj1.d1 << endl;
    cout << "Розмір об'єкта D1: " << sizeof(obj1) << " байт" << endl;

    // === З virtual ===
    D2 obj2;
    obj2.a2 = 10;
    obj2.b2 = 20;
    obj2.c2 = 30;
    obj2.d2 = 40;

    cout << "\n=== З віртуальним успадкуванням ===" << endl;
    cout << "a2 = " << obj2.a2 << endl;
    cout << "b2 = " << obj2.b2 << endl;
    cout << "c2 = " << obj2.c2 << endl;
    cout << "d2 = " << obj2.d2 << endl;
    cout << "Розмір об'єкта D2: " << sizeof(obj2) << " байт" << endl;

    return 0;
}
