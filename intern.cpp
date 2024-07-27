// general stream
//  write a class
//  create object of each class
//  serilize these objects into a file
//  read the file
//  deserilize the object

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

class Employee
{
public:
    string name;
    float salary;
};

class Customer
{
public:
    string name;
    string address;
};

class Sale
{
public:
    Customer customer;
    Employee salerep;
    float amount;
    time_t date = time(0);   // getting the time stamp
    char *dt = ctime(&date); // converting the timestamp to readble string. This variable is used for the Timestamp
};

void addEmployees(Employee emp[], int i)
{
    Employee obj1; // object for employee class
    cout << "Enter the name of the employee =" << "\n";
    cin >> obj1.name;
    emp[i].name = obj1.name;
    cout << "Enter the Salary of the employee = ";
    cin >> obj1.salary;
    emp[i].salary = obj1.salary;
}
void addCustomer(Customer cus[], int i)
{

    Customer obj1; // object for employee class
    cout << "Enter the name of the customer =" << "\n";
    cin >> obj1.name;
    cus[i].name = obj1.name;
    cout << "Enter the address of the customer = ";
    cin >> obj1.address;
    cus[i].address = obj1.address;
}

void addSales(Sale sal[], int i, Employee emp[], Customer cus[])
{
    Sale obj1;
    int empid;
    cout << "Which employee would you like? = ";
    cin >> empid;
    sal[i].salerep = emp[empid];
    int cusid;
    cout << "Which customer would you like? = ";
    cin >> cusid;
    sal[i].customer = cus[cusid];
    cout << "What is the amount =";
    cin >> sal[i].amount;
}

void display(Sale sal[], Employee emp[], Customer cus[], int cEmp, int cCus, int cSal)
{
    cout << "||EMPLOYEE||" << "\n";
    for (int i = 0; i < cEmp; i++)
    {
        cout << "Employee number " << i << "\n";
        cout << "Employee name = " << emp[i].name << "\n";
        cout << "Employee Salary = " << emp[i].salary << "\n";
    }
    cout << "||CUSTOMER||" << "\n";
    for (int i = 0; i < cCus; i++)
    {
        cout << "Customer number " << i << "\n";
        cout << "Customer name = " << cus[i].name << "\n";
        cout << "Customer address = " << cus[i].address << "\n";
    }
    cout << "||SALES||" << "\n";
    for (int i = 0; i < cSal; i++)
    {
        cout << "Sales number " << i << "\n";
        cout << "Employee name " << sal[i].salerep.name << "\n";
        cout << "Employee Salary  " << sal[i].salerep.salary << "\n";
        cout << "Customer name " << sal[i].customer.name << "\n";
        cout << "Customer address " << sal[i].customer.address << "\n";
        cout << "Time-Stamp " << sal[i].dt << "\n";
    }
}

int main()
{
    int option;       // menu driven option
    bool flag = true; // flag for loop and menu driven;

    Employee obj1;          // object for employee class
    Employee employee[50];  // object array of employee
    Customer customers[50]; // object array of customers
    Sale sales[50];         // object array of sales
    int cEmp = 0;           // count for number of employee entry
    int cCus = 0;           // count for number of customer entry
    int cSal = 0;           // count for sales entry
    while (flag == true)    // loop for menu driven options
    {

        cout << "\n"
             << "Enter 1.add Employees/2.add Customer/3.add Sales/4.to Exit/5.display ";
        cin >> option;
        switch (option)
        {
        case 1:
            int num; // number of employees
            cout << "How many employees to add= ";
            cin >> num;
            cEmp = cEmp + num;
            for (int i = 0; i < num; i++)
            {
                addEmployees(employee, i);
            }
            break;
        case 2:
            int num1; // number of customers

            cout << "How many customers to add= ";
            cin >> num1;
            cCus = cCus + num;
            for (int i = 0; i < num1; i++)
            {
                addCustomer(customers, i);
            }
            break;
        case 3:
            int num2; // number of customers
            cout << "How many sales to add= ";
            cin >> num2;
            cSal = cSal + num2;
            for (int i = 0; i < num2; i++)
            {
                addSales(sales, i, employee, customers);
            }
            break;
        case 4:
            flag = false;
            break;
        case 5:
            display(sales, employee, customers, cEmp, cCus, cSal);
            break;

        default:
            cout << "Wrong option please enter again.";
        }
    }
}

// COULD NOT SERIALIZE AS I COULD NOT RECALL ON HOW TO DO IT