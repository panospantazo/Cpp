#include <string>
#include <vector>
#include "subject.h"
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
        const char* get_student_AM();

        void set_student_semester(int);
        void set_student_name(string);
        void set_student_AM(char *);
    

        void change_semester(bool);

		student &operator=(const student &right);
		student &operator+=(subject &);
        student operator+=(const int);
        student operator-=(const int);
        void operator++ (const int);
        
        int sign_subj(vector <subject>&,ostream &);
        
        friend ostream &operator<<(ostream &,student &);
    private:
        char *AM;
        string name;
        unsigned int semester;
        vector <float> grades;
        vector <subject> classes_passed;
        vector <subject> classes;
};

