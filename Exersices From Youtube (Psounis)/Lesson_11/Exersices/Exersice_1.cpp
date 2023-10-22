#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define size 300
#define h_size 10
using namespace std;

//10 lepto

class card;

class pool 
{
    public:
        pool();
        ~pool();
        card * pick_random_card();
    protected:
        card *arr[size];
        int cards;
};

class hand
{
    public:
        hand(pool &);
        void pick_card(pool & , int );
        void fill_hand(pool &);
        friend ostream & operator<<(ostream &,hand &);
    private:
        card *y_hand[h_size];
        int hand_cards;
};

class card 
{
    public: 
        card();
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
    srand(time(NULL));


    pool deck;


    hand l(deck);

    cout << l;
    

    return 0;
}

card::card()
{
    name = " ";
    color = " ";
    rarity = " ";
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

pool::pool()
{
    
    arr[0] = new creature("Akroan Crusader", "Red" , "Common" , 1 , 1 , "Human");
    
    arr[1] = new creature("Rune Scarred Demon" , "Black" , "Legendary" , 6 , 6 , "Demon");
    
    arr[2] = new land("Plains" , "Gold" , "Common" , 1 , "Basic Land");
    
    arr[3] = new land("Swamp" , "Black" , "Rare" , 2 , "Basic Land");
    
    arr[4] = new land("Forest" , "Green" , "Very Rare" , 1 , "Basic Land");
    
    arr[5] = new creature("Aegis Angel" , "White", "Common" , 5 , 5 , "Angel");
    
    arr[6] = new creature("Angler Turtle" , "Blue" , "Very Rare" , 5 , 7 , "Creature - Turtle");
    
    arr[7] = new creature("Harbinger of Night" , "Black" , "Legendary" , 2 , 2 , "Summon Spirit");
   
    arr[8] = new creature("Ghalta, Primal Hunger" , "Green" , "Very Rare" , 12 , 12 , "Elder Dinosaur");
    
    arr[9] = new creature("Skarrgan Hellkite" , "Red" , "Common" , 4 , 4 , "Dragon");
   
    arr[10] = new creature("Spawn of Mayhem" , "Black" , "Legendary" , 4 , 4 , "Demon");
    

    cards = 11;  

}

pool::~pool()
{
    int i;
    for(i = 0 ; i < cards ; i++)
    {
        delete arr[i];
    }
   
}

hand::hand(pool &arr)
{
    int i;

    for(i = 0; i < h_size ; i++)
    {
        pick_card(arr , i);
    }

    hand_cards = h_size;
}

card * pool::pick_random_card()
{
    return arr[rand()%cards];
}

void hand::pick_card(pool &arr , int i)
{
    y_hand[i] = arr.pick_random_card(); 
    hand_cards++;
}

void hand::fill_hand(pool &arr)
{
    int i;

    if(hand_cards<= 3)
    {
        for(i = hand_cards; i < h_size; i++)
        {
            pick_card(arr , i);
            hand_cards += 7;
        }
    }
}

ostream & operator<<(ostream & left,hand & obj)
{
    int i;

    for(i = 0 ; i < obj.hand_cards ; i++)
    {
        left << i+1 << "." << *obj.y_hand[i] << endl;
    }

    return left;
}

