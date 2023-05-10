//Exersice 2

#include <iostream>
#include <cstdlib>
#include "ARRAY.cpp"
using namespace std;



int main(void)
{
    int n=10001;
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

