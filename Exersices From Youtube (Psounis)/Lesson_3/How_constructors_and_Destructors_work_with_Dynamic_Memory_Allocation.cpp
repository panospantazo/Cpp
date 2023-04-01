//How constructors and destructors work with Dynamic Memory Allocation

#include <iostream>
#include <cstdlib>
using namespace std;

class dummy
{
    public:
        dummy(int in_x);
        ~dummy();
    private:
        int x;
};

int main(void)
{
    dummy *p = NULL;
    p = new dummy(5);
    
    if(!p)
    {
        cout << "Error Allocating Memory" << endl;
        exit(350);
    }

    delete p;
    
    return 0;
}

dummy::dummy(int in_x)
{
    x - in_x;
    cout << "Constructing" << endl;
}

dummy::~dummy()
{
    cout << "Destructing";
}