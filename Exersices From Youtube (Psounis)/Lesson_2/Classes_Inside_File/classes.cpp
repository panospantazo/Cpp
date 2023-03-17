#include <iostream>
#include "classes.h"
using namespace std;

void dog::bark()
{
      cout << "bark" << endl;
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

void human::checks_mood_dog()
{
    cout << "How are you azor?" << endl;
}

void human::demand_bark()
{
     cout <<"Azor, please bark twice for me" << endl;
}