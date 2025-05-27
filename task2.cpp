#include <iostream>
#include <cmath>    // для sqrt
using namespace std;

// Абстрактний клас Function
class Function {
public:
    virtual double calculate(double x) const = 0; // чисто віртуальна функція
    virtual ~Function() {}
};

// Пряма: y = ax + b
class Line : public Function {
    double a, b;
public:
    Line(double a_, double b_) : a(a_), b(b_) {}
    double calculate(double x) const override {
        return a * x + b;
    }
};

// Еліпс: (x^2)/a^2 + (y^2)/b^2 = 1 → y = ±b * sqrt(1 - (x^2)/a^2)
class Ellipse : public Function {
    double a, b;
public:
    Ellipse(double a_, double b_) : a(a_), b(b_) {}
    double calculate(double x) const override {
        if (abs(x) > a) {
            cout << "x is outside the ellipse domain!" << endl;
            return NAN;
        }
        return b * sqrt(1 - (x * x) / (a * a)); // повертаємо верхню половину
    }
};

// Гіпербола: (x^2)/a^2 - (y^2)/b^2 = 1 → y = ±b * sqrt((x^2)/a^2 - 1)
class Hyperbola : public Function {
    double a, b;
public:
    Hyperbola(double a_, double b_) : a(a_), b(b_) {}
    double calculate(double x) const override {
        if (abs(x) < a) {
            cout << "x is inside the hyperbola gap!" << endl;
            return NAN;
        }
        return b * sqrt((x * x) / (a * a) - 1); // верхня гілка
    }
};

int main() {
    // Масив вказівників на базовий клас
    const int size = 3;
    Function* funcs[size];

    // Створення об'єктів похідних класів
    funcs[0] = new Line(2.0, 3.0);       // y = 2x + 3
    funcs[1] = new Ellipse(5.0, 4.0);    // a = 5, b = 4
    funcs[2] = new Hyperbola(3.0, 2.0);  // a = 3, b = 2

    double x;
    cout << "Enter x: ";
    cin >> x;

    // Вивід результатів
    cout << "\nResults:\n";
    cout << "Line: y = " << funcs[0]->calculate(x) << endl;
    cout << "Ellipse: y = " << funcs[1]->calculate(x) << endl;
    cout << "Hyperbola: y = " << funcs[2]->calculate(x) << endl;

    // Звільнення пам'яті
    for (int i = 0; i < size; ++i) {
        delete funcs[i];
    }

    return 0;
}
