#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class student
{
    public:
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

        student operator+=(const int);
        student operator-=(const int);
        void operator++ (const int);

    private:
        char *AM;
        string name;
        unsigned int semester;
};

void delete_help_arr(char **);
void make_help_arr(char *&, const char *);
void increase_semester(student &,student &, student &);
void decrease_semester(student &,student &, student &);
void semester_after_exams(student &,student &,student &);

int main(void)
{    
    //Creating students with Constructor,Copy Constructor and setters

    char* help_arr = NULL;
    
    
    cout << endl << "Creating Students" << endl;
    cout << "-----------------------" << endl;

    make_help_arr(help_arr,"22390174");

    student panagiotis(help_arr,"Pantazopoulos Panagiotis");
    
	panagiotis.print(cout);
    
    make_help_arr(help_arr,"22390052");
    
    student xarhs(help_arr,"Xarhs Sotiriou",2);
    xarhs.print(cout);

    student nefeli = panagiotis;
    nefeli.print(cout);
    
    make_help_arr(help_arr,"22390131");
    
    nefeli.set_student_AM(help_arr);
    delete_help_arr(&help_arr);
    nefeli.set_student_name("Nefeli Argiropoulou");
    nefeli.set_student_semester(5);
    nefeli.print(cout);

    //Increasing semester with ++

    cout << "End of Exams" << endl;
    cout<< "-------------" << endl;
    
    semester_after_exams(panagiotis,xarhs,nefeli);

    cout << "|Tabs of Students|" << endl;
    cout << "------------------" << endl;

    panagiotis.print(cout);
    xarhs.print(cout);
    nefeli.print(cout);

    // Increasing semester with +=

    cout << "Increasing Semester..." << endl;
    cout << "----------------------" << endl;
    increase_semester(panagiotis,xarhs,nefeli);

    panagiotis.print(cout);
    xarhs.print(cout);
    nefeli.print(cout);

    //Decreasing semester with -=

    cout << "Decreasing Semester..." << endl;
    cout << "----------------------" << endl;
    decrease_semester(panagiotis,xarhs,nefeli);

    panagiotis.print(cout);
    xarhs.print(cout);
    nefeli.print(cout);
    
    return 0;
}

//Increasing semester function (+=)

void increase_semester(student &panagiotis,student &xarhs, student &nefeli)
{
    panagiotis += 1;
    xarhs += 1;
    nefeli += 1;
}

//Decreasing semester function (-=)

void decrease_semester(student &panagiotis,student &xarhs, student &nefeli)
{
    panagiotis -= 1;
    xarhs -= 1;
    nefeli -= 1;
}

//Increasing semester function (++)

void semester_after_exams(student &panagiotis,student &xarhs,student &nefeli)
{
    panagiotis++;
    xarhs++;
    nefeli++;
}

//Deleting help array

void delete_help_arr(char **help_arr)
{
    delete [] *help_arr;
}

//Proccesing helping array

void make_help_arr(char *&help_arr,const char *AM)
{
  int len = strlen(AM);
  help_arr = new char [len + 1];
  strcpy (help_arr, AM);
}

//Constructor with AM and Name as parametres

student::student(char *in_AM,string in_name)
{
    AM = new char[strlen(in_AM) + 1];
    strcpy(AM,in_AM);
    name = in_name;
    semester = 1;    
}

//Constructor with AM,Name and semester as parametres

student::student(char *in_AM,string in_name,int in_semester)
{
    AM = new char[strlen(in_AM) + 1];
    strcpy(AM,in_AM);
    name = in_name;
    semester = in_semester;
}

//Copy Constructor

student::student(const student &in_student)
{
    AM = new char [strlen(in_student.AM + 1)];
    strcpy(AM,in_student.AM);
    name = in_student.name;
    semester = in_student.semester;
}

//Semester getter

unsigned int student::get_student_semester()
{
    return semester;
}

//Name getter

string student::get_student_name()
{
    return name;
}

//AM getter

char* student::get_student_AM()
{
    return AM;
}

//Destructor

student::~student()
{
    delete [] AM;
}

//Setter of student's semester

void student::set_student_semester(int in_semester)
{
    semester = in_semester;
}

//Setter of student's name

void student::set_student_name(string in_name)
{
    name = in_name;
}

//Setter of AM

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

//Overloading +=

student student::operator+=(const int right)
{
    semester = semester + right;
    return *this;
}

//Overloading -=

student student::operator-=(const int right)
{
    semester = semester - right;
    return *this;
}

//Overloading ++

void student::operator++(const int b) 
{
    semester = semester + 1;
}
