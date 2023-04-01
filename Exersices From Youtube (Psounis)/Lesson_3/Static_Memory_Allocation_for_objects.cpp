//Static_Memory_Allocation_for_objects

#include <iostream>
using namespace std;

class dummy
{
    public:
        int x;
        int y;
};

int main(void)
{
    dummy obj;
    obj.x = 3;
    obj.y = 5;

    cout << sizeof obj << endl;

    return 0;
}