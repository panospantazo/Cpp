#include <iostream>
#include <cstring>
#include <cstdlib>
#define N 10
using namespace std;

int checks_spell(int );
int end_turn();


class wizard
{
    public:
        wizard(int ,char *,int );   //Constructor

        //Apperance
        void show_beard();
        void tell_age();

        //Magic Power 
        int give_mana() const;
        void take_mana(int );
        void magic_durability();


        //ACTIONS
        void fireball_spell();
        void lighting_spell();
        void magic_build_up();
   
    private:
        int age;
        int mana;
        char beard[N];

};


int main(void)
{
    char color[N] = "Grey";
    int spell = 0;
    int decision = 0;
    int cnt = 1;
    wizard Gandalf(2019,color,100);
    cout << "BATTLE ENCOUNTER" << endl;
        cout << "----------------" << endl;
        cout << "1.Lighting Spell" << endl;
        cout << "2.Fireball Spell" << endl;
        cout << "3.Magic build up" << endl;
        cout << "9.Update on mana" << endl;
        cout << "My next move is:" << endl;
        cin >> spell;
        checks_spell(spell);
    while (1)
    {
        if(cnt > 1)
        {
            cout << "Continue with another spell" << endl;
            cout << "----------------" << endl;
            cout << "1.Lighting Spell" << endl;
            cout << "2.Fireball Spell" << endl;
            cout << "3.Magic build up" << endl;
            cout << "9.Update on mana" << endl;
            cout << "My next move is:" << endl;
            cin >> spell;
            checks_spell(spell);    
        }
        switch(spell)
        {
            case 1: Gandalf.lighting_spell(); break;
        
            case 2: Gandalf.fireball_spell(); break;

            case 3: Gandalf.magic_build_up(); break;

            case 9: Gandalf.magic_durability(); break;
        }
        if(end_turn())
        {
            cout << "Ending Turn..." << endl;
            break;
        }
        cnt += 1;
    }


    return 0;
}

wizard::wizard(int in_age,char *color,int maximum_magic)
{
    age = in_age;
    strcpy(beard,color);
    mana = maximum_magic;
}

void wizard::tell_age()
{
    cout << "Gandalf: I am "<< age << " years old my child" << endl;
}


void wizard::show_beard()
{
    cout << "Gandalf: My beards color is "<< beard << endl << endl;
}

int wizard::give_mana() const
{
    return mana;
}

void wizard::take_mana(int in_mana)
{
    mana= in_mana;
    while(mana > 100)
    {
        mana -= 10;
    }
}

void wizard::fireball_spell()
{
    int magic = give_mana();
    cout << "Fireball!" << endl;
    cout << "------------------- Casting Fireball Spell -------------------" << endl;
    take_mana(magic-30);
    magic_durability();
}

void wizard::lighting_spell()
{
    int magic = give_mana();
    cout << "Lightning!" << endl;
    cout << "------------------- Casting Lighting Spell -------------------"<< endl;
    take_mana(magic-50);
    magic_durability();
}


 void wizard::magic_durability()
 {
    cout << "My mana is at " << mana << "%" << endl;
 }

void wizard::magic_build_up()
{
    int magic = give_mana();
    cout << "------------------- Casting Magic Build Up -------------------" << endl;
    cout << "I shall be patient so my magic power can strenthen itself" << endl;
    take_mana(magic + 30);
    magic_durability(); 
}

int checks_spell(int spell)
{
    while(spell != 1 && spell != 2 && spell != 3 && spell != 9) 
    {
        cout << "Not avaiable spell" << endl << "Your avaiable spells are:" << endl;
        cout << "1.Lighting Spell" << endl;
        cout << "2.Fireball Spell" << endl;
        cout << "3.Magic build up" << endl;
        cout << "9.Update on mana" << endl;
        cin >> spell;
    }
    return spell;
} 

int end_turn()
{
    char decision;
    cout << "Wanna end your turn? (Y/N)" << endl;
    cin >> decision; 
    if(decision == 'Y' || decision == 'y')
    {   
        return 1;
    }
    else
    {
        return 0;
    }       
}
