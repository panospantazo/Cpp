#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

class student
{
    public:
        student();
        student(char*,string);
        student(char*,string,int);
        student(const student &);
        
        ~student();
        
        unsigned int get_student_semester();
        string get_student_name();
        char* get_student_AM();

        void set_student_semester(int);
        void set_student_name(string);
        void set_student_AM(char *);
    
        void print(ostream &);
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
void delete_help_arr(char **);
void make_help_arr_2(char **);
void make_help_arr_3(char **);
void change_semester(student &,student &, student &, ostream &);

int main(void)
{

    srand(time(NULL));

    char* help_arr = NULL;

    make_help_arr(&help_arr);

    student panagiotis(help_arr,"Panagiotis Pantazopoulos");
    panagiotis.print(cout);
    
    make_help_arr(&help_arr);
    
    student xarhs(help_arr,"Xarhs Sotiriou",2);
    xarhs.print(cout);

    student nefeli = panagiotis;
    nefeli.print(cout);
    
    make_help_arr(&help_arr);
    
    nefeli.set_student_AM(help_arr);
    delete_help_arr(&help_arr);
    nefeli.set_student_name("Nefeli Argiropoulou");
    nefeli.set_student_semester(5);
    nefeli.print(cout);

    cout << "End of Exams" << endl;
    cout<< "-------------" << endl;
    panagiotis++;
    xarhs++;
    nefeli++;

    cout << "|The tabs of the students after exams|" << endl;

    panagiotis.print(cout);
    xarhs.print(cout);
    nefeli.print(cout);

    change_semester(panagiotis,xarhs,nefeli,cout);

    panagiotis.print(cout);
    xarhs.print(cout);
    nefeli.print(cout);
    
    return 0;
}

void change_semester(student &panagiotis,student &xarhs,student &nefeli,ostream &k)
{
    string answer;
    int s;
    k << "Who wants to change his semester? Panagiotis/Xarhs/Nefeli" << endl;
    cin >> answer;
    k << "Press 1 for increase" << endl << "Press 2 for decrease" << endl;
    cin >> s;
    
    if(answer == "Panagiotis" && s == 1)
    {
        panagiotis+=1;
    }
    else if(answer == "Panagiotis" && s == 2)
    {
        panagiotis-=1;  
    }
    else if(answer == "Xarhs" && s == 1)
    {
        xarhs+=1;        
    }
    else if (answer == "Xarhs" && s == 2)
    {
        xarhs -=1; 
    }
    else if(answer == "Nefeli" && s == 1)
    {
        nefeli += 1;        
    }
    else
    {
        nefeli -= 1;
    }
}

void delete_help_arr(char **help_arr)
{
    delete [] *help_arr;
}

void make_help_arr(char **help_arr)
{
    if(*help_arr != NULL)
    {
        delete [] *help_arr;
    }
    *help_arr = new char [25]{'2','2','3','9','0','1','7','4','\0'}; 
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

student::student()
{
    AM = NULL;
    semester = 0;
    name = "";
}

student::student(char *in_AM,string in_name)
{
    AM = new char[strlen(in_AM) + 1];
    strcpy(AM,in_AM);
    name = in_name;
    semester = 1;    
}

student::student(char *in_AM,string in_name,int in_semester)
{
    AM = new char[strlen(in_AM) + 1];
    strcpy(AM,in_AM);
    name = in_name;
    semester = in_semester;
}

student::student(const student &in_student)
{
    AM = new char [strlen(in_student.AM + 1)];
    strcpy(AM,in_student.AM);
    name = in_student.name;
    semester = in_student.semester;
}

unsigned int student::get_student_semester()
{
    return semester;
}

string student::get_student_name()
{
    return name;
}

char* student::get_student_AM()
{
    return AM;
}

student::~student()
{
    delete [] AM;
}

void student::set_student_semester(int in_semester)
{
    semester = in_semester;
}

void student::set_student_name(string in_name)
{
    name = in_name;
}

void student::set_student_AM(char * in_AM)
{
    if(AM != NULL)
    {
        delete [] AM;
    }

    AM = new char [strlen(in_AM) + 1];
    if(!AM)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(AM,in_AM);
}

void student::print(ostream &k)
{
    
    k << "|Name: " << name <<"|"<< "AM: " << AM <<"|"<< "Semester: " << semester <<"|"<< endl << endl;
   
} 

void student::change_semester(bool a)
{
    if(a == true)
        semester += 1;
    else
        semester -= 1;
    
}

void student::operator+=(const int right)
{
    semester = semester + right;
}

void student::operator-=(const int right)
{
    semester = semester - right;
}

void student::operator++(const int b) 
{
    student tmp = *this;
    semester = semester + 1;
    return tmp;
}
