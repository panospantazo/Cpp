//Exersice 2
#include <iostream>
using namespace std;

class mark
{
    public:
      mark();
      mark(float new_x,float new_y);
      
      void give_mark_x(float new_x);
      void give_mark_y(float new_y);
      
      float take_mark_x() const;
      float take_mark_y() const;
      
      void print();

    private:
        float x,y;
};

int main(void)
{
    mark a(1.6,3.2);
    mark b(2.1,9.9);
    mark c(2.5,6.9);
    
    cout << "The first mark is:";
    a.print();
    
    cout << endl <<"The second mark is:";
    b.print();
    
    cout << endl <<"The third mark is:";
    c.print();

    return 0;
}


mark::mark()
{
    x=0.0;
    y=0.0;
}

mark::mark(float new_x,float new_y)
{
    x = new_x;
    y = new_y;
}

void mark::give_mark_x(float new_x)
{
    x = new_x;
}

void mark::give_mark_y(float new_y)
{
    y = new_y;
}

float mark::take_mark_x() const
{
    return x;
}

float mark::take_mark_y() const
{
    return y;
}

void mark::print()
{
    cout << "(" << x << "," << y << ")" << endl;
}