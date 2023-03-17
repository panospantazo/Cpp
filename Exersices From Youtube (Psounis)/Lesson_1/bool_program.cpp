//A Learning boolean variables program
#include <iostream>
using namespace std;

int main(void)
{
    bool x = true;

    cout << x << endl;

    x = 4;
    cout << x << endl;

    x = !(0>1);
    if(x)
        cout << x << endl;
    
    return 0;
}