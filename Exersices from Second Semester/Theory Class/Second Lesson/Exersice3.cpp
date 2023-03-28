//Exersice 3 Lesson 2

#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    public:
        Student(int id,const char*  name)
        {
            this ->id=id;
            this ->name=new char[strlen(name)+1];
            strcpy(this->name,name);
        }
        
        ~Student()
        {
            delete[] name;
        }
        
        int getId()
        {
            return id;
        }

        char* getName()
        {
            return name;
        }
    
    private:
        int id;
        char *name;

};

int main(void)
{
    Student s1(111,"Nikos");
    cout << "Id:" << s1.getId() << endl;
    cout << "Name:" << s1.getName() << endl;



    return 0;
}