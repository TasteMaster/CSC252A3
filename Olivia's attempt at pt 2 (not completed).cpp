#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 

using namespace std;

// --- 1. Person Class ---
class Person {
protected:
    string name;
    string phoneNumber;
    string emailAddress;

public:
    Person(string name, string phoneNumber, string emailAddress)
        : name(name), phoneNumber(phoneNumber), emailAddress(emailAddress) {
    }

    virtual string toString() const {
        return "Person named " + name + " has phone number " + phoneNumber +
            " and can be reached at " + emailAddress;
    }

    virtual ~Person() = default;
};

// --- 2. Student Class ---
class Student : public Person {
private:
    string yearInCollege;

public:
    Student(string name, string phoneNumber, string emailAddress, string yearInCollege)
        : Person(name, phoneNumber, emailAddress), yearInCollege(yearInCollege) {
    }

    string toString() const override {
        return Person::toString() + " is in the " + yearInCollege + " year";
    }
};

// --- 3. Employee Class ---
class Employee : public Person {
protected:
    string salary;

public:
    Employee(string name, string phoneNumber, string emailAddress, string salary)
        : Person(name, phoneNumber, emailAddress), salary(salary) {
    }

    string toString() const override {
        return Person::toString() + " earns " + salary;
    }
};

// --- 4. Faculty Class ---
class Faculty : public Employee {
private:
    string title;

public:
    Faculty(string name, string phoneNumber, string emailAddress, string salary, string title)
        : Employee(name, phoneNumber, emailAddress, salary), title(title) {
    }

    string toString() const override {
        return Employee::toString() + " is a/an " + title;
    }
};

// --- 5. Staff Class ---
class Staff : public Employee {
private:
    string role;

public:
    Staff(string name, string phoneNumber, string emailAddress, string salary, string role)
        : Employee(name, phoneNumber, emailAddress, salary), role(role) {
    }

    string toString() const override {
        return Employee::toString() + " handles " + role;
    }
};

int main() {
    vector<Person*> people;

    people.push_back(new Person("Susan", "800-555-1212", "susan@quirkymail.com"));
    people.push_back(new Student("Jerry", "123-456-7890", "jerjer@nat.edu", "sophomore"));
    people.push_back(new Employee("Larry", "333-444-5555", "larry@threestooges.org", "123456.00"));
    people.push_back(new Faculty("Linda", "987-654-3210", "lindalou@whoknew.edu", "150000.00", "adjunct professor"));
    people.push_back(new Staff("Jane", "567-123-6565", "jane@whizkid.com", "100000.00", "registration"));

    cout << "--- List of People ---\n";
    for (const Person* p : people) {
        cout << p->toString() << "\n";
    }

    for (Person* p : people) {
        delete p;
    }
    people.clear();

    return 0;
}
