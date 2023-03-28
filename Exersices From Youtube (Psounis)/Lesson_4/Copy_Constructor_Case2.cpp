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

dummy f();

int main(void)
{
    cout << "Main:Before calling f" << endl;
    f();
    cout << "Main:After calling f" << endl;
    return 0;
}

dummy::dummy()
{
    cout << "Constructor..." << endl;
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

dummy f()
{
    dummy ob;
    cout << "In function..." << endl;
    return ob;
}