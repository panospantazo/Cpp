#include <iostream>
using namespace std;

float average(int ,int );
float average(float ,float );

int main(void)
{
    int ans;
    cout << "1.Integers" << endl << "2.Float" << endl;
    cin >> ans;

    if(ans == 2)
    {
        float a,b;
        cout << "Give float a: ";
        cin >> a;
        cout << "Give float b: ";
        cin >> b;
        cout << average(a,b);
    }
    else
    {
        int a,b;
        cout << "Give integer a: ";
        cin >> a;
        cout << "Give integer b: ";
        cin >> b;
        cout << average(a,b);
    }
    return 0;
}

float average(int x, int y)
{
    return (x+y)/2.0;
}

float average(float x, float y)
{
    return (x+y)/2;
}
