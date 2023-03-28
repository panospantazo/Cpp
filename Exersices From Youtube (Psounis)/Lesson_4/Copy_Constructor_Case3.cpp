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

int main(void)
{
    dummy ob1;
    dummy ob2 = ob1; // dummy ob2(ob1)

    return 0;
}

dummy::dummy()
{
    cout << "Constructing..." << endl;
    x = 0;
}

dummy::dummy(const dummy &ob)
{
    cout << "Copy Constructor..." << endl;
    x = ob.x;
}

dummy::~dummy()
{
    cout << "Destructing..." << endl;
}