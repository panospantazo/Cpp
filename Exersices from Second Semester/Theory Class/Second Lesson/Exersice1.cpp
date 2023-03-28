//Lesson 2 Exersice 1

#include <iostream>
using namespace std;

class Rectangle
{
    public:
        
        void setlenght(int len)
        {
            lenght = len;
        }

        void setbreadth(int bre)
        {
            breadth = bre;
        }
        
        int area()
        {
            return lenght * breadth;
        }
        
        int perimeter()
        {
            return  2*(lenght+breadth);
        }

    private:
        int lenght;
        int breadth;
};


int main(void)
{
    Rectangle r1;
    
    r1.setlenght(5);
    r1.setbreadth(10);
    
    cout << "THE AREA IS:" << r1.area() << endl;
    cout << "THE PERIMETER IS:" << r1.perimeter() << endl;



    return 0;
}