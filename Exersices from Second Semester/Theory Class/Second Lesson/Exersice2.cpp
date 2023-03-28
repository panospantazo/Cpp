//Exersice 2 Lesson 1

#include <iostream>
using namespace std;

class Student
{
    public:
        void setName(string n)
        {
            name = n;
        }

        void setAge(int a)
        {
            age = a;
        }
        
        void setID(int i)
        {
            id = i;
        }

        string getName()
        {
            return name;
        }

        int getAge()
        {
            return age;
        }

        int getId()
        {
            return id;
        }

    private:
        string name;
        int age;
        int id;
        
};

int main(void)
{
    Student s1;
    s1.setName("Christos");
    s1.setAge(25);
    s1.setID(1312);
    cout << "Name:" << s1.getName() << endl;
    cout << "Age:" << s1.getAge() << endl;
    cout << "Id:" << s1.getId() << endl;

    s1.setName("Nikos");
    cout << "New Name:" << s1.getName() << endl;


    return 0;
}