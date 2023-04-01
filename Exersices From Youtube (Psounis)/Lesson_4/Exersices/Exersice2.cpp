#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class STRING
{
    public:
        STRING();
        STRING(char *);
        STRING(const STRING &); 
        ~STRING();
        char * get_str()  const;
        int get_N()  const; 
        void set_N(int); 
        void set_str(char *);
        void print_str();
    private:
        char *str;
        int N;

};

int main(void)
{
    char s[80] = "This is a string";
    STRING s1(s);
    STRING s2 = s1;
    strcpy(s,"This is a new string");
    s2.set_str(s);  
    s1.print_str();
    s2.print_str();
    
    return 0;
}

STRING::STRING()
{
    str = NULL;
    N = 0;
}

STRING::STRING(char *arr)
{
    N = strlen(arr);
    str = new char [N];
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
    str = new char [N];
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
   str = new char [N];
    if(!str)
    {
        cout << "Error Allocating Memory" << endl;
        exit(1312);
    }
    strcpy(str,ob.get_str());

    
}

void STRING::print_str()
{
    cout << str << endl;
}