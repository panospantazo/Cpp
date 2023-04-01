//Dynamic Memory Allocation of Two Dimansional Array

#include <iostream>
#include <cstdlib>
using namespace std;

int main(void)
{
        int **arr;
        int i,j,n=4,m=4;

        arr = new int * [n];
        if(!arr)
        {
            cout << "Error Allocating Memory";
            exit(1312);
        }
        for(i=0;i<n;i++)
        {
            arr[i] = new int [m];
            if(!arr[i])
            {
                cout << "Error Allocating Memory";
                exit(1312);
            }
        }
        

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                arr[i][j] = i*j;
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }

        return 0;
}