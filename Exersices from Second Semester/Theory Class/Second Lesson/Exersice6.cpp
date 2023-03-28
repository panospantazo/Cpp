//Exersice 7 Lesson 2

#include <iostream>
using namespace std;

class Person
{
    public:
        inline void setName(string n)
        {
            name = n;
        }
        inline void setAge(int a)
        {
            age = a;
        }

        inline string getName()
        {
            return name;
        }

        inline int getAge()
        {
            return age;
        }


    private:
        string name;
        int age;
};

int main(void)
{
    Person p1;
    p1.setName("Christos");
    p1.setAge(25);


    return 0;
}