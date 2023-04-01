//Dynamic Memory Allocation for object 

#include <iostream>
#include <cstdlib>
using namespace std;

class dummy
{
    public:
        int x;
};


int main(void)
{
    dummy *p = NULL;
    p = new dummy;
    if(!p)
    {
        cout << "Error Allocating Memory!" << endl;
        exit(423);
    }
    (*p).x = 5;
    
    cout << "(*p).x=" << (*p).x << endl;

    delete p;

    return 0;
}