//This program teaches private and public data of classes

class cow
{
    public:
        int weight;
    private:
        int hunger;
};

int main(void)
{
    cow molly;
    molly.weight = 500;
    //molly.hunger = 10; //  We aren't allow to do that because hunger is a private data of the class cow
    return 0;
}