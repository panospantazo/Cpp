

class humanoid
{
    public:
        humanoid();
        humanoid &operator-=(const int&);
        int attack();
        bool check_dead();
    private:
        int health;

};