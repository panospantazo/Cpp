#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

class wizard
{
    public:
        wizard(int ,char* ,int,int );
        int fireball();
        int lightning();
        void wait();
        wizard &operator+=(const int&);
        wizard &operator-=(const int&);
        void print();
        bool check_dead();
    private:
        int age;
        char beard[80];
        int mana;
        int health;  

};

class humanoid
{
    public:
        humanoid();
        humanoid &operator-=(const int&);
        int attack();
        bool check_dead();
    private:
        int health;

};

int main(void)
{
    srand(time(NULL));
    char *p;
    bool check;
    int damage,round = 1,spell,winner;
    p = new char [5]{'g','r','e','y'};
    wizard Gandalf(2022,p,100,100);
    delete [] p;
    humanoid Lakis;
    
    while(1)
    {
        damage = 0;
        spell = 0;
        
        cout << "------" << endl;
        cout << "Round"<< round <<endl;
        cout << "-------" << endl;
        cout << "Wizard's Turn" << endl;
        spell = 1+rand()%3;
        if(spell == 1)
        {
            damage = Gandalf.lightning();
            Lakis-=damage;
            if(Lakis.check_dead())
            {
                winner = 1;
                break;
            }
                
        }
        else 
        {
            damage = Gandalf.fireball();
            Lakis-=damage;
            if(Lakis.check_dead())
            {
                winner = 1;
                break;
            }
        }
        cout << "Humanoid's Turn" << endl;
        damage = Lakis.attack();
        Gandalf -= damage;
        if(Gandalf.check_dead())
        {
            winner = 0;
            break;
        } 
        Gandalf.wait();    
        round++;  
    }
    if(winner == 1)
        cout << "Wizard Wins!" << endl;
    else
        cout << "Humanoid Wins!" << endl;
    
    return 0;
}

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