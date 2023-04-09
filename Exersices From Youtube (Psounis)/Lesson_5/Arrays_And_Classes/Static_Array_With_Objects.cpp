#include <iostream>
#define N 3
using namespace std;

class dummy
{
    public:
        dummy();
        dummy(int );
        int get_x() const;
    private:
        int x;
};

int main(void)
{
    dummy array[N] = {dummy(),dummy(3),dummy(5)};

    
    for(int i=0;i<N;i++)
    {
        cout << array[i].get_x() << endl;
    }
    return 0;
}

dummy::dummy(int in_x)
{
    x = in_x;     
}

dummy::dummy()
{
    x = 0;
}

int dummy::get_x() const
{
    return x;
}
