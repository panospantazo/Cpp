//Learning to put classes's functions outside classes
#include <iostream>
#include "classes.cpp"


using namespace std;


int main(void)
{
    dog azor;
    human owner;
    
    azor.set_mood(3);
    owner.checks_mood_dog();
    azor.report_mood();
    owner.demand_bark();
    azor.bark();
    azor.bark();
    return 0;
}



