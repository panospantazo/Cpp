#include <iostream>
#include <string>
using namespace std;

class animal
{
    public:
        int get_weight() const;
        int get_height() const;
        void set_weight(int );
        void set_height(int );
    private:
        int weight;
        int height;
};

class dog: public animal
{
    public:
        void bark();
        void set_house_address(string );
        string get_house_address() const;
        friend ostream & operator<<(ostream & , const dog &);
    private:
        string house_address;
};

int main(void)
{
    dog piko;

    piko.set_house_address("Wolf Street 1312");
    piko.set_weight(10);
    piko.set_height(35);

    piko.bark();
    cout << piko;
    return 0;
}

void animal::set_weight(int in_weight)
{
    weight = in_weight;
}

void animal::set_height(int in_height)
{
    height = in_height;
}

int animal::get_height() const
{
    return height;
}

int animal::get_weight() const
{
    return weight;
}

void dog::bark()
{
    cout << "bark bark!" << endl;
}

void dog::set_house_address(string in_add)
{
    house_address = in_add;
}

string dog::get_house_address() const
{
    return house_address;
}

ostream & operator<<(ostream &left,const dog &obj)
{
    //left << "weight: " << weight; doesn't work
    left << "weight: " << obj.get_weight() << endl;
    //left << "height: " << obj.get_height() << endl;
    left << "height: " << obj.get_height() << endl;
    left << "address: " << obj.get_house_address() << endl; 
    
    return left;
}
