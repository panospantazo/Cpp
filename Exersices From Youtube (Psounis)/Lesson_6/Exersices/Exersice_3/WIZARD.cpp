#include <iostream>
#include <cstring>
#include "WIZARD.h"
using namespace std;

void wizard::print()
{
    cout << health;
}



wizard::wizard(int in_age,char* in_beard,int in_mana,int in_health)
{
    age = in_age;
    strcpy(beard,in_beard);
    mana = in_mana;
    health = in_health;
}

int wizard::fireball()
{
    
    if(mana >= 90)
    {
        mana -= 90;
        cout << endl << "Fireball! (mana:" << mana << ")" << endl;
        return 20+rand()%49;
    }
    else
    {
         cout << endl << "Fireball effort (not enough mana)" << endl;
         return 0;
    }
    
}
   

int wizard::lightning()
{
    if(mana >= 30)
    {
        mana -= 30;
        cout << endl << "Lightning! (mana:" << mana << ")" << endl;;
        return 10+rand() % 9;
    }
    else
    {
        cout << endl << "Lightning effort (not enough mana)" << endl;
        return 0;
    }
    
}

void wizard::wait()
{
    mana += 10;
    cout << endl << "Wait... (mana:" << mana << ")" << endl;
}

wizard &wizard::operator+=(const int &in_health)
{
    health += in_health;
    if(health > 100)
        health = 100;
    return *this;
}   

wizard &wizard::operator-=(const int &in_health)
{
    health -= in_health;
    if(health < 0)
    {
        health = 0;
        cout << "Wizard Dead!" << endl;
    }
    else
        cout << "Wizard's Health:" << health << endl;
    
    return *this;
}   

bool wizard::check_dead()
{
    if(health == 0)
        return true;
    else   
        return false;
}