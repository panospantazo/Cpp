#include <iostream>
#include <cstdlib>

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
    dummy *array;
    int n = 3;

    array = new dummy[n];
    if(!array)
    {
        cout << "Error Allocating Memory";
        exit(1312);
    }
    
    for(int i=0;i<n;i++)
    {
        array[i].set_x(i*i);
    }

    
    for(int i=0;i<n;i++)
    {
        cout << array[i].get_x() << endl;
    }

    delete [] array;
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