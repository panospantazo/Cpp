#include <iostream>
using namespace std;

class apartment
{
    public:
        apartment();
        ~apartment();
        void set_people(int );
        int get_people() const;

    private:
        int people;
};

class floor
{
    public:
        floor();
        ~floor();
        void set_people(int ,int );
        int get_people() const;
    private:
        apartment apartments[2];
};

class building
{
    public:
        building();
        ~building();
        void set_people(int ,int ,int );
        int get_people() const;
    private:
        floor floors[3];
};

int main(void)
{
    building x;

    x.set_people(0,0,3);
    x.set_people(0,1,5);
    x.set_people(1,0,4);
    x.set_people(1,1,6);
    x.set_people(2,0,2);
    x.set_people(2,1,5);

    cout << endl;
    cout << "People in building:" << x.get_people();
    cout << endl << endl;
    return 0;
}

apartment::apartment()
{
    people = 0;
    cout << "Constructing Flat..." << endl;
}

apartment::~apartment()
{
    cout << "Destructing flat..." << endl;
}

void apartment::set_people(int in_people)
{
    people = in_people;
}

int apartment::get_people() const
{
    return people;
}

floor::floor()
{
    cout << "Constructing Floor..." << endl;
}

floor::~floor()
{
    cout << "Destructing Floor..." << endl;
}

void floor::set_people(int in_apartments,int in_people)
{
    apartments[in_apartments].set_people(in_people);
}

int floor::get_people() const
{
    return apartments[0].get_people() + apartments[1].get_people();
}

building::building()
{
    cout << "Constructing building..." << endl;
}

building::~building()
{
    cout << "Destructing building..." << endl;
}

void building::set_people(int in_floor,int in_apartments,int in_people)
{
    floors[in_floor].set_people(in_apartments,in_people);
}

int building::get_people() const
{
    return floors[0].get_people() + floors[1].get_people() + floors[2].get_people();
}