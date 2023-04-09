#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class demidog
{
    public:
        demidog();
        int attack();
    private:
        int health;
};

class demigordon
{
    public:
        demigordon();
        int attack();
    private: 
        int height;
        int weight;
        int health;

};

class hive
{
    public:
        hive(bool);
        int attack();
    private:
        demidog *arr;
        demigordon *boss;
        int in_demidogs;
};

int main(void)
{
    srand(time(NULL));
    int dmg=0;
    
    hive dungeon(true);
    dmg = dungeon.attack();
    cout << "The Damage done by the hive is: " << dmg << endl;
    
    
    return 0;
}

int hive::attack()
{
    int sum_dmg = 0;
    if(boss != NULL)
    {
        sum_dmg += boss->attack();
        cout << endl << "Demigordon attacks! (damage: "<< sum_dmg <<")"<<endl;
    }
    for(int i = 0;i<in_demidogs;i++)
    {
        int demidog_dmg = 0;
        demidog_dmg = arr[i].attack();
        cout << i << "Demidog attacks! (damage: " << demidog_dmg <<")"<<endl;
        sum_dmg += demidog_dmg;
    }
    return sum_dmg;
}


hive::hive(bool check_boss)
{
    int demidogs = 10+rand()%41;
    arr = new demidog [demidogs];
    if(!arr)
    {
        cout << "Error Allocating Memory!" << endl;
        exit(1312);
    }
    in_demidogs = demidogs;
    if(check_boss)
    {
        boss = new demigordon;
        if(!boss)
        {
            cout << "Error Allocating Memory" << endl;
            exit (1312);
        }
    }
    else
    {
        boss = NULL;
    } 
}


demigordon::demigordon()
{
    height = 5;
    weight = 500;
    health = 10000;
}

int demigordon::attack()
{
    return (300+rand()%201);
}



demidog::demidog()
{
    health = 100;
}

int demidog::attack()
{
    return (10+rand()%41);
}