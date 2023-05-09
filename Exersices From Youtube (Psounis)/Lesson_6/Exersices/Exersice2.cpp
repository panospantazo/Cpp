//Exersice 2

#include <iostream>
#include <cstdlib>
using namespace std;

class array
{   
    public:
        array(int );
        array(const array &);
        ~array();
        
        void print_array();
       
        int get_N() const;
        
        int &operator[](int );
        array operator+=(int );
        array &operator= (array &);
        

    private:
        int *p;
        int N;

};

int main(void)
{
    int n=10;
    array pin(n);
    array pin2(2);
    for(int i=0;i<n;i++)
    {
        pin[i] = i * i;
    }
    pin.print_array();

    pin2 = pin;
    
    pin2.print_array();

    pin2 += 5;

    pin2.print_array();



    return 0;
}

array &array::operator=(array &right)
{
    if(this == &right)
    {
        return *this;
    }
    delete [] p;
    
    N = right.N;
    p = new int [N];
    if(!p)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }

    for(int i=0;i<N;i++)
    {
        p[i] = right[i];
    }

    return *this;
}

array array::operator+=(int k)
{    
    int *new_p;
    int new_N = N + k;
    
    new_p = new int [new_N];
    if(!new_p)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }

    for(int i=0;i<N;i++)
    {
        new_p[i] = p[i];
    }

    delete [] p;

    p = new int [new_N];
    if(!p)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }

    for(int i=0;i<N;i++)
    {
        p[i] = new_p[i];
    }
    for(int i=N;i<new_N;i++)
    {
        p[i] = 0;
    }

    N = new_N;
} 

array::array(const array &ob)
{

    N = ob.get_N();

    p = new int [N];
    if(!p)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
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
    cout << ")" << endl;
}

/*void array::take_array(int k,int o)
{
    if(k<0 || k>9)
    {
        cout << "You are outside the limits of the array" << endl;
        exit(1312);
    }
    p[k] = o;
    
} */

int array::get_N() const
{
    return N;
}

int &array::operator[](int i)
{
    if(i>=0 && i<N)
        return p[i];
    else
        cout << "Index Error";
        exit(1312);
}