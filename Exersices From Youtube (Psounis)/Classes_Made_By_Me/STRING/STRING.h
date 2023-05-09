#include <iostream>
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
        
    
        
        STRING &operator=(const STRING &);   
        char &operator[](int);               
        bool operator>(const STRING &);     
        bool operator<(const STRING &);     
        bool operator==(const STRING &);
        friend ostream &operator<<(ostream &,STRING &);  
        friend istream &operator>>(istream &,STRING &);   
    private:
        char *str;
        int N;

};