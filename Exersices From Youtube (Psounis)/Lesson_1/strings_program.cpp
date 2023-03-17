//A strings learning program
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[80];
    char str2[80];

    cout << "Give string: ";
    cin >> str1;
    strcpy(str2,str1);
    cout << str2;
    
    return 0;
}