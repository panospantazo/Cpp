//Dynamic Memory Allocation of One Dimansional Array



#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
    int *arr;
    int n = 4;

    arr = new int [n];
    if(!arr)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i] = i*i;
    }

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;

    return 0;

}