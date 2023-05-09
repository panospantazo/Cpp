#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "WIZARD.cpp"
#include "HUMANOID.cpp"
using namespace std;


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
