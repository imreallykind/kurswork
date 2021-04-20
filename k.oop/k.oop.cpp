#include <iostream>
#include <string>
#include "BankClient.h"
#include <conio.h>
#include <vector>
#include <iomanip>

using namespace std;

void menu(int point);
void input(vector<BankClient>& lst);
double check(string p);
int check1(string p);
void output(vector<BankClient>& lst);
void hline();
void deletion(vector<BankClient>& lst);
void editor(vector<BankClient>& lst);

int main()
{
    int mu = 0;
    vector<BankClient>list;
    while (mu != 53)
    {
        menu(0);
        mu = _getch();
        switch (mu)
        {
        case 49:
            system("cls");
            input(list);
            break;
        case 50:
            system("cls");
            output(list);
            break;
        case 51:
            system("cls");
            editor(list);
            break;
        case 52:
            system("cls");
            deletion(list);
            break;
        case 53:
            break;

        default:
            system("cls");
            cout << "Wrong Choise\n\n";
        }
    }
    return 0;
}

void menu(int point)
{
    switch (point)
    {
    case 0:
        cout << "Chose Action" << endl;
        cout << "  1. Input Data\n" << "  2. Output Data\n" << "  3. Change Data\n"
            << "  4. Delete Data\n" << "  5. Exit...\n" << endl;
        break;
        case 1:
            cout << "Chose Action" << endl;
            cout << "  1. All Data \n" << "  2. Output Data by Bank Account Number\n" << "  3. Output Clients With Balance less than Entered\n"
                << "  4. Output Clients Without Overdraft\n" << "  5. Go Back\n" << endl;
            break;
        case 2:
            cout << "Chose Action\n";
            cout << "  1.Surname\n" << "  2.Name\n" << "  3.Last Name\n" << "  4.Address\n" << "  5.Phone number\n"
                << "  6.Bank account number\n" << "  7.Bank account balance\n" << "  8.Overdraft limit\n" << "  9.Go Back" << endl;
            break;
        case 3:
            cout << "| No || Surname |  Name  | Last Name |      Address      | Phone number | Account number | Balance | Overdraft limit |" << endl;
            break;

    default:
        cout << "Menu Error" << endl;
        break;
    }
}

void input(vector<BankClient>& lst)
{
    int amNotes = 0;
    string surname = "noname", name = "noname", lastname = "noname", adress = "noadress", phoneNum = "nodata", accountNum = "nodata";
    double money = 0.0, overdraftLimit = 0.0;
    amNotes = check1("Enter Amount of Notes: ");
    for (int i = 0; i < amNotes; i++)
    {
        cout << "\nSurname: ";
        cin >> surname;
        cout << "Name: ";
        cin >> name;
        cout << "Lastname: ";
        cin >> lastname;
        cout << "Adress: ";
        cin.ignore();
        getline(cin, adress) ;
        cout << "Phone number: ";
        cin >> phoneNum;
        cout << "Bank account number: ";
        cin >> accountNum;
        money=check("Bank account balance: ");
        overdraftLimit = check("Overdraft limit: ");
        cout << "\n";
        lst.push_back(BankClient(surname, name, lastname, adress, phoneNum, accountNum, money, overdraftLimit));
    }
}

double check(string p)
{
    double number;
    while (true)
    {
        cout << p;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
            return number;
    }
}

int check1(string p)
{
    double number;
    while (true)
    {
        cout << p;
        cin >> number;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
            return number;
    }
}

void output(vector<BankClient>& lst)
{
    int size = lst.size();
    string tmp;
    bool searchFlag;
    double sF = 0.0;
    if (size)
    {
        int mu = 0;
        while (mu != 53)
        {
            menu(1);
            mu = _getch();
            switch (mu)
            {
            case 49:
                system("cls");
                hline();
                menu(3);
                hline();
                for (int i = 0; i < size; i++)
                {
                    cout << "|" << setw(3) << i + 1 << " |";
                    lst[i].print();
                }
                hline();
                break;
            case 50:
                system("cls");
                cout << "Enter Needed Account Number\n";
                cin >> tmp;
                searchFlag = false;
                for (int i = 0; i < size; i++)
                    if (lst[i].getAccountNum() == tmp)
                        searchFlag = true;
                if (!searchFlag)
                    cout << "Nothing Found";
                else
                {
                    hline();
                    menu(3);
                    hline();
                    for (int i = 0; i < size; i++)
                    {

                        if (lst[i].getAccountNum() == tmp)
                        {
                            cout << "|" << setw(3) << i + 1 << " |";
                            lst[i].print();
                            searchFlag = true;
                        }

                    }
                    hline();
                }
                cout << "\n\n";
                break;
            case 51:
                system("cls");
                sF = check("Enter Lower Money Threshold: ");
                searchFlag = false;
                for (int i = 0; i < size; i++)
                    if (lst[i].getMoney() <= sF)
                        searchFlag = true;
                if (!searchFlag)
                    cout << "Nothing Found";
                else
                {
                    hline();
                    menu(3);
                    hline();
                    for (int i = 0; i < size; i++)
                    {

                        if (lst[i].getMoney() <= sF)
                        {
                            cout << "|" << setw(3) << i + 1 << " |";
                            lst[i].print();
                            searchFlag = true;
                        }

                    }
                    hline();
                }
                cout << "\n\n";
                break;
            case 52:
                system("cls");
                cout << "Clients Without Overdraft\n";
                searchFlag = false;
                for (int i = 0; i < size; i++)
                    if (lst[i].getOverdraftLimit() <= 0.0)
                        searchFlag = true;
                if (!searchFlag)
                    cout << "Nothing Found";
                else
                {
                    hline();
                    menu(3);
                    hline();
                    for (int i = 0; i < size; i++)
                    {

                        if (lst[i].getOverdraftLimit() <= 0.0)
                        {
                            cout << "|" << setw(3) << i + 1 << " |";
                            lst[i].print();
                            searchFlag = true;
                        }

                    }
                    hline();
                }
                cout << "\n\n";
                break;
            case 53:
                system("cls");
                break;

            default:
                system("cls");
                cout << "Wrong Choise\n";
            }
        }

    }
    else
        cout << "No data entered\n\n";
}

void hline()
{
    int n = 118;
    for (int i = 0; i < n; i++)
        cout << "-";
    cout << "\n";
}

void deletion(vector<BankClient>& lst)
{
    int size = lst.size(), bum;
    if (size)
    {
        hline();
        menu(3);
        hline();
        for (int i = 0; i < size; i++)
        {
            cout << "|" << setw(3) << i + 1 << " |";
            lst[i].print();
        }
        hline();
        bum = check1("Delete note: ");
        if (bum > size || bum <= 0)
            cout << "Nothing Found\n\n";
        else
        {
            auto itor = lst.cbegin();
            lst.erase(itor + bum - 1);
            if (size > lst.size())
                cout << "Data Successful Deleted\n\n";
            else
                cout << "Data Not Deleted\n\n";

        }

    }
    else
        cout << "No Data to Delete\n\n";
}

void editor(vector<BankClient>& lst)
{
    int size = lst.size();
    string Tmp;
    double dTmp;
    if (size)
    {
        int mu = 0, objNum;
        hline();
        menu(3);
        hline();
        for (int i = 0; i < size; i++)
        { 
            cout << "|" << setw(3) << i + 1 << " |";
            lst[i].print();
        }
        hline();
        objNum = check1("Enter Note To Change: ");
        objNum--;
        if (objNum > size || objNum < 0)
            cout << "Nothing Found\n\n";
        else
        { 
            while (mu != 57)
            {
                menu(2);
                mu = _getch();
                switch (mu)
                { 
                case 49:
                    system("cls");
                    cout << "Old Surname: " << lst[objNum].getSurname() << "\n New Surname: ";
                    cin >> Tmp;
                    lst[objNum].setSurname(Tmp);
                    break;
                case 50:
                    system("cls");
                    cout << "Old Name: " << lst[objNum].getName() << "\n New Name: ";
                    cin >> Tmp;
                    lst[objNum].setName(Tmp);
                    break;
                case 51:
                    system("cls");
                    cout << "Old Lastname: " << lst[objNum].getLastName() << "\n New Lastname: ";
                    cin >> Tmp;
                    lst[objNum].setLastName(Tmp);
                    break;
                case 52:
                    system("cls");
                    cout << "Old Address: " << lst[objNum].getAdress() << "\n New Address: ";
                    cin >> Tmp;
                    lst[objNum].setAdress(Tmp);
                    break;
                case 53:
                    system("cls");
                    cout << "Old Phone Number: " << lst[objNum].getPhoneNum() << "\n New Phone Number: ";
                    cin >> Tmp;
                    lst[objNum].setPhoneNum(Tmp);
                    break;
                case 54:
                    system("cls");
                    cout << "Old Account Number: " << lst[objNum].getAccountNum() << "\n New Account Number: ";
                    cin >> Tmp;
                    lst[objNum].setAccountNum(Tmp);
                    break;
                case 55:
                    system("cls");
                    cout << "Old Balance: " << lst[objNum].getMoney() << "\n New Balance: ";
                    dTmp = check("");
                    lst[objNum].setMoney(dTmp);
                    break;
                case 56:
                    system("cls");
                    cout << "Old Overdraft Limit: " << lst[objNum].getOverdraftLimit() << "\n New Overdraft Limit: ";
                    dTmp = check("");
                    lst[objNum].setOverdraftLimit(dTmp);
                    break;
                case 57:
                    system("cls");
                    break;
                default:
                    system("cls");
                    cout << "Wrong Choise\n\n";
                }
            }
        }
    }
    else
        cout << "Data Not Deleted\n\n";
}

