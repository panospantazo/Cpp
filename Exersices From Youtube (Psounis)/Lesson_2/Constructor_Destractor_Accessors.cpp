//Learning Constructor,Destractor and Accessors
#include <iostream>
using namespace std;

class human
{
    public:
        void checks_mood_dog();
        void demand_bark();
};


class dog
{
    public:
        void bark();
        ~dog();                     //Destractor
        void set_mood(int in_mood); //setter
        int get_mood() const;       //getter
        void report_mood();
        dog(int in_mood);            //Constructor
    

    private:
        int mood;
};

int main(void)
{
    human owner;
    
    dog azor(3);                //Constructor
    owner.checks_mood_dog();
    azor.report_mood();     
    owner.demand_bark();
    azor.bark();
    azor.bark();
    
    return 0;
}

void dog::bark()
{
      cout << "bark" << endl;
}

dog::~dog()
{
    cout << "I will be waiting...";
}

void dog::report_mood()
{
         if(mood>5)
         {
                cout << "I am cool" << endl;
         }
        else
         {
                cout << "I am furious" << endl;
         }
}

void dog::set_mood(int in_mood)
{
    mood = in_mood;
}

int dog::get_mood() const
{
    return mood;
}

dog::dog(int in_mood)
{
    mood = in_mood;
}

void human::checks_mood_dog()
{
    cout << "How are you azor?" << endl;
}

void human::demand_bark()
{
     cout <<"Azor, please bark twice for me" << endl;
}