#include <iostream>
#include <string>
using namespace std;
#define size 10

void taxinomisi(string *);
void swap(string &,string &);

int main(void)
{
    string arr[size] = {"abcd" , "Abcd" , "aBcd" , "abCd" , "abcD" , "lops" , "luffy" , "kappa" , "opa","aAaA"};
    taxinomisi(arr);
     for(int i = 0 ; i < size ; i++)
    { 
            cout<< i + 1 << ". " << arr[i] << endl;  
    }
    return 0;
}


void taxinomisi(string *arr)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = i; j >= 1 ; j--)
        {
            if(arr[i] < arr[j - 1])
            {
                swap(arr[j] , arr[j - 1]);
            }
            else
            {
                break;
             }
        }
    }
}

void swap(string &str1,string &str2)
{
    string temp = str1;
    str1 = str2;
    str2 = temp;
}