#include <iostream>
#define N 5

using namespace std;

void max(float *);
float min(float *);

int main(void)
{

    float array[N];
    for (int i=0;i<5;i++)
    {
        cout << "Give " << i+1 << "st number: ";
        cin >> array[i];
    }
    cout << "-----------------------" << endl;
   
    max(array);
    
    cout << "The Minimum number multiplied by 2 is:" << min(array) * 2 << endl;

    return 0;
}


void max(float *array)
{
    float max1=array[0];
    float max2=0;

    for(int i=1;i<N;i++)
    {
        if(max1 < array[i])
        {
            max2 = max1;
            max1 = array[i];
        }
        else if(max2 < array[i])
        {
            max2 = array[i];
        }
    }
    cout << "First Maximum number: "<< max1 << endl << endl << "Second Maximun Number: " << max2 << endl << endl;   
}

float min(float *array)
{
    float min=array[0];
    for(int i=1;i<N;i++)
    {
        if(min > array[i])
        {
            min = array[i];
        }
    }
    return min;
}