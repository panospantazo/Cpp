#include <iostream>
#include "HUMANOID.h"
using namespace std;

humanoid::humanoid()
{
    health = 100;
}

humanoid &humanoid::operator-=(const int &in_health)
{
    health -= in_health;
    if(health < 0)
    {
        health = 0;
        cout << "Humanoid Dead!" << endl;
        
    }
    else
        cout << "Humanoids's Health:" << health << endl;
    return *this;
}

int humanoid::attack()
{
    return (1 + rand() % 5);
}

bool humanoid::check_dead()
{
    if(health == 0)
        return true;
    else
        return false; 
}