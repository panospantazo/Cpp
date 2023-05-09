#include <iostream>
using namespace std;

class complex
{
    public:
        complex();
        complex(double ,double );
        
        void set_real(double );
        void set_imag(double );
        
        double get_real() const;
        double get_imag() const;
        
        complex operator+ (const complex &);
        complex operator+ (const int );   
        complex operator++ (const int );
        complex &operator++();           
        complex &operator=(const complex &);   
        friend complex operator+(int ,complex &);   
        friend ostream &operator<<(ostream &,const complex &);
    private:
        double real;
        double imag;
};

complex operator+(int ,complex &);
ostream &operator<<(ostream &, complex &);

int main(void)
{
    complex a(1.0,2.0);
    complex b(2.0,3.0);
    complex c;

    
    b = a;
    cout << "a:" << a.get_real() << " " << a.get_imag() << endl;
    cout << "b:" <<b.get_real() << " " << b.get_imag() << endl;

    c = a+b;

    cout << c.get_real() <<" "<<c.get_imag() << endl;
    
    
    c = a + 5;
    cout << c.get_real() << " " << c.get_imag() << endl;

    c = b++;
    cout << c.get_real() << " " << c.get_imag() << endl;

    c = ++a;
    cout << c.get_real() << " " << c.get_imag() << endl;
    
   
    b = a;
    cout << "a:" << a.get_real() << " " << a.get_imag() << endl;
    cout << "b:" <<b.get_real() << " " << b.get_imag() << endl;

    c.set_imag(2.0);
    c.set_real(2.0);

    a.set_imag(2.0);
    a.set_real(2.0);

    c = 5 + a;

    cout << "c:(" << c.get_imag() << "," << c.get_real() << ")" <<endl;

    cout << "c:"<< c;


    return 0;
}

complex::complex()
{
    real = 0.0;
    imag = 0.0;
}

complex::complex(double in_real,double in_imag)
{
    real = in_real;
    imag = in_imag;
}

void complex::set_real(double in_real)
{
    real = in_real;
}

void complex::set_imag(double in_imag)
{
    imag = in_imag;
}

double complex::get_real() const
{
    return real;
}

double complex::get_imag() const
{
    return imag;
}

complex complex::operator+(const complex &b)
{
    return complex(real+b.real, imag+b.imag);
}

complex complex::operator+(const int b)     
{
    return complex(real + b , imag + b);
}

complex complex::operator++(const int b) 
{
    complex result = *this;

    real++;
    imag++;
    return result;
}

complex &complex::operator++()            
{   
    real += 1;
    imag += 1;
    return *this;
}

complex &complex::operator=(const complex &b)  //!
{
    if(this == &b) 
        return *this;
    real = b.real;
    imag = b.imag;
    return *this;
}

complex operator+(int left,complex &right)
{
    complex result;

    result.real = left + right.real;
    result.imag = left + right.imag;
    return result;
}

ostream &operator<<(ostream &left,complex &right)
{
    left << "(" << right.get_real() << "," << right.get_imag() << ")";

    return left;
}