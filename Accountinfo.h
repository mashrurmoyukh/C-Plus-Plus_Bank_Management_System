#ifndef ACCOUNTHOLDERINFO_H_INCLUDED
#define ACCOUNTHOLDERINFO_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class AccountHolderInfo {
public:
    AccountHolderInfo ();
    AccountHolderInfo (string fn, string ln, string an, double bn);
    ~AccountHolderInfo ();
    void SetFirstName (string fn);
    void SetLastName (string ln);
    void SetAccountNo (string an);
    void SetBalance (double b);
    string GetFirstName ();
    string GetLastName ();
    string GetAccountNo ();
    double GetBalance ();
    void Show();
private:
    string first_name;
    string last_name;
    string account_no;
    double balance;
};

#endif // ACCOUNTHOLDERINFO_H_INCLUDED
