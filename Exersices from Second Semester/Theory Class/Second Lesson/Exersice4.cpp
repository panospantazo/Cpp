//Exersice 4 Lesson 2
#include <iostream>
using namespace std;

class BankAccount
{
    public:
        BankAccount(int accountNumber,string accountHolder,double balance)
        {
            this->accountNumber = accountNumber;
            this->accountHolder = accountHolder;
            this->balance = balance;
        }
    friend void displayAccount(BankAccount ba);


    private:
        int accountNumber;
        string accountHolder;
        double balance;

};

void displayAccount(BankAccount ba)
{
    cout << "Account number:" << ba.accountNumber << endl;
    cout << "Account holder:" << ba.accountHolder << endl;
    cout << "Account balance:" << ba.balance << endl;
}

int main(void)
{
    BankAccount ba(12345,"Christos",150);
    displayAccount(ba);

    return 0;
}