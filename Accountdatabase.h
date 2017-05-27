#ifndef ACCOUNTDATABASE_H_INCLUDED
#define ACCOUNTDATABASE_H_INCLUDED

#include "Accountinfo.h"
#define SIZE 1000

class AccountDatabase {
public:
    AccountDatabase ();
    ~AccountDatabase();
    void Handle();
    void AddUser();
    void EditUser();
    bool CheckInfo(string an);
    void DeleteUser();
    void Withdraw();
    void Deposite();
    void Display();
    void Displayall();
private:
    AccountHolderInfo AHA[SIZE];
    int toa;
};

#endif // ACCOUNTDATABASE_H_INCLUDED
