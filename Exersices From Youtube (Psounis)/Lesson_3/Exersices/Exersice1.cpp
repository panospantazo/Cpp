#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    int x=6;
    int *p,**pp;
    cout << &x << endl;

    p = &x;
    pp = &p;

    
    cout << "x = " << x <<"(address:"<< &x <<")"<<endl;
    cout << "p = " << p << "(address:" << &p << ")" << endl;
    cout << "x =(*p)" << *p << endl;
    cout << "pp= " << pp << "(address:" << &pp << ")" << endl;
    cout << "x=(**pp)=" << **pp << endl;
    cout << "p=(*p)=" << *p << endl;  
    

   
    
    
    return 0;
}