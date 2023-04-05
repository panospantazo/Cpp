#include <iostream>
#include <cstring>
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

void make_help_arr(char **);
void make_help_arr_2(char **);
void make_help_arr_3(char **);
void change_semester(foititis, foititis , foititis);

int main(void)
{
    char* help_arr = NULL;

    make_help_arr(&help_arr);

    foititis panagiotis(help_arr,"Panagiotis Pantazopoulos");
    panagiotis.print();
    
    foititis xarhs(help_arr,"Xarhs Sotiriou",2);
    xarhs.print();

    foititis nefeli = panagiotis;
    nefeli.print();
    
    make_help_arr_3(&help_arr);
    
    nefeli.set_foititi_AM(help_arr);
    delete [] help_arr;
    nefeli.set_foititi_name("Nefeli Argiropoulou");
    nefeli.set_foititi_semester(5);
    nefeli.print();

    cout << "End of Exams" << endl;
    cout<< "-------------" << endl;
    panagiotis++;
    xarhs++;
    nefeli++;

    cout << "|The tabs of the students after exams|" << endl;

    panagiotis.print();
    xarhs.print();
    nefeli.print();

    change_semester(panagiotis,xarhs,nefeli);
    return 0;
}

void change_semester(foititis panagiotis,foititis xarhs,foititis nefeli)
{
    string answer;
    int s;
    cout << "Who wants to change his semester? Panagiotis/Xarhs/Nefeli" << endl;
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
    else if (answer == "Xarhs" && s == 2)
    {
        xarhs -=1; 
        xarhs.print();
    }
    else if(answer == "Nefeli" && s == 1)
    {
        nefeli += 1;
        nefeli.print();
    }
    else
    {
        nefeli -= 1;
        nefeli.print();
    }

}

void make_help_arr(char **help_arr)
{
    if(*help_arr != NULL)
    {
        delete [] *help_arr;
    }
    *help_arr = new char [25]{'2','2','3','9','0','1','7','4'};

}

void make_help_arr_2(char **help_arr)
{
    if(*help_arr != NULL)
    {
        delete [] *help_arr;
    }
    *help_arr = new char [25]{'2','2','3','9','0','0','5','2'};
}

void make_help_arr_3(char **help_arr)
{
    if(*help_arr != NULL)
    {
        delete [] *help_arr;
    }
    *help_arr = new char [25]{'2','2','3','9','0','1','3','1'};
}

foititis::foititis()
{
    AM = NULL;
    semester = 0;
    name = "";
}

foititis::foititis(char *in_AM,string in_name)
{
    AM = new char[strlen(in_AM) + 1];
    strcpy(AM,in_AM);
    name = in_name;
    semester = 1;    
}

foititis::foititis(char *in_AM,string in_name,int in_semester)
{
    AM = new char[strlen(AM) + 1];
    strcpy(AM,in_AM);
    name = in_name;
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
    
    cout << "|Name: " << name <<"|"<< "AM: " << AM <<"|"<< "Semester: " << semester <<"|"<< endl << endl;
   
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
