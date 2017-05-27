#include "Accountdatabase.h"

AccountDatabase :: AccountDatabase () {
    toa = 0;
}

AccountDatabase :: ~AccountDatabase() {}

void AccountDatabase :: Handle() {
    char ch = 0;
    while (ch != 'n') {
        int select;
        cout << "Press 1: to add user info" << endl;
        cout << "Press 2: to edit user info" << endl;
        cout << "Press 3: to delete user info" << endl;
        cout << "Press 4: to withdraw money" << endl;
        cout << "Press 5: to deposite money" << endl;
        cout << "Press 6: to show one account info" << endl;
        cout << "Press 7: to show all account info" << endl;

        cin >> select;
        switch (select) {
        case 1:
            AddUser();
            break;
        case 2:
            EditUser();
            break;
        case 3:
            DeleteUser();
            break;
        case 4:
            Withdraw();
            break;
        case 5:
            Deposite();
            break;
        case 6:
            Display();
            break;
        case 7:
           Displayall();
            break;
        default:
            cout << "You press wrong key" << endl;
            break;
        }
        cout << "Press n to exit: ";
        cin >> ch;
    }
}


void AccountDatabase :: AddUser() {
    string fn, ln, an;
    double b;
    cout << "Put first name: ";
    cin >> fn;
    cout << "Put last name: ";
    cin >> ln;
    cout << "Put account no: ";
    cin >> an;
    cout << "Put balance: ";
    cin >> b;
    if (!CheckInfo(an)) {
        if (toa >= SIZE) {
            cout << "Array is already full" << endl;
            return;
        }
        AccountHolderInfo nah(fn, ln, an, b);
        AHA[toa] = nah;
        toa++;
    }
}

void AccountDatabase :: EditUser() {
    string an;
    cout << "Put account no: ";
    cin >> an;
    if (CheckInfo(an)) {
        cout << "Press 1: to change first name" << endl;
        cout << "Press 2: to change last name" << endl;
        cout << "Press 3: to change first & last name" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:{
            cout << "Put your new first name: ";
            string fn;
            cin >> fn;
            for (int i = 0; i < toa; i++) {
                if (AHA[i].GetAccountNo() == an) {
                    AHA[i].SetFirstName(fn);
                }
            }
        }
        break;
        case 2: {
            cout << "Put your new last name: ";
            string ln;
            cin >> ln;
            for (int i = 0; i < toa; i++) {
                if (AHA[i].GetAccountNo() == an) {
                    AHA[i].SetLastName(ln);
                }
            }
        }
        break;
        case 3: {
            cout << "Put your new first name: ";
            string fn, ln;
            cin >> fn;
            cout << "Put your new last name: ";
            cin >> ln;
            for (int i = 0; i < toa; i++) {
                if (AHA[i].GetAccountNo() == an) {
                    AHA[i].SetFirstName(fn);
                    AHA[i].SetLastName(ln);
                }
            }
        }
        break;
        default:
            cout << "You press wrong key" << endl;
            break;
        }
    }
    else {
        cout << "Account no does not exist" << endl;
    }

}

bool AccountDatabase :: CheckInfo(string an) {
    for (int i = 0; i < toa; i++) {
        if (AHA[i].GetAccountNo() == an) return true;
    }
    return false;
}

void AccountDatabase :: DeleteUser() {
    int pos;
    string an;
    cout << "Put account no: ";
    cin >> an;
    for (int i = 0; i < toa; i++) {
        if (AHA[i].GetAccountNo() == an) pos = i;
    }

    for (int i = pos; i <toa; i++) {
        AHA[i] = AHA[i + 1];
    }
    toa--;
}

void AccountDatabase :: Withdraw()
{
   string an;
    cout<<"Enter account number";
    cin>>an;
    if (CheckInfo(an))
    {
       for(int i=0;i<toa;i++)
    {
        if(AHA[i].GetAccountNo() == an)
        {
            cout<<"Enter ammount"<<endl;
            double b;
            cin>>b;
            if(b<AHA[i].GetBalance())
            {
                AHA[i].SetBalance(AHA[i].GetBalance()-b);
                break;
            }
            else
            {
                cout<<"You do not have enough money"<<endl;
                break;
            }
        }
    }
    }
    else
    {
        cout<<"You have entered wrong account num"<<endl;
    }
}

void AccountDatabase :: Deposite()
{
    string an;
    cout<<"Enter account number";
    cin>>an;
    if (CheckInfo(an))
    {
       for(int i=0;i<toa;i++)
    {
        if(AHA[i].GetAccountNo() == an)
        {
            cout<<"Enter ammount"<<endl;
            double b;
            cin>>b;

                AHA[i].SetBalance(AHA[i].GetBalance()+b);
                break;
        }
    }
    }
    else
    {
        cout<<"You have entered wrong account num"<<endl;
    }

}

void AccountDatabase :: Display()
{
    string an;
    cout<<"Enter account number";
    cin>>an;
    if (CheckInfo(an))
    {
       for(int i=0;i<toa;i++)
    {
        if(AHA[i].GetAccountNo() == an)
        {
            AHA[i].Show();
        }

    }

    }
}

void AccountDatabase :: Displayall()
{
    for(int i=0;i<toa;i++)
    {
        AHA[i].Show();
        cout<<endl<<endl;
    }

}
