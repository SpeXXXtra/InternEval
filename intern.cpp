// general stream
//  write a class
//  create object of each class
//  serilize these objects into a file
//  read the file
//  deserilize the object
#include <string.h>
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

void serializeEmp(Employee emp[], int i)
{

    ofstream myfile("Employee.txt", ios::app);
    myfile << "!! Employee number " << i << " !!" << "\n";
    myfile << emp[i].name << "\n";
    myfile << emp[i].salary << "\n";
    myfile.close();
}

void addEmployees(Employee emp[], int i, int indexEmp)
{
    Employee obj1; // object for employee class
    i = indexEmp + i;
    cout << "Enter the name of the employee =" << "\n";
    cin >> obj1.name;
    emp[i].name = obj1.name;
    cout << "Enter the Salary of the employee = ";
    cin >> obj1.salary;
    emp[i].salary = obj1.salary;
    serializeEmp(emp, i);
}

void serializeCus(Customer cus[], int i)
{
    ofstream myfile("Customer.txt", ios::app);
    myfile << "!! Customer number " << i << " !!" << "\n";
    myfile << cus[i].name << "\n";
    myfile << cus[i].address << "\n";
    myfile.close();
}

void addCustomer(Customer cus[], int i, int indexCus)
{

    Customer obj1; // object for employee class
    i = indexCus + i;
    cout << "Enter the name of the customer =" << "\n";
    cin >> obj1.name;
    cus[i].name = obj1.name;
    cout << "Enter the address of the customer = ";
    cin >> obj1.address;
    cus[i].address = obj1.address;
    serializeCus(cus, i);
}

void serializeSal(Sale sal[], int i, Employee emp[], Customer cus[])
{
    ofstream myfile("Sales.txt", ios::app);
    myfile << "!! Sales number " << i << " !!" << "\n";
    myfile << "Employee name = " << emp[i].name << "\n";
    myfile << "Customer name =" << cus[i].name << "\n";
    myfile << "Amount = " << sal[i].amount << "\n";
    myfile << sal[i].dt << "\n";
    myfile.close();
}
void addSales(Sale sal[], int i, Employee emp[], Customer cus[], int indexSal)
{
    Sale obj1;
    int empid;
    indexSal = i + indexSal;
    cout << "Which employee would you like? = ";
    cin >> empid;
    sal[i].salerep = emp[empid];
    int cusid;
    cout << "Which customer would you like? = ";
    cin >> cusid;
    sal[i].customer = cus[cusid];
    cout << "What is the amount =";
    cin >> sal[i].amount;
    serializeSal(sal, i, emp, cus);
}

// void display(Sale sal[], Employee emp[], Customer cus[], int cEmp, int cCus, int cSal)
// {
//     cout << "||EMPLOYEE||" << "\n";
//     for (int i = 0; i < cEmp; i++)
//     {
//         cout << "Employee number " << i << "\n";
//         cout << "Employee name = " << emp[i].name << "\n";
//         cout << "Employee Salary = " << emp[i].salary << "\n";
//     }
//     cout << "||CUSTOMER||" << "\n";
//     for (int i = 0; i < cCus; i++)
//     {
//         cout << "Customer number " << i << "\n";
//         cout << "Customer name = " << cus[i].name << "\n";
//         cout << "Customer address = " << cus[i].address << "\n";
//     }
//     cout << "||SALES||" << "\n";
//     for (int i = 0; i < cSal; i++)
//     {
//         cout << "Sales number " << i << "\n";
//         cout << "Employee name " << sal[i].salerep.name << "\n";
//         cout << "Employee Salary  " << sal[i].salerep.salary << "\n";
//         cout << "Customer name " << sal[i].customer.name << "\n";
//         cout << "Customer address " << sal[i].customer.address << "\n";
//         cout << "Time-Stamp " << sal[i].dt << "\n";
//     }
// }

void deserialize(int n)
{
    int num = n;
    if (num == 1)
    {
        ifstream myFile("Employee.txt");
        string line;
        cout << "File Content: " << endl;
        while (getline(myFile, line))
        {
            cout << line << endl;
        }

        myFile.close();
    }
    else if (num == 2)
    {
        ifstream myFile("Customer.txt");
        string line;
        cout << "File Content: " << endl;
        while (getline(myFile, line))
        {
            cout << line << endl;
        }
    }
    else if (num == 3)
    {
        ifstream myFile("Sales.txt");
        string line;
        cout << "File Content: " << endl;
        while (getline(myFile, line))
        {
            cout << line << endl;
        }
    }
}

int main()
{

    string deserialArray[1000];
    int option;             // menu driven option
    bool flag = true;       // flag for loop and menu driven;
    Employee obj1;          // object for employee class
    Employee employee[50];  // object array of employee
    Customer customers[50]; // object array of customers
    Sale sales[50];         // object array of sales
    int cEmp = 0;           // count for number of employee entry
    int cCus = 0;           // count for number of customer entry
    int cSal = 0;           // count for sales entry
    int indexEmp = 0;
    int indexCus = 0;
    int indexSal = 0;
    while (flag == true) // loop for menu driven options
    {

        cout << "\n"
             << "Enter 1.add Employees/2.add Customer/3.add Sales/4.to Exit/5.Deserialize = ";
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
                addEmployees(employee, i, indexEmp);
            }
            indexEmp = indexEmp + num;
            break;
        case 2:
            int num1; // number of customers

            cout << "How many customers to add= ";
            cin >> num1;
            cCus = cCus + num;
            for (int i = 0; i < num1; i++)
            {
                addCustomer(customers, i, indexCus);
            }
            indexCus = indexCus + num;
            break;
        case 3:
            int num2; // number of customers
            cout << "How many sales to add= ";
            cin >> num2;
            cSal = cSal + num2;
            for (int i = 0; i < num2; i++)
            {
                addSales(sales, i, employee, customers, indexSal);
            }
            indexSal = indexSal + num;
            break;
        case 4:
            flag = false;
            break;
            // case 5:
            //     display(sales, employee, customers, cEmp, cCus, cSal);
            //     break;
        case 5:
            int nom;
            cout << "Enter number to deserialize 1.Employee/2.Customer/3.Sales =";
            cin >> nom;
            deserialize(nom);
            break;

        default:
            cout << "Wrong option please enter again.";
        }
    }
}
