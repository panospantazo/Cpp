#include <iostream>
using namespace std;


class array
{   
    public:
        array(int );
        array(const array &);
        ~array();
        
        void print_array();
       
        int get_N() const;
        
        int &operator[](int );
        array operator+=(int );
        array &operator= (array &);

        friend ostream &operator<<(ostream &,array &);  //!

        static int MAX_LENGTH;
    private:
        int *p;
        int N;

};

int array::MAX_LENGTH = 1000;