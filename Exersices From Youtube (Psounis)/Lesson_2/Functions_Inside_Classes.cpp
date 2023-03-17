//Learning to put classes's functions inside classes
#include <iostream>
using namespace std;

class human
{
    public:
        void checks_mood_dog()
        {
            cout << "How are you azor?" << endl;
        }

        void demand_bark()
        {
            cout <<"Azor, please bark twice for me" << endl;
        }

};


class dog
{
    public:
        
        void set_mood(int in_mood)
        {
            mood = in_mood;
        }
        
        void bark()
        {
            cout << "bark" << endl;
        }
        
        void report_mood()
        {
            if(mood>5)
            {
                cout << "I am cool" << endl;
            }
            else
            {
                cout << "I am furious" << endl;
            }
        }


    private:
        int mood;
};

int main(void)
{
    dog azor;
    human owner;
    
    azor.set_mood(3);
    owner.checks_mood_dog();
    azor.report_mood();
    owner.demand_bark();
    azor.bark();
    azor.bark();
    
    return 0;
}