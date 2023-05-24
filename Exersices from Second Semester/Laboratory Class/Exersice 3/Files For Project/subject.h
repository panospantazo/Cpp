#include <string>
#ifndef CLASSSUBJECT_H
#define CLASSSUBJECT_H
using namespace std;

class subject
{
    public:
        //Setters

        void set_subject_password(string);
        void set_subject_lektiko(string);
        void set_subject_hours(unsigned int);
        void set_subject_season(bool);

        //Getters
        
        string get_subject_password() const;
        string get_subject_lektiko() const;
        unsigned int get_subject_hours() const;
        bool get_subject_season() const;
    
        friend ostream &operator<<(ostream &,subject &);
    private:
        string password;
        string lektiko;
        unsigned int hours;
        bool season;
};

#endif
