#include <iostream>
#include <string>
#include "C"
using namespace std;


class card
{
    public: 
        card(string , string , string);
        friend ostream & operator<<(ostream & , card &);
    protected: 
        string name;
        string color;
        string rarity;
};

class creature: public card
{
    public:
        creature(string , string , string , int , int , string );
        friend ostream & operator<<(ostream &, creature &);
    private:
        int attack;
        int defence;
        string kind;
        
};

class land: public card
{
    public:
        land(string , string , string , int ,string );
        friend ostream & operator<<(ostream &, land &);
    private:
        int mana;
        string description;
        bool tap;
};

int main(void)
{
    creature  Akroan_Crusader("Akroan Crusader", "Red" , "Common" , 1 , 1 , "Human");
    creature Rune_Scarred_Demon("Rune Scarred Demon" , "Black" , "Legendery" , 6 , 6 , "Demon");

    cout << Akroan_Crusader << endl;
    cout << Rune_Scarred_Demon << endl; 


    land Plains("Plains" , "Gold" , "Common" , 1 , "Basic Land");

    land Swamp("Swamp" , "Black" , "Rare" ,2 , "Basic Land");

    land Forest("Forest" , "Green" , "Very Rare" , 1 , "Basic Land");

    cout << Plains << Swamp << Forest << endl;

    return 0;
}

card::card(string in_name,string in_color,string in_rarity)
{
    name = in_name;
    color = in_color;
    rarity = in_rarity;
}

ostream & operator<<(ostream & left, card & obj)
{
    left << "Name: " << obj.name << "| Color: " << obj.color << "| Rarity " << obj.rarity << endl; 

    return left;
}

ostream & operator<<(ostream & left, creature & obj)
{
    left << "Name: " << obj.name << "| Color: " << obj.color << "| Rarity " << obj.rarity << "| Attack: " << obj.attack << "| Defence: " << obj.defence << "| Kind: " << obj.kind << endl;

    return left;
}

creature::creature(string in_name,string in_color,string in_rarity , int in_attack , int in_defence , string in_kind ):
  card(in_name ,in_color,in_rarity)
{
    attack = in_attack;
    defence = in_defence;
    kind = in_kind;
}

land::land(string in_name ,string in_color,string in_rarity , int in_mana , string in_description):
    card(in_name ,in_color,in_rarity)
{
    mana = in_mana;
    description = in_description;
    tap = false;
}

ostream & operator<<(ostream & left, land & obj)
{
    left << "Name: " << obj.name << "| Color: " << obj.color << "| Rarity " << obj.rarity << "| Mana: " << obj.mana << "| Description: " << obj.description;
    if(obj.tap)
    {
        left << "| Tap: Tapped" << endl;
    }
    else
    {
        left << "| Tap: Untapped" << endl;
    }

    return left;
}
