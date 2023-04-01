//How can I put values into Dynamic Memory Allocated Objects

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
    dummy obj;
    dummy *p = &obj;
    
    obj.x =  6;

    cout << "ob.x = " << obj.x << endl << "p->x = " << p->x << endl << "(*p).x = " << (*p).x << endl;

    return 0; 
}