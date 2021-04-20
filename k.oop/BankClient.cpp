#include "BankClient.h"

    void BankClient::setSurname(string surname)
    {
        this->surname = surname;
    }
    void BankClient::setName(string name)
    {
        this->name = name;
    }
    void BankClient::setLastName(string lastname)
    {
        this->lastname = lastname;
    }
    void BankClient::setAdress(string adress)
    {
        this->adress = adress;
    }
    void BankClient::setPhoneNum(string phoneNum)
    {
        this->phoneNum = phoneNum;
    }
    void BankClient::setAccountNum(string accountNum)
    {
        this->accountNum = accountNum;
    }
    void BankClient::setMoney(double money)
    {
        this->money = money;
    }
    void BankClient::setOverdraftLimit(double overdraftLimit)
    {
        this->overdraftLimit = overdraftLimit;
    }
    string BankClient::getSurname()
    {
        return surname;
    }
    string BankClient::getName()
    {
        return name;
    }
    string BankClient::getLastName()
    {
        return lastname;
    }
    string BankClient::getAdress()
    {
        return adress;
    }
    string BankClient::getPhoneNum()
    {
        return phoneNum;
    }
    string BankClient::getAccountNum()
    {
        return accountNum;
    }
    double BankClient::getMoney()
    {
        return money;
    }
    double BankClient::getOverdraftLimit()
    {
        return overdraftLimit;
    }
    void BankClient::print()
    {
        cout << "|"<<setw(8) << surname << " |"<< setw(7) << name  << " |"<< setw(10) << lastname  << " |"<< setw(18) << adress  << " |"<< setw(13) << phoneNum  << " |"<< setw(15) << accountNum  << " |"<< setw(8) << money  << " |" << setw(16) << overdraftLimit  << " |" << endl;
    }
    BankClient::BankClient()
    {
        surname = "noname";
        name = "noname";
        lastname = "noname";
        adress = "noadress";
        phoneNum="nodata";
        accountNum = "nodata";
        money=0.0;
        overdraftLimit=0.0;
        cout << "Default Constructor is Used " << this << endl;
    }
    BankClient::BankClient(string surname, string name, string lastname, string adress, string phoneNum, string accountNum, double money, double overdraftLimit)
    {
         this->surname=surname;
         this->name = name;
         this->lastname = lastname;
         this->adress = adress;
         this->phoneNum = phoneNum;
         this->accountNum = accountNum;
         this->money = money;
         this->overdraftLimit = overdraftLimit;
         cout << "Constructor With Parameters is Used " << this << endl;
    }
    BankClient::~BankClient()
    {
    }
    BankClient::BankClient(const BankClient& copy)
    {
        surname = copy.surname;
        name = copy.name;
        lastname = copy.lastname;
        adress = copy.adress;
        phoneNum = copy.phoneNum;
        accountNum = copy.accountNum;
        money = copy.money;
        overdraftLimit = copy.overdraftLimit;
        cout << "Copy Constructor is Used " << this << endl;
    }

