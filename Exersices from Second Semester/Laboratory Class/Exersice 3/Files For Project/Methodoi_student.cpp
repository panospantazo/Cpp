#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

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

const char* student::get_student_AM()
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
        cout << "Αδυναμία Δέσμευσης Μνήμης" << endl;
        exit(1312);
    }
    strcpy(AM,in_AM);
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

//Overloading <<

ostream &operator<<(ostream &left, student &right) {
    int i;
    float sum = 0;
    
    left << "|Όνομα: " << right.get_student_name() <<"|"<< "ΑΜ: " << right.get_student_AM() <<"|"<< "Εξάμηνο: " << right.get_student_semester() <<"|"<< endl << endl;

    left << "|--------------------|" << endl;
    left << "|YOUR CURRENT CLASSES|" << endl;
    left << "|--------------------|" << endl;
    for (i = 0; i < right.classes.size(); i++) 
    {
        left << "Your " << i + 1 << "st class is: " << right.classes[i].get_subject_lektiko() << endl << endl;
    }

    left << endl << "|------------------|" << endl;
    left << "|THE PASSED CLASSES|" << endl;
    left << "|------------------|" << endl;
    
    for (i = 0; i <right.grades.size(); i++) 
    {
        left << "You passed " << right.classes_passed[i].get_subject_lektiko() << " class with grade " << right.grades[i] << endl << endl;
    }

    left << endl << "|------------------|" << endl;
    left << "|YOUR AVERAGE GRADE|" << endl;
    left << "|------------------|" << endl;
    
    for (i = 0; i <right.grades.size(); i++) 
    {
       sum += right.grades[i];
    }
    if(sum == 0)
    {
         left << endl <<"You haven't passed any subject yet" << endl;
    }
    else
    {
        left << endl <<"Your average grade is " << sum << endl;
    }

    return left;
}

student &student::operator+=(subject &right)
{	
    this->classes.push_back(right);

    return *this;
}

int student::sign_subj(vector<subject>& vec, ostream& left)
{
    int i, lesson = -1;
    string sub_name;
    bool toggle = false, F = false, K = false;
    
    

    left << "Δώσε το μάθημα που θες να δηλώσεις: ";

    cin.ignore();
    getline(cin, sub_name);
    
    
	for (i = 0; i < vec.size(); i++)
    {
        if (sub_name == vec[i].get_subject_lektiko())
        {
            lesson = i;
            toggle = true;
            break;
        }
    }
    
    if(vec[lesson].get_subject_season() == false)
	{
		cout << "Μπορείς να επιλέξεις μόνο μαθήματα Εαρινού Εξαμήνου" << endl;
		return 0;
	}
    

    if (toggle)
    {
		for (i = 0; i < this->classes.size(); i++)
        {
            if (this->classes[i].get_subject_lektiko() == sub_name)
        	{
                F = true;
                break;
    		}
        }
        if (F)
        {
            left << "Έχεις ήδη γραφτεί στο συγκεκριμένο μάθημα" << endl;
        }

        for (i = 0; i < this->classes_passed.size(); i++)
        {
            if (this->classes_passed[i].get_subject_lektiko() == sub_name)
            {
                K = true;
                break;
        	}
        }
        if (K)
        {
            left << "Έχεις ήδη περάσει το συγκεκριμένο μάθημα" << endl;
        }
    }
    else
    {
        left << "Δεν βρέθηκε το μάθημα που ψάχνεις στον κατάλογο των μαθημάτων" << endl;
        return 0;
    }
    
    
    if (K == false && F == false)
    {
    	return lesson;
    }
    else
	{
    	return 0;	
	}
}

student& student::operator=(const student& right)
{
    if (this == &right) 
	{
        return *this;
    }

    if (AM != NULL) 
	{
        delete[] AM;
    }
    
	AM = new char[strlen(right.AM + 1)];
    if (!AM) 
	{
        cout << "Memory allocation failed" << endl;
    }

    strcpy(AM, right.AM);

    name = right.name;

    semester = right.semester;

    grades = right.grades;

    classes_passed = right.classes_passed;

    classes = right.classes;

    return *this;
}


