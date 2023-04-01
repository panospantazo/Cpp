//Exersice 2

#include <iostream>
#include <cstdlib>
using namespace std;

class array
{   
    public:
        array(int );
        ~array();
        void print_array();
        void take_array(int ,int );
        int give_array(int );
        
        

    private:
        int *p;
        int N;

};

int main(void)
{
    int n=10;
    array pin(n);
    for(int i=0;i<n;i++)
    {
        pin.take_array(i,i*i);
    }
    pin.print_array();
    

    return 0;
}

array::array(int in_n)
{
    N = in_n;
    p = new int[N];
    if(!p)
    {
        cout << "Error Allocating Memory" <<endl;
        exit(1312);
    }
    cout << "Constructing..." << endl;
}

array::~array()
{
    delete p;
    cout << endl << "Decostructing..." << endl;   
}
void array::print_array()
{
    cout << "(";
    for(int i=0;i<N;i++)
    {
        cout << p[i] << " "; 
    }
    cout << ")";
}

void array::take_array(int k,int o)
{
    if(k<0 || k>9)
    {
        cout << "You are outside the limits of the array" << endl;
        exit(1312);
    }
    p[k] = o;
    
}

int array::give_array(int k)
{
     if(k<0 || k>9)
    {
        cout << "You are outside the limits of the array" << endl;
        exit(1312);
    }
    return p[k];
}

