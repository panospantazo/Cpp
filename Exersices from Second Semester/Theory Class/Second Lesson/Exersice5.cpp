//Exersice 5 Lesson 2

#include <iostream>
using namespace std;

class Employee
{
    public:
        Employee(string name,double salary)
        {
            this->name=name;
            this->salary=salary;
        }
        friend class Manager;


    private:
        string name;
        double salary;


};

class Manager
{
    public:
        void display(Employee emp)
        {
            cout << "Name:" << emp.name << endl;
            cout << "Salary:" << emp.salary << endl;
        }
};

int main(void)
{
    Employee emp("Christos",100);
    Manager ngr;
    ngr.display(emp);  
}