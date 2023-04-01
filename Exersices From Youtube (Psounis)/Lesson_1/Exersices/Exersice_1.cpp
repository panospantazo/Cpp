//Exersice 1 of the first lesson
#include <iostream>
using namespace std;

int main(void)
{
    char name[30];
    char sirname[30];
    int age;

    cout << "What's your name: ";
    cin  >> name;
    cout << "What's your sirname: ";
    cin  >> sirname;
    cout << "How old are you: ";
    cin >> age;
    cout << sirname << " " << name << " ("<< age << ")" << endl;

    return 0;
}