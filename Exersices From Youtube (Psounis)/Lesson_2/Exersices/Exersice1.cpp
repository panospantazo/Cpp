#include <iostream>
using namespace std;

class dummy
{
    public:
        dummy();
        dummy(int in_x);
        ~dummy();


        void give_dummy(int x);
        int  take_dummy() const;

    private:
        int x;

};

int main(void)
{
    dummy x(10),y;


    return 0;
}

dummy::dummy()
{
    x = 0;
}

dummy::dummy(int in_x)
{
    x = 10;
}

dummy::~dummy()
{
    cout <<"Destructing with x = "<< x << endl; 
}

void dummy::give_dummy(int in_x)
{
    x = in_x;
}

int dummy::take_dummy() const
{
    return x;
}