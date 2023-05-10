#include <iostream>
#include <cstdlib>
#define N 5
using namespace std;

class orc
{
    public:
        static int alive_orcs;
        
        orc();
        ~orc();

        static bool frenzy_mode;
        static void toggle_frenzy_mode();

        friend ostream &operator<<(ostream &,orc &);
    private:
        int h;   //random information about orcs
};

int orc::alive_orcs = 0;
bool orc::frenzy_mode = false;

int main(void)
{
    orc orc1,orc2;

    cout << "NORMAL MODE" << endl;
    cout << "-----------" << endl;

    cout << orc1 << endl;
    cout << orc2 << endl;

    orc::toggle_frenzy_mode();

    cout<< endl << "FRENZY MODE" << endl;
    cout << "-----------" << endl;

    cout << orc1 << endl;
    cout << orc2 << endl;
    
    return 0;
}

orc::orc()
{
    alive_orcs++;
}

orc::~orc()
{
    alive_orcs--;
}

void orc::toggle_frenzy_mode()
{
    if(frenzy_mode)
    {
        frenzy_mode = false;
    }
    else
    {
        frenzy_mode = true;
    }
}

ostream &operator<<(ostream &left,orc &right)
{
    if(orc::frenzy_mode)
    {
        cout << "AAISUFNABFSNUH0";
    }
    else
    {
        cout << "MEERLOOO";
    }

    return left;
}