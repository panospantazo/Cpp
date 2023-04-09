#include <iostream>
using namespace std;

class point
{
    public:
        point(int x = 0,int y = 0);
        point *ret_this();
        void print();
    private:
        int x;
        int y;
};


int main(void)
{
    point ob(3,4);

    ob.print();

    return 0;
}

point::point(int x,int y)
{
    this->x = x;
    this->y = y;
}

point *point::ret_this()
{
    return this;
}

void point::print()
{
    cout << x << " " << y << endl;
}



