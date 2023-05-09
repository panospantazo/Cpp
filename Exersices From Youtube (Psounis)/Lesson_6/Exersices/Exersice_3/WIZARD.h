

class wizard
{
    public:
        wizard(int ,char* ,int,int );
        int fireball();
        int lightning();
        void wait();
        wizard &operator+=(const int&);
        wizard &operator-=(const int&);
        void print();
        bool check_dead();
    private:
        int age;
        char beard[80];
        int mana;
        int health;  

};