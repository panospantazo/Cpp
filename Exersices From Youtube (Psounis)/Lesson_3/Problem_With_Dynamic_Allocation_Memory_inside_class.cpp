//I cant copy any obj(example obj1 = obj2)
//! THIS CODE IS WRONG !

#include <iostream>
#include <cstdlib>
using namespace std;

class dummy
{
    public:
        dummy();
        ~dummy();
        void set_val(int in_val);
        int get_val();
    private:
        int *p_val;
};

int main(void)
{
    dummy obj1;
    obj1.set_val(3);
    dummy obj2;
    obj2=obj1;

    cout << obj1.get_val() << endl;
    cout << obj2.get_val() << endl;

    return 0;
}

dummy::dummy()
{
    p_val = new int;
    if(!p_val)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }

    cout << "Constructing" << endl;
}

dummy::~dummy()
{
    delete p_val;
    cout << "Destructing" << endl;
}

void dummy::set_val(int in_val)
{
    *p_val = in_val;
}

int dummy::get_val()
{
    return *p_val;
}