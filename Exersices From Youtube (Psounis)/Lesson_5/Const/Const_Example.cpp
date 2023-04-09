#include <iostream>
using namespace std;

class dummy
{
    public:
        dummy(int);
        int get_x();
        void set_x(int);
    private:
        int x;
};

int main(void)
{
    const dummy ob(3);

   // ob.set_x(4);  //error 

    return 0;
}

dummy::dummy(int in_x)
{
    x = in_x;
}

int dummy::get_x()
{
    return x;
}

void dummy::set_x(int in_x)
{
    x = in_x;
}