#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>

using namespace std;

struct Employee
{
    int id;
    string name;
    double salary;
};

void displayEmployee(const Employee &emp)
{
    cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: $" << emp.salary << endl;
}

void displayAllEmployees(const vector<Employee> &employees)
{
    if (employees.empty())
    {
        cout << "No employees found." << endl;
        return;
    }
    for (const auto &employee : employees)
    {
        displayEmployee(employee);
    }
}

void addEmployee(vector<Employee> &employees, int id, const string &name, double salary)
{
    employees.push_back({id, name, salary});
    cout << "Employee added successfully." << endl;
}

void updateEmployee(vector<Employee> &employees, int id, const string &name, double salary)
{
    auto it = find_if(employees.begin(), employees.end(), [id](const Employee &e)
                      { return e.id == id; });
    if (it != employees.end())
    {
        it->name = name;
        it->salary = salary;
        cout << "Employee updated successfully." << endl;
    }
    else
    {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

void deleteEmployee(vector<Employee> &employees, int id)
{
    auto it = remove_if(employees.begin(), employees.end(), [id](const Employee &e)
                        { return e.id == id; });
    if (it != employees.end())
    {
        employees.erase(it, employees.end());
        cout << "Employee deleted successfully." << endl;
    }
    else
    {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

void viewEmployee(const vector<Employee> &employees, int id)
{
    auto it = find_if(employees.begin(), employees.end(), [id](const Employee &e)
                      { return e.id == id; });
    if (it != employees.end())
    {
        displayEmployee(*it);
    }
    else
    {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

int main()
{
    vector<Employee> employees = {
        {101, "Pratik", 100000},
        {102, "Akshit", 30000},
        {103, "Nilay", 50000},
        {104, "Shubh", 60000},
        {105, "Kapil", 70000},
    };

    int choice;
    do
    {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. View All Employees\n";
        cout << "2. Add Employee\n";
        cout << "3. Update Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. View Specific Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAllEmployees(employees);
            break;
        case 2:
        {
            int id;
            string name;
            double salary;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Salary: ";
            cin >> salary;
            addEmployee(employees, id, name, salary);
            break;
        }
        case 3:
        {
            int id;
            string name;
            double salary;
            cout << "Enter ID of the employee to update: ";
            cin >> id;
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter New Salary: ";
            cin >> salary;
            updateEmployee(employees, id, name, salary);
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter ID of the employee to delete: ";
            cin >> id;
            deleteEmployee(employees, id);
            break;
        }
        case 5:
        {
            int id;
            cout << "Enter ID of the employee to view: ";
            cin >> id;
            viewEmployee(employees, id);
            break;
        }
        case 6:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
