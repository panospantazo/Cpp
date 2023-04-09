#include <iostream>
#define N 3
using namespace std;

class dummy
{
    public:
        dummy();
        dummy(int );
        void set_x(int );
        int get_x() const;
    private:
        int x;
};

int main(void)
{
    dummy *array[N];

    for(int i=0;i<N;i++)
    {
        array[i] = new dummy;
    }
    
    for(int i=0;i<N;i++)
    {
        array[i]->set_x(i*i);
    }

    
    for(int i=0;i<N;i++)
    {
        cout << array[i]->get_x() << endl;
    }
    
    for(int i = 0; i<N;i++)
    {
        delete array[i];
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

void dummy::set_x(int in_x)
{
    x = in_x;
}