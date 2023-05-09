#include <iostream>
#include "STRING.cpp"
using namespace std;

class table;  //fwd declaration

class chair
{   
    public:
        chair(int ,STRING );
        friend ostream &operator <<(ostream &,chair &);
        friend void shrink(chair &,table &);
    private:
        int height;
        STRING color;
};

class table
{
    public:
        table(int ,STRING );
        friend ostream &operator <<(ostream &,table &);
        friend void shrink(chair &,table &);
    private:
        STRING color;
        int length;
};

ostream &operator <<(ostream &,chair &);
ostream &operator <<(ostream &,table &);
void shrink(chair &,table &);


int main(void)
{
    table k(10,"red");
    cout << k << endl;

    chair c(10,"blue");
    cout << c << endl;

    shrink(c,k);
    
    cout << c << endl << k << endl;
    return 0;
}

chair::chair(int in_height,STRING in_color)
{
    height = in_height;
    color = in_color;
}


ostream &operator <<(ostream &left,chair &right)
{
    left << "The color of the chair is:" << right.color << "The height of the chair is:" << right.height << endl;

    return left;
}

table::table(int in_lenght,STRING in_color)
{
    length = in_lenght;
    color = in_color;
}

ostream &operator <<(ostream &left,table &right)
{
    left << "The color of the desk is:" << right.color << "The length of the desk is:" << right.length << endl;

    return left;
}

void shrink(chair &c,table &t)
{
    c.height = c.height * 0.1;
    t.length = t.length * 0.1;
    
}