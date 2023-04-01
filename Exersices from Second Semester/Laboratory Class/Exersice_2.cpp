#include <iostream>
#include <cstdlib>
#include <cstring>
#define size 9
using namespace std;

class foititis
{
    public:
        foititis();
        foititis(char*,string);
        foititis(char*,string,int);
        foititis(const foititis &);
        
        ~foititis();
        
        unsigned int get_foititi_semester();
        string get_foititi_name();
        char* get_foititi_AM();

        void set_foititi_semester(int);
        void set_foititi_name(string);
        void set_foititi_AM(char *);
    
        void print();
        void change_semester(bool);
        void operator+=(const int);
        void operator-=(const int);
        void operator++ (const int b);

    private:
        char *AM;
        string name;
        unsigned int semester;
};

int main(void)
{
    char* help_arr;
    string answer;
    int s;
    help_arr = new char [size]{'2','2','3','9','0','1','7','4'};
    if(!help_arr)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    foititis panagiotis(help_arr,"Panagiotis Pantazopoulos");
    panagiotis.print();
    
    
    foititis xarhs;
    xarhs = panagiotis;
    delete [] help_arr;

    help_arr = new char [size]{'2','2','3','9','0','0','5','2'};    
    if(!help_arr)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    
    xarhs.set_foititi_AM(help_arr);
    delete [] help_arr;
    xarhs.set_foititi_name("Xarhs Kotsidopoulos");
    xarhs.set_foititi_semester(2);
    xarhs.print();

    cout << "End of Exams" << endl;
    panagiotis++;
    xarhs++;

    panagiotis.print();
    xarhs.print();

    cout << "Who wants to change his semester? Panagiotis/Xarhs" << endl;
    cin >> answer;
    cout<< "Press 1 for increase" << endl << "Press 2 for decrease" << endl;
    cin >> s;
    
    if(answer == "Panagiotis" && s == 1)
    {
        panagiotis+=1;
        panagiotis.print();
    }
    else if(answer == "Panagiotis" && s == 2)
    {
        panagiotis-=1;
        panagiotis.print();
    }
    else if(answer == "Xarhs" && s == 1)
    {
        xarhs+=1;
        xarhs.print();
    }
    else
    {
        xarhs -=1; 
        xarhs.print();
    }

    return 0;
}

foititis::foititis()
{
    AM = NULL;
    semester = 0;
    name = "";
}

foititis::foititis(char *in_AM,string in_name)
{
    AM = new char[size];
    if(!AM)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(AM,in_AM);
    name = in_name;
    semester = 1;    
}

foititis::foititis(char *in_AM,string name,int in_semester)
{
    AM = new char[strlen(AM)];
    if(!AM)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(AM,in_AM);
    name = "Pantazopoulos Panagiotis";
    semester = in_semester;
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

char* foititis::get_foititi_AM()
{
    return AM;
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
    cout << "-------------------------"<<endl;
    cout << "Name: " << name << endl << "AM: " << AM << endl << "Semester: " << semester << endl;
    cout << "-------------------------"<<endl;
} 

void foititis::change_semester(bool a)
{
    if(a == true)
        semester += 1;
    else
        semester -= 1;
    
}

void foititis::operator+=(const int right)
{
    semester = semester + right;
}

void foititis::operator-=(const int right)
{
    semester = semester - right;
}

void foititis::operator++(const int b) 
{
    semester = semester + 1;
}
