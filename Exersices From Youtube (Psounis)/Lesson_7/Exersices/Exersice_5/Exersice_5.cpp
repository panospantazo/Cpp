#include <iostream>
#include <cstdlib>
#include "BOARD.cpp"
#include "POINT.CPP"
using namespace std;



class point
{
    public:
        point(int ,int );

        int get_x() const;
        int get_y() const;

        void set_x(int );
        void set_y(int );

        friend ostream &operator<<(ostream &,point &);
    private:
        int x;
        int y;
};

class board
 {
    public:
        board(int);
        
        ~board();

        board(const board &);

        board &operator=(board &);
        friend ostream &operator<<(ostream &,board &);

        char get_element(int ,int ) const;
        void set_element(int ,int ,char );

        void insert_point(point );

        void clear_b();

    private:
        int N;
        char **b;

 };

 ostream &operator<<(ostream &,board &);
 ostream &operator<<(ostream &,point &);




int main(void)
{
    int choice;
    point p1(0,0);
    board bord(25);
    do
    {
        cout <<"--MENU--" << endl;
        cout <<"1|Create new point" << endl;
        cout <<"2|Print board" << endl;
        cout <<"3|Clear board" << endl;
        cout <<"4|Exit" << endl;
        cin  >> choice;
        switch(choice)
        {
            case 1:
                int x,y;
                cout << "MAKING THE POINT..." << endl;
                cout << "-------------------" << endl;
                cout << "Give me coordinates about x between 0-59: ";
                cin  >> x;
                cout << endl <<"Give me coordinates about y between 0-59: ";
                cin  >> y;
                p1.set_x(x);
                p1.set_y(y);
                bord.insert_point(p1);
                break;
            case 2:
                cout << "PRINTING THE BOARD" << endl;
                cout << "------------------" << endl;
                cout << bord << endl;
                break;
            case 3:
                cout << "CLEANING THE BOARD" << endl;
                cout << "------------------" << endl;
                bord.clear_b();
                break;
            case 4:
                cout << "GOODBYE USER" << endl;
                cout << "------------" << endl;
            default:
                cout << "Wrong Choice..." << endl;
        }   
    }while(choice != 4);

    return 0;
}

point::point(int in_x,int in_y)
{
    if(in_x >=0 && in_x <= 59)
    {
        x = in_x;
    }
    else
    {
        cout << "Wrong Value for x" << endl;
        x = 0;
    }

    if(in_y >=0 && in_y <= 59)
    {
        y = in_y;
    }
    else
    {
        cout << "Wrong Value for y" << endl;
        y = 0;
    }
}

int point::get_x() const
{
    return x;
}

int point::get_y() const
{
    return y;
}

void point::set_x(int in_x)
{   
    if(in_x >=0 && in_x <= 59)
    {
        x = in_x;
    }
    else
    {
        x = 0;
    }
}

void point::set_y(int in_y)
{   
    if(in_y >=0 && in_y <= 59)
    {
        y = in_y;
    }
    else
    {
        y = 0;
    }
}

ostream &operator<<(ostream &left,point &right)
{
    left << "(" <<right.get_x() << "," << right.get_y() << ")";

    return left;
}

board::board(int in_N)
{
    int i,j;
    N = in_N;
    b = new char *[N];
    if(!b)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    for(i=0;i<N;i++)
    {
        b[i] = new char [N];
        if(!b[i])
        {
            cout << "Error Allocating Memory" << endl;
            exit(1312);
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            b[i][j] = '.';
        }
    }
}

board::~board()
{
    int i;

     for(i=0;i<N;i++)
     {
        delete [] b[i];
     }
     delete [] b;
}

board::board(const board &copy_b)
{
    int i,j;

    N = copy_b.N;

    b = new char *[N];
    if(!b)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    for(i=0;i<N;i++)
    {
        b[i] = new char [N];
        if(!b[i])
        {
            cout << "Error Allocating Memory" << endl;
            exit(1312);
        }
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            b[i][j] = copy_b.b[i][j];
        }
    }
}

board &board::operator=(board &ob)
{
    int i,j;
    
    if(ob.b != NULL)
    {
        for(i=0;i<N;i++)
        {
            delete [] b[i];
        }
        delete [] b;
    }
        
    N = ob.N;

    b = new char *[N];
    if(!b)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    for(i=0;i<N;i++)
    {
        b[i] = new char [N];
        if(!b[i])
        {
            cout << "Error Allocating Memory" << endl;
            exit(1312);
        }
    }   
    
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            b[i][j] = ob.b[i][j];
        }
    }

    return *this;
}

char board::get_element(int i,int j) const
{
    return b[i][j];
}

void board::set_element(int i,int j,char q)
{
    b[i][j] = q;
}

ostream &operator<<(ostream &left,board &right)
{
    int i,j;

    for(i=right.N-1;i>=0;i--)
    {
        for(j=0;j<right.N;j++)
        {
            left << right.b[i][j] << " "; 
        }
        left << endl;
    }

    return left;
} 

void board::insert_point(point ob)
{
    if(ob.get_x() >= 0 && ob.get_x() <= N && ob.get_y() >= 0 && ob.get_y() <= N)
    {
        b[ob.get_x()][ob.get_y()] = 'O'; 
    }
    else
    {
        cout << "Point out of bounds" << endl;
    }
}

void board::clear_b()
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(b[i][j] == 'O')
            {
                b[i][j] = '.';
            }
        }
    }
}