#include <iostream>
#include <fstream>
using namespace std;

bool FileCopy(char *,char *);

int main(void)
{
    istream f1;
    ostream f2;

    f1.open("input.txt", ios::out);

    if(f1.is_open())
    {
        f1 << "To kappakeepo";
        f1.close();
    }

    FileCopy(f1,f2);

    f2.open("input.txt", ios::in);

    if(f2.is_open())
    {
        f2 << 
    }
}

bool FileCopy(char *Sf , char * Df)
{
    char buf[4096];
    int size;

    ifstream inp(Sf,ios::binary);
    
    if(inp.good())
    {
        return false;
    }
    
    ifstream out(Df,ios::binary);
    
    if(!out.is_open())
    {
        return false;
    }

    while(size = inp.read(buf,4096))
    {
        out.write(buf,size);
    }

    inp.close();
    out.close();
    return true;
}