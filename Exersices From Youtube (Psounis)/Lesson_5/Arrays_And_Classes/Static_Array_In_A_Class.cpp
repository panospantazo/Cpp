#include <iostream>
#define N 3
using namespace std;

class grades
{
    public:
        grades();
        void set_i(int ,int);
        int get_i(int ) const;
    private:
        int array[N];
};

int main(void)
{
    grades my_grades;

    my_grades.set_i(0,5);
    my_grades.set_i(1,8);
    my_grades.set_i(2,7);

    for(int i=0;i<N;i++)
    {
        cout << my_grades.get_i(i) << endl;
    }
    return 0;
}

grades::grades()
{
     for(int i=0;i<N;i++)
    {
        array[i] = 0;
    }
}

void grades::set_i(int pos,int val)
{
    if(pos>=0 && pos<=N)
    {
        array[pos] = val;
    }
    else
    {
        cout << "Out of bounds" << endl;
    }
}

int grades::get_i(int pos) const
{
    if(pos>=0 && pos<=N)
    {
        return array[pos];
    }
    cout << "Out of bounds" << endl << "Returning 0" << endl;
    return 0;
}
