#include <string>
#include <vector>
#include "subject.h"
#ifndef CLASSSTUDENT_H
#define CLASSSTUDENT_H
using namespace std;

float roundNumber(float );

class student
{
    public:
    	
    	//Constructors
    	
        student(char*,string);
        student(char*,string,int);
        student(const student &);
        
        //Destructors
        
        ~student();
        
        //Getters
        
        unsigned int get_student_semester();
        string get_student_name();
        const char* get_student_AM();

		//Setters

        void set_student_semester(int);
        void set_student_name(string);
        void set_student_AM(char *);
    
		//Αλλαγή Εξαμήνου

        void change_semester(bool);
        
        //Υπερφορτώσεις

		student &operator=(const student &);
		student &operator+=(subject &);
        student &operator+=(const int);
        student &operator-=(const int);
        student &operator++ (const int);
        
		bool operator==(const student &);
        bool operator>=(const student &);
        bool operator<=(const student &);
        bool operator<(const student &);
        bool operator>(const student &);
        bool operator!=(const student &);
        
        friend ostream &operator<<(ostream &,student &);
        
        
        int sign_subj(vector <subject>&,ostream &);
        int passed_subj(vector <subject>&,ostream &);
        
        friend float roundNumber(float );
        
        
    private:
        char *AM;
        string name;
        unsigned int semester;
        vector <float> grades;
        vector <subject> classes_passed;
        vector <subject> classes;
};

#endif

