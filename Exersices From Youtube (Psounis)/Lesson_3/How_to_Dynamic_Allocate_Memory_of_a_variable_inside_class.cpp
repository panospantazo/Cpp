//How_to_Dynamic_Allocate_Memory_of_a_variable_inside_class

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
    dummy obj;
    obj.set_val(3);

    cout << endl << obj.get_val() << endl;

    return 0;
}

dummy::dummy()
{
    p_val = new int;
    
    if(!p_val)
    {
        cout << "Error Allocating Memory";
        exit(1312);
    }

    cout << "Constructing";
}

dummy::~dummy()
{
    delete p_val;
    cout << "Destructing...";       
}

void dummy::set_val(int in_val)
{
    *p_val = in_val;
}

int dummy::get_val()
{
    return *p_val;
}

    
