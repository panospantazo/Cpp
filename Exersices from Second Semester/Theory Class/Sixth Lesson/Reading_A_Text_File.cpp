// reading a text file, with problem in Loop because of EOF in last row.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main () {
  char buffer[256];
  ifstream examplefile ("example.txt");
  
  if (! examplefile.is_open())
  { cout << "Error opening file"; exit (1); }

  
  while (!examplefile.eof())
  {
    examplefile.getline (buffer,100);
    cout << buffer << endl;
  }
  
  return 0;
}
