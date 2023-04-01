#include <iostream>
using namespace std;

class dummy
{
    public:
        dummy();
        ~dummy();
        dummy(const dummy &);
        int x;
        int y;
};

void swap(int&,int&);
void swap(double&,double&);
void swap(dummy&,dummy&);

int main(void)
{
    dummy x,y;
    cout << "Give first number: ";
    cin >> x.x;
    cout << "Give second number: ";
    cin >> y.y;
    cout << x.x << " " << y.y << endl;
    swap(x.x,y.y);
    cout << x.x << " " << y.y << endl;
    
    

    return 0;
}

void swap(int &rx,int &ry)
{
    int temp;
    temp = rx;
    rx = ry;
    ry = temp;
}

void swap(double &rx,double &ry)
{
    double temp;
    temp = rx;
    rx = ry;
    ry = temp;
}

void swap(dummy &rx,dummy &ry)
{
    dummy temp;
    temp = rx;
    rx = ry;
    ry = temp;
}

dummy::dummy()
{
    cout << "Constructing..." << endl;
}

dummy::~dummy()
{
    cout << "Decostructing..." << endl;
}