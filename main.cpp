#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Employee {
    string name, gender, address, degree, office, dateStart, dateEnd;
};

// Convert CSV line to Employee struct
Employee parseCSVLine(const string& line) {
    stringstream ss(line);
    Employee emp;
    getline(ss, emp.name, ',');
    getline(ss, emp.gender, ',');
    getline(ss, emp.address, ',');
    getline(ss, emp.degree, ',');
    getline(ss, emp.office, ',');
    getline(ss, emp.dateStart, ',');
    getline(ss, emp.dateEnd, ',');
    return emp;
}

// Convert Employee struct to CSV line
string toCSVLine(const Employee& emp) {
    return emp.name + "," + emp.gender + "," + emp.address + "," +
           emp.degree + "," + emp.office + "," + emp.dateStart + "," + emp.dateEnd;
}

// Load all employees from CSV file
vector<Employee> loadEmployees(const string& filename) {
    vector<Employee> employees;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            employees.push_back(parseCSVLine(line));
        }
    }
    return employees;
}

// Save all employees to CSV file
void saveEmployees(const vector<Employee>& employees, const string& filename) {
    ofstream file(filename);
    for (const auto& emp : employees) {
        file << toCSVLine(emp) << endl;
    }
}

// Add a new employee
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
    cout << "Employee added successfully.\n";
}

// Display all employees
void listEmployees(const vector<Employee>& employees) {
    cout << "\n--- Employee Records ---\n";
    for (size_t i = 0; i < employees.size(); ++i) {
        const auto& emp = employees[i];
        cout << "[" << i + 1 << "] " << emp.name << " | " << emp.gender << " | " 
             << emp.address << " | " << emp.degree << " | " << emp.office
             << " | " << emp.dateStart << " - " << emp.dateEnd << "\n";
    }
}

// Edit an existing employee
void editEmployee(vector<Employee>& employees) {
    listEmployees(employees);
    int index;
    cout << "Enter the number of the employee to edit: ";
    cin >> index;
    if (index < 1 || index > employees.size()) {
        cout << "Invalid index.\n";
        return;
    }

    Employee& emp = employees[index - 1];
    cin.ignore();
    cout << "Editing employee: " << emp.name << "\n";
    cout << "Enter new Name (" << emp.name << "): "; getline(cin, emp.name);
    cout << "Enter new Gender (" << emp.gender << "): "; getline(cin, emp.gender);
    cout << "Enter new Address (" << emp.address << "): "; getline(cin, emp.address);
    cout << "Enter new Degree (" << emp.degree << "): "; getline(cin, emp.degree);
    cout << "Enter new Office (" << emp.office << "): "; getline(cin, emp.office);
    cout << "Enter new Date Started (" << emp.dateStart << "): "; getline(cin, emp.dateStart);
    cout << "Enter new Date Ended (" << emp.dateEnd << "): "; getline(cin, emp.dateEnd);
    cout << "Employee updated.\n";
}

// Delete an employee
void deleteEmployee(vector<Employee>& employees) {
    listEmployees(employees);
    int index;
    cout << "Enter the number of the employee to delete: ";
    cin >> index;
    if (index < 1 || index > employees.size()) {
        cout << "Invalid index.\n";
        return;
    }

    employees.erase(employees.begin() + index - 1);
    cout << "Employee deleted.\n";
}

// Main program
int main() {
    const string filename = "employees.csv";
    vector<Employee> employees = loadEmployees(filename);
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. List Employees\n";
        cout << "3. Edit Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Save and Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(employees); break;
            case 2: listEmployees(employees); break;
            case 3: editEmployee(employees); break;
            case 4: deleteEmployee(employees); break;
            case 5:
                saveEmployees(employees, filename);
                cout << "Data saved. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
