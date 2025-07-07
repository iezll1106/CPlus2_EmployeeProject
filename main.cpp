#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    string name, gender, address, degree, office, dateStart, dateEnd;
};

void addEmployee(vector<Employee>& employees) {
    Employee emp;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, emp.name);
    cout << "Enter Gender: "; getline(cin, emp.gender);
    cout << "Enter Address: "; getline(cin, emp.address);
    cout << "Enter Degree: "; getline(cin, emp.degree);
    cout << "Enter Office: "; getline(cin, emp.office);
    cout << "Enter Date Started: "; getline(cin, emp.dateStart);
    cout << "Enter Date Ended (or 'Present'): "; getline(cin, emp.dateEnd);

    employees.push_back(emp);
    cout << "\n Employee added!\n";
}

int main() {
    vector<Employee> employees;

    // ONLY calling addEmployee to test it
    addEmployee(employees);

    // Optional: Print the added employee
    cout << "\n--- Employee List ---\n";
    for (const auto& emp : employees) {
        cout << emp.name << " | " << emp.gender << " | " << emp.address
             << " | " << emp.degree << " | " << emp.office
             << " | " << emp.dateStart << " - " << emp.dateEnd << "\n";
    }

    return 0;
}
