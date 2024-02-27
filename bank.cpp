// Design a Customer class for a bank system that manages customer information and basic operation

#include<iostream>
#include<stdlib.h>
using namespace std;

class Customer
{
    string name;
    int accountNumber;
    int accountBalance = 1000;
public:
    int deposit,remain,tar,trans;
    void setName(string name)
    {
        if(name.size()==0){
            cout<<"invalid name."<<endl;
        }
        this->name = name;
    }
    void setAccountNumber(int ac)
    {
        accountNumber = ac;
    }
    int balance()
    {   
        if(accountBalance == 0){
            cout<<"You have to pay fine for keeping the bank account empty."<<endl;
        }
        else{
            cout<<"Total Balance in Your account: ";
            return accountBalance;
        }
    }
    void depositAmount(int amount)
    {   
        deposit = balance() + amount;
        cout<<deposit;
        accountBalance = deposit;
    }
    void withdraw(int money)
    {   
        if(money>accountBalance)
        {
            cout<<"Insufficient Bank Balance!!"<<endl;
        }
        else if(money<0)
        {
            cout<<"Enter Valid Amount!!"<<endl;
        }
        else{
        cout<<"Withdrwal is successfull!!"<<endl;
        remain = accountBalance - money;
        cout<<"Total Balance in Your account: "<<remain;
        deposit = remain;
        }
        exit(1);
    }
    void transfer(int targetAccount)
    {   
        cout<<"Enter Transfered Amount: ";
        cin>>trans;
        if(accountBalance<=0 || trans>accountBalance)
        {
            cout<<"Insufficient Bank Balance!!"<<endl;
        }
        else if(trans<0)
        {
            cout<<"Enter Valid Amount!!"<<endl;
        }
        else if(targetAccount<0)
        {
            cout<<"The account is not valid. Enter a Valid account number!!"<<endl;
        }
        else{
        tar = accountBalance - trans;
        cout<<"tranfer is successfull!!"<<endl;
        cout<<"Total Balance in Your account: "<<tar<<endl;
        accountBalance = accountBalance - tar;
        }
        cout<<"Thank You!!"<<endl;
        exit(1);
    }
};

int main()
{   
    int Enter,no,am,with,account;
    string n;
    Customer C1;
    cout<<"\n----------Welcome to My OOP Bank---------\n\n";
    cout<<"Enter your name: ";
    cin>>n;
    cout<<"Enter your Account Number: ";
    cin>>no;
    cout<<"Your Minimum Balance is: 1000"<<endl;
    C1.setName(n);
    C1.setAccountNumber(no);
    while(1){
    cout<<"\n\nPlease follow the given instructions\n";
    cout<<"1)Enter 1 for deposit money\n2)Enter 2 for withdrawl money\n3)Enter 3 for Transfer Money\n4)Enter 4 for exit.\nEnter: ";
    cin>>Enter;
    switch(Enter)
    {
        case 1: cout<<"Enter Deposit Amount: ";
                cin>>am;
                C1.depositAmount(am);
                break;
        case 2: cout<<"Enter Withdrawl Amount: ";
                cin>>with;
                C1.withdraw(with);
                break;
        case 3: cout<<"Enter Account Number to be transfered: ";
                cin>>account;
                C1.transfer(account);
                break;
        case 4: exit(1);
                break;
        default: cout<<"Wrong entry!!.";
                break;
    }
    }
}