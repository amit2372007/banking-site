#include<iostream>
#include<vector>

using namespace std;
class BankAccount {
    public:
       string Name;
       double AccNumber;
       double AccBalance;

       BankAccount(string name,double accNum,double initBalance) {
        this->Name = name;
        this->AccNumber = accNum;
        this->AccBalance = initBalance;
       }
       void deposit(double amount) {
        if (amount > 0) {
            this->AccBalance = AccBalance+amount;
            cout << "INR" << amount << "succefully Deposite" << endl;
        } else {
            cout << "Invalid Amount" << endl;
        }
       }
       void withdraw(double amount) {
        if (amount <= AccBalance && amount > 0) {
            this->AccBalance = AccBalance - amount;
            cout << "INR " << amount << " succefully Withdraw" << endl;
            cout << "Current Balance : INR" << AccBalance << endl;
        } else {
            cout << "Invalid Amount or Insufficient Balance" << endl;
        }
       }
       void AccountDetails() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Holder: " << this->Name << endl;
        cout << "Account Number: " << this->AccNumber << endl;
        cout << "Current Balance: ₹" << this->AccBalance << endl;
       }

};
int main () {
    vector<BankAccount> accounts; // Stores multiple bank accounts
    int choice;
    
    while (true) {
        cout << "\n==== Bank Management System ====\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {  // create a account
            string name;
            double accNo;
            double initialDeposit;

            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Deposit Amount: ₹";
            cin >> initialDeposit;

            BankAccount newAccount(name, accNo, initialDeposit);
            accounts.push_back(newAccount);
            cout << "Account Created Successfully!\n";
        } else if(choice == 2) {   // Deposite 
            int accNo;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (auto &acc : accounts) {
                if (accNo == accNo) { // Searching for the account
                    cout << "Enter Deposit Amount: ₹";
                    cin >> amount;
                    acc.deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!\n";
            }
        } else if(choice == 3) {   //withdraw
            int accNo;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (auto &acc : accounts) {
                if (accNo == accNo) { // Searching for the account
                    cout << "Enter Withdrawal Amount: ₹";
                    cin >> amount;
                    acc.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!\n";
            }
        } else if (choice == 4) {    //Display Details
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (auto &acc : accounts) {
                if (accNo == accNo) { // Searching for the account
                    acc.AccountDetails();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Account not found!\n";
            }
        } else if(choice == 5) {   //Exit
            cout << "Thank you for using the Bank Management System!\n";
            break;

        } else {
            cout << "Invalid choice! Please try again.\n";
        }

    }
    
    return 0;
}