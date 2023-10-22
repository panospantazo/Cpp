#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string s1;
    string s2("Medium");
    string s3("A rather large one");

    cout << "Capacity s1:" << s1.capacity() << endl;
    cout << "Length s1:" << s1.size() << endl;

    cout << "Capacity s2:" << s2.capacity() << endl;
    cout << "Length s2:" << s2.size() << endl;

    cout << "Capacity s3:" << s3.capacity() << endl;
    cout << "Length s3:" << s3.size() << endl;

    s3 += s1 + s2;

    cout << "Capacity s3:" << s3.capacity() << endl;
    cout << "Length s3:" << s3.size() << endl;

    s3.resize(10);

    cout << "Capacity s3:" << s3.capacity() << endl;
    cout << "Length s3:" << s3.size() << endl;

    s3.shrink_to_fit();

    cout << "Capacity s3:" << s3.capacity() << endl;
    cout << "Length s3:" << s3.size() << endl;


    return 0;
}