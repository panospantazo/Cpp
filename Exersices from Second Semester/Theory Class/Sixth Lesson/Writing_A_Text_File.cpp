// Write a text file

#include <iostream>
#include <fstream>
using namespace std;


int main(void)
{
    fstream file;

    file.open("example.txt", ios::out | ios::app );
    if(file.is_open())
    {
        file << "This is a line" << endl;
        file << "To kappakeepo" << endl;
        file << "sotiriou";
        file.close();
    }

    return 0;
}