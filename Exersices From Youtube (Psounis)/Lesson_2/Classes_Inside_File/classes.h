class dog
{
    public:
        void bark();
        void report_mood();
        void set_mood(int in_mood);     
    
    private:
        int mood;
};

class human
{
    public:
        void checks_mood_dog();
        void demand_bark();
};