#include <iostream>

using namespace std;

void max(float *,int ,float *,float *);
float * create_array(int N);
float min(float *,int N);
void destroy_array(float *,int N);

int main(void)
{
    int N;
    float *array,max1,max2;
    cout << "How many cells do you need: ";
    cin >> N;
    array = create_array(N);
    for (int i=0;i<N;i++)
    {
        cout << "Give " << i+1 << "st number: ";
        cin >> array[i];
    }
    cout << "-----------------------" << endl;
   
    max(array,N,&max1,&max2);

    cout << "The First Maximum digit is:" << max1 << endl << "The Second Maximum digit is:" << max2 << endl; 
    
    cout << "The Minimum number multiplied by 2 is:" << min(array,N) * 2 << endl;

    destroy_array(array,N);

    return 0;
}


void max(float *array,int N,float *max1,float *max2)
{
     *max1 = array[0];
     *max2=0;

    for(int i=1;i<N;i++)
    {
        if(*max1 < array[i])
        {
            *max2 = *max1;
            *max1 = array[i];
        }
        else if(*max2 < array[i])
        {
            *max2 = array[i];
        }
    }
}

float min(float *array,int N)
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

float * create_array(int N)
{
    float *array;
    array = new float[N];
    return array;
}

void destroy_array(float *array,int N)
{
    delete[]array;
}