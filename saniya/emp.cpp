#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    float salary;
};

// Function to add employee
void addEmployee() {
    Employee e;
    ofstream fout("employee.txt", ios::app);

    cout << "Enter Employee ID: ";
    cin >> e.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, e.name);
    cout << "Enter Designation: ";
    getline(cin, e.designation);
    cout << "Enter Salary: ";
    cin >> e.salary;

    fout << e.id << " " << e.name << " " << e.designation << " " << e.salary << endl;
    fout.close();

    cout << "Employee added successfully.\n";
}

// Function to display employee by ID
void displayEmployee() {
    int id;
    bool found = false;
    Employee e;
    ifstream fin("employee.txt");

    cout << "Enter Employee ID to search: ";
    cin >> id;

    while (fin >> e.id >> e.name >> e.designation >> e.salary) {
        if (e.id == id) {
            cout << "\n--- Employee Details ---\n";
            cout << "ID: " << e.id << "\nName: " << e.name
                 << "\nDesignation: " << e.designation << "\nSalary: " << e.salary << endl;
            found = true;
            break;
        }
    }

    fin.close();
    if (!found)
        cout << "Employee record not found.\n";
}

// Function to delete employee by ID
void deleteEmployee() {
    int id;
    bool found = false;
    Employee e;
    ifstream fin("employee.txt");
    ofstream fout("temp.txt");

    cout << "Enter Employee ID to delete: ";
    cin >> id;

    while (fin >> e.id >> e.name >> e.designation >> e.salary) {
        if (e.id == id) {
            found = true;
            cout << "Deleting record of Employee ID: " << id << endl;
            continue;
        }
        fout << e.id << " " << e.name << " " << e.designation << " " << e.salary << endl;
    }

    fin.close();
    fout.close();

    remove("employee.txt");
    rename("temp.txt", "employee.txt");

    if (found)
        cout << "Record deleted successfully.\n";
    else
        cout << "Employee record not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Employee Management Menu ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: deleteEmployee(); break;
            case 3: displayEmployee(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

