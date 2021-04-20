#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class BankClient
{
private:
    string surname;
    string name;
    string lastname;
    string adress;
    string phoneNum;
    string accountNum;
    double money;
    double overdraftLimit;
public:
    void setSurname(string surname);

    void setName(string name);

    void setLastName(string lastname);

    void setAdress(string adress);

    void setPhoneNum(string phoneNum);

    void setAccountNum(string accountNum);

    void setMoney(double money);

    void setOverdraftLimit(double overdraftLimit);

    string getSurname();

    string getName();
 
    string getLastName();
 
    string getAdress();
 
    string getPhoneNum();
 
    string getAccountNum();
 
    double getMoney();

    double getOverdraftLimit();
    
    void print();
    
    BankClient();
    BankClient(string surname,string name,string lastname,string adress, string phoneNum, string accountNum, double money, double overdraftLimit);
    ~BankClient();
    BankClient(const BankClient &copy);
    

};
