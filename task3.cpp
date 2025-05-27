#include <iostream>
#include <string>
using namespace std;

// === Клас працівника ===
class Worker {
protected:
    string position;
    double salary;
public:
    Worker() : position("Unknown"), salary(0.0) {}
    Worker(string pos, double sal) : position(pos), salary(sal) {}
    virtual ~Worker() {}

    // Перевантаження введення
    friend istream& operator>>(istream& in, Worker& w) {
        cout << "Enter position: ";
        getline(in, w.position);
        cout << "Enter salary: ";
        in >> w.salary;
        in.ignore(); // очищення буфера
        return in;
    }

    // Перевантаження виведення
    friend ostream& operator<<(ostream& out, const Worker& w) {
        out << "Position: " << w.position << "\n";
        out << "Salary: " << w.salary << "\n";
        return out;
    }
};

// === Клас батька сімейства ===
class Father {
protected:
    int numChildren;
    string spouseName;
public:
    Father() : numChildren(0), spouseName("Unknown") {}
    Father(int children, string spouse) : numChildren(children), spouseName(spouse) {}
    virtual ~Father() {}

    // Перевантаження введення
    friend istream& operator>>(istream& in, Father& f) {
        cout << "Enter number of children: ";
        in >> f.numChildren;
        in.ignore(); // очищення буфера
        cout << "Enter spouse name: ";
        getline(in, f.spouseName);
        return in;
    }

    // Перевантаження виведення
    friend ostream& operator<<(ostream& out, const Father& f) {
        out << "Number of children: " << f.numChildren << "\n";
        out << "Spouse name: " << f.spouseName << "\n";
        return out;
    }
};

// === Похідний клас: працівник-батько сімейства ===
class WorkerFather : public Worker, public Father {
protected:
    string name;
    int age;
public:
    WorkerFather() : name("Unknown"), age(0) {}
    WorkerFather(string n, int a, string pos, double sal, int children, string spouse)
        : Worker(pos, sal), Father(children, spouse), name(n), age(a) {}

    virtual ~WorkerFather() {}

    // Перевантаження введення
    friend istream& operator>>(istream& in, WorkerFather& wf) {
        cout << "Enter name: ";
        getline(in, wf.name);
        cout << "Enter age: ";
        in >> wf.age;
        in.ignore();

        // Введення частини Worker
        in >> static_cast<Worker&>(wf);
        // Введення частини Father
        in >> static_cast<Father&>(wf);

        return in;
    }

    // Перевантаження виведення
    friend ostream& operator<<(ostream& out, const WorkerFather& wf) {
        out << "=== Worker-Father Info ===\n";
        out << "Name: " << wf.name << "\n";
        out << "Age: " << wf.age << "\n";
        out << static_cast<const Worker&>(wf);
        out << static_cast<const Father&>(wf);
        return out;
    }

    // Метод для виведення всієї інформації
    void showInfo() const {
        cout << *this;
    }
};

// === main ===
int main() {
    WorkerFather wf;

    cout << "--- Input data for Worker-Father ---" << endl;
    cin >> wf;

    cout << "\n--- Output data ---" << endl;
    wf.showInfo();

    return 0;
}
