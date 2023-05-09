#include <iostream>
#include <cstdlib>
#include <cstring>
#include "STRING.cpp"
using namespace std;



int main(void)
{
    char s[80] = "This is a string";
    STRING s1(s);
    STRING s2 = s1;
    
    cout << "Give a string" << endl;
    cin >> s2;
    
    cout << s1;
    cout << s2;
    cout<<"----------------------------" << endl;
    s1 = s2;
    cout << s1;
    cout << s2;
    cout<<"----------------------------" << endl;
    s1[3] = 'g';
    cout << s1;
    
    if(s1 == s2)
        cout <<"The two strings are the same" << endl;
    else
        cout << "The two string are not the same" << endl;
    
    s1[3] = 's';
    
    if(s1 == s2)
        cout <<"The two strings are the same" << endl;
    else
        cout << "The two strings are not the same" << endl;

    
    return 0;
}
