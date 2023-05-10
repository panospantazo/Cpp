#include <iostream>
#include <cstdlib>
#define N 5
using namespace std;

class orc
{
    public:
        static int alive_orcs;
        orc();
        ~orc();
    private:
        int h;   //random information about orcs
};

int orc::alive_orcs = 0;

int main(void)
{
    orc *arr[N];
    int i,pos;

    for(i=0;i<N;i++)
    {
        arr[i] = NULL;
    }

    for(i=0;i<N;i++)
    {
        pos = rand()%N;

        if(arr[pos] == NULL)
        {
            arr[pos] = new orc;
            if(!arr[pos])
            {
                cout << "Error Allocating Memory" << endl;
                exit(1312);
            } 
        }
        else
        {
            delete arr[pos];
            arr[pos] = NULL;
        }
        if(i%10 == 0)
        {
            cout << "Step " << i << ":Alive orcs = " << orc::alive_orcs << endl;
        }
    }
    return 0;
}

orc::orc()
{
    alive_orcs++;
}

orc::~orc()
{
    alive_orcs--;
}