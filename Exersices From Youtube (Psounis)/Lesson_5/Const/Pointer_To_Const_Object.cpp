#include <iostream>
using namespace std;

class dummy
{
    public:
        dummy(int );
        int get_x() const;
        void set_x(int );
    private:
        int x;
};

void f(const dummy *p);

int main(void)
{
    dummy ob(3);

    f(&ob);

    return 0;
}

dummy::dummy(int in_x)
{
    x = in_x;
}

int dummy::get_x() const 
{
    return x;
}

void dummy::set_x(int in_x)
{
    x = in_x;
}

void f(const dummy *p)
{
    cout << p->get_x();
    //p->set_x(2);  //error
}