#include <iostream>
using namespace std;

class dummy
{
    public:
        dummy();
        dummy(const dummy &);
        ~dummy();
        int x;
};

void f(dummy);

int main(void)
{
    dummy d;
    
    cout << "Main: Before calling f" << endl;
    f(d);
    cout << "Main: After calling f" << endl;
    return 0;
}

dummy::dummy()
{
    cout << "Constructing..." << endl;
    x = 0;
}

dummy::dummy(const dummy &ob)
{
    cout << "Copy constructor..." << endl;
    x = ob.x;
}

dummy::~dummy()
{
    cout << "Destructing..." << endl;
}

void f(dummy arg)
{
    cout << "In fuction..." << endl;
}