#include <iostream>
#include <cstdlib>
#include <cstring>
#define size 9
using namespace std;

class foititis
{
    public:
        foititis();
        foititis(int);
        foititis(const foititis &in_foit);
        ~foititis();
        
        unsigned int get_foititi_semester();
        string get_foititi_name();
        char* get_foititi_AM();

        void set_foititi_semester(int);
        void set_foititi_name(string);
        void set_foititi_AM(char *);
    
        void print();
        void change_semester(bool);
    private:
        char *AM;
        string name;
        unsigned int semester;
};

int main(void)
{
    foititis mpotis;
    bool a = true;
    string answer;
    
    cout << "Wanna increase or decrease semester?";
    cin >> answer;
    if(answer == "increase")
    {
        mpotis.change_semester(a);
    }
    else
    {
        a = false;
        mpotis.change_semester(a);
    }
    mpotis.print();

    return 0;
}

foititis::foititis()
{
    AM = new char[size]{'2','2','3','9','0','1','7','4'};
    if(!AM)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    name = "Pantazopoulos Panagiotis";
    semester = 1;    
}

foititis::foititis(int in_semester)
{
    AM = new char[size]{'2','2','3','9','0','1','7','4'};
    name = "Pantazopoulos Panagiotis";
}

foititis::foititis(const foititis &in_foit)
{
    AM = in_foit.AM;
    name = in_foit.name;
    semester = in_foit.semester;
}

unsigned int foititis::get_foititi_semester()
{
    return semester;
}

string foititis::get_foititi_name()
{
    return name;
}

char*  foititis::get_foititi_AM()
{
    return &AM[0];
}

foititis::~foititis()
{
    delete [] AM;
}

void foititis::set_foititi_semester(int in_semester)
{
    semester = in_semester;
}

void foititis::set_foititi_name(string in_name)
{
    name = in_name;
}

void foititis::set_foititi_AM(char * in_AM)
{
    strcpy(AM,in_AM);
}

void foititis::print()
{
    //cout << "Name: " << name << endl << "AM: " << AM << endl << "Semester: " << semester << endl;
    cout << "Semester: " << semester << endl;
} 

void foititis::change_semester(bool a)
{
    if(a == true)
        semester += 1;
    else
        semester -= 1;
    
}