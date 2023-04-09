#include <iostream>
using namespace std;

class dummy
{
    public:
        dummy(int ,int );
        void print();
    private:
        int x,y;
};  

int main(void)
{
    dummy ob(1,2);

    ob.print();

    return 0;
}

dummy::dummy(int in_x,int in_y):
x(in_x),y(in_y)
{
    cout << "Constructing..." << endl;
}

void dummy::print()
{
    cout << x << " " << y;
}