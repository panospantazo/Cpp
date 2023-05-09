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
        STRING &operator=(const STRING &);   //!
        char &operator[](int);               //!
        bool operator>(const STRING &);     //!
        bool operator<(const STRING &);     //!
        bool operator==(const STRING &);    //!
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
    cout<<"----------------------------" << endl;
    s1 = s2;
    s1.print_str();
    s2.print_str();
    cout<<"----------------------------" << endl;
    s1[3] = 'g';
    s1.print_str();
    
    if(s1 == s2)
        cout <<"SUIIIIIIIIIIII" << endl;
    else
        cout << "To kappakeepo" << endl;
    
    s1[3] = 's';
    
    if(s1 == s2)
        cout <<"SUIIIIIIIIIIII" << endl;
    else
        cout << "To kappakeepo" << endl;

    
    return 0;
}

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

void STRING::print_str()
{
    cout << str << endl;
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