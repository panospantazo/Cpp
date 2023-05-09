#include <cstring>
#include <iostream>
#include "STRING.h"


STRING::STRING()
{
    str = new char[1];
    str[0] = '\0';
    N = 0;
}

STRING::STRING(char *arr)
{
    N = strlen(arr);
    str = new char [N+1];
    if(!str)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(str,arr);
}

STRING::STRING(const char *arr)
{
    N = strlen(arr);
    str = new char [N+1];
    if(!str)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(str,arr);
}

STRING::~STRING()
{
    delete [] str;
}

char* STRING::get_str() const
{
    return str;
}

int STRING::get_N() const
{
    return N;
}

void STRING::set_str(char *arr)
{
    if(str != NULL)
    {
        delete [] str;
    }
        

    N = strlen(arr);
    str = new char [N+1];
    if(!str)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(str,arr);    
}

void STRING::set_N(int size)
{   
    N = size;
}


STRING::STRING(const STRING &ob)
{
   N = ob.get_N();
   str = new char [N+1];
    if(!str)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(str,ob.get_str());

    
}

STRING &STRING::operator=(const STRING &b)
{
    if(this == &b)
        return *this;
    
    N = b.N;
    delete [] str;
    str = new char [N+1];
    if(!str)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(str,b.str); 
    return *this;
}

char &STRING::operator[](int i)
{
    if(i>=0 && i<=N)
        return str[i];
    else
        cout << "Index Out Of Bounds" << endl;
        exit(1312);
}

bool STRING::operator>(const STRING &b)
{
    if(strcmp(str,b.str)>0)
        return true;
    else
        return false; 
}

bool STRING::operator<(const STRING &b)
{
    if(strcmp(str,b.str)<0)
        return true;
    else
        return false; 
}

bool STRING::operator==(const STRING &b)
{
    if(strcmp(str,b.str)==0)
        return true;
    else
        return false; 
}

ostream &operator<<(ostream &left,STRING &right)
{
    left << right.get_str() << endl;

    return left;
}

istream &operator>>(istream &left,STRING &right)
{
    char in_str[80];
    left >> in_str;

    if(right.str != NULL)
    {
        delete [] right.str;
    }
        
    right.N = strlen(in_str);

    right.str = new char [right.N + 1];
    if(!right.str)
    {
        cout << "Error Allocating Memory";
        exit(1312);
    }

    strcpy(right.str,in_str);

    return left;
}