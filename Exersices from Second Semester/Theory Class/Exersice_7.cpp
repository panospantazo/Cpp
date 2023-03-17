#include <iostream>
using namespace std;

int main(void)
{
    int matrix1[3][4] = {(1,2,3,4)
                        (5,6,7,8)
                        (9,10,11,12)};
    
    int matrix2[3][4] = {{121,245,33,42
                          59,67,74,81
                          94,104,111,128}};

    int sumMatrix[3][4];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << "sumMatrix["<<i<<"]["<<j<<"]="<<sumMatrix[i][j] << endl;
        }
    }
    return 0;
}