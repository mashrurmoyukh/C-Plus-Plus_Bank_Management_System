   #include "Accountinfo.h"

    AccountHolderInfo :: AccountHolderInfo() {
        balance = 0;
    }

    AccountHolderInfo :: AccountHolderInfo (string fn, string ln, string an, double bn) {
        first_name = fn;
        last_name = ln;
        account_no = an;
        balance = bn;
    }

    AccountHolderInfo :: ~AccountHolderInfo () {}

    void AccountHolderInfo :: SetFirstName (string fn) {
            first_name = fn;
    }

    void AccountHolderInfo :: SetLastName (string ln) {
            last_name = ln;
    }

    void AccountHolderInfo :: SetAccountNo (string an) {
            account_no = an;
    }

    void AccountHolderInfo :: SetBalance (double b) {
            balance = b;
    }

    string AccountHolderInfo :: GetFirstName () {
        return first_name;
    }

    string AccountHolderInfo :: GetLastName () {
        return last_name;
    }

    string AccountHolderInfo :: GetAccountNo () {
        return account_no;
    }

    double AccountHolderInfo :: GetBalance () {
        return balance;
    }

    void AccountHolderInfo :: Show() {
        cout << "First Name: " << first_name << endl;
        cout << "Last Name: " << last_name << endl;
        cout << "Account No: " << account_no << endl;
        cout << "Balance: " << balance << endl;
    }
