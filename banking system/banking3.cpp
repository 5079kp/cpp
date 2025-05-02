#include <iostream>
using namespace std;

 
class BankAccount {
private
    string accountNumber;
    string accountHolderName;
    double balance;

public
    BankAccount(string num, string name, double bal)
         accountNumber(num), accountHolderName(name), balance(bal) {}

     Deposit method
    virtual void deposit(double amount) {
        if (amount  0) {
            balance += amount;
            cout  Deposited $  amount  . New balance $  balance  endl;
        } else {
            cout  Invalid deposit amount!  endl;
        }
    }

     Withdrawal method (to be overridden)
    virtual void withdraw(double amount) {
        if (amount  0 && amount = balance) {
            balance -= amount;
            cout  Withdrew $  amount  . New balance $  balance  endl;
        } else {
            cout  Invalid withdrawal or insufficient funds!  endl;
        }
    }

     Get balance
    double getBalance() const { return balance; }

     Display account info
    virtual void displayInfo() const {
        cout  nAccount Number   accountNumber
              nHolder   accountHolderName
              nBalance $  balance  endl;
    }

     Virtual method for interest calculation
    virtual void calculateInterest() {
        cout  No interest for basic account.  endl;
    }

    virtual ~BankAccount() {}
};

 Savings Account
class SavingsAccount  public BankAccount {
private
    double interestRate;

public
    SavingsAccount(string num, string name, double bal, double rate)
         BankAccount(num, name, bal), interestRate(rate) {}

    void calculateInterest() override {
        double interest = getBalance()  interestRate  100;
        deposit(interest);
        cout  Interest added $  interest  endl;
    }

    void displayInfo() const override {
        BankAccountdisplayInfo();
        cout  Type SavingsnInterest Rate   interestRate  %  endl;
    }
};

 Checking Account
class CheckingAccount  public BankAccount {
private
    double overdraftLimit;

public
    CheckingAccount(string num, string name, double bal, double limit)
         BankAccount(num, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount  0 && (getBalance() - amount) = -overdraftLimit) {
            BankAccountwithdraw(amount);
        } else {
            cout  Withdrawal exceeds overdraft limit!  endl;
        }
    }

    void checkOverdraft() const {
        if (getBalance()  0) {
            cout  In overdraft! Amount $  -getBalance()  endl;
        } else {
            cout  No overdraft.  endl;
        }
    }

    void displayInfo() const override {
        BankAccountdisplayInfo();
        cout  Type CheckingnOverdraft Limit $  overdraftLimit  endl;
    }
};

 Fixed Deposit Account
class FixedDepositAccount  public BankAccount {
private
    int term;  in months
    double interestRate;

public
    FixedDepositAccount(string num, string name, double bal, int months, double rate)
         BankAccount(num, name, bal), term(months), interestRate(rate) {}

    void withdraw(double amount) override {
        cout  Cannot withdraw from fixed deposit before maturity!  endl;
    }

    void calculateInterest() override {
        double interest = getBalance()  interestRate  100  (term  12.0);
        deposit(interest);
        cout  Fixed interest added $  interest  endl;
    }

    void displayInfo() const override {
        BankAccountdisplayInfo();
        cout  Type Fixed DepositnTerm   term   monthsnInterest Rate   interestRate  %  endl;
    }
};

 Menu functions
void displayMenu() {
    cout  nBANKING SYSTEM MENUn
          1. Create Savings Accountn
          2. Create Checking Accountn
          3. Create Fixed Deposit Accountn
          4. Depositn
          5. Withdrawn
          6. Calculate Interestn
          7. Check Overdraftn
          8. Display Account Infon
          9. Exitn
          Enter choice ;
}

int main() {
    vectorunique_ptrBankAccount accounts;
    int choice;

    while (true) {
        displayMenu();
        cin  choice;

        if (choice == 9) break;

        switch (choice) {
            case 1 {
                string num, name;
                double bal, rate;
                cout  Enter account number ;
                cin  num;
                cout  Enter holder name ;
                cin.ignore();
                getline(cin, name);
                cout  Enter initial balance ;
                cin  bal;
                cout  Enter interest rate (%) ;
                cin  rate;
                accounts.push_back(make_uniqueSavingsAccount(num, name, bal, rate));
                cout  Savings account created!  endl;
                break;
            }
            case 2 {
                string num, name;
                double bal, limit;
                cout  Enter account number ;
                cin  num;
                cout  Enter holder name ;
                cin.ignore();
                getline(cin, name);
                cout  Enter initial balance ;
                cin  bal;
                cout  Enter overdraft limit ;
                cin  limit;
                accounts.push_back(make_uniqueCheckingAccount(num, name, bal, limit));
                cout  Checking account created!  endl;
                break;
            }
            case 3 {
                string num, name;
                double bal, rate;
                int months;
                cout  Enter account number ;
                cin  num;
                cout  Enter holder name ;
                cin.ignore();
                getline(cin, name);
                cout  Enter initial balance ;
                cin  bal;
                cout  Enter term (months) ;
                cin  months;
                cout  Enter interest rate (%) ;
                cin  rate;
                accounts.push_back(make_uniqueFixedDepositAccount(num, name, bal, months, rate));
                cout  Fixed deposit account created!  endl;
                break;
            }
            case 4 {
                int index;
                double amount;
                cout  Enter account index ;
                cin  index;
                if (index = 0 && index  accounts.size()) {
                    cout  Enter deposit amount ;
                    cin  amount;
                    accounts[index]-deposit(amount);
                } else {
                    cout  Invalid account index!  endl;
                }
                break;
            }
            case 5 {
                int index;
                double amount;
                cout  Enter account index ;
                cin  index;
                if (index = 0 && index  accounts.size()) {
                    cout  Enter withdrawal amount ;
                    cin  amount;
                    accounts[index]-withdraw(amount);
                } else {
                    cout  Invalid account index!  endl;
                }
                break;
            }
            case 6 {
                int index;
                cout  Enter account index ;
                cin  index;
                if (index = 0 && index  accounts.size()) {
                    accounts[index]-calculateInterest();
                } else {
                    cout  Invalid account index!  endl;
                }
                break;
            }
            case 7 {
                int index;
                cout  Enter account index ;
                cin  index;
                if (index = 0 && index  accounts.size()) {
                    CheckingAccount checking = dynamic_castCheckingAccount(accounts[index].get());
                    if (checking) {
                        checking-checkOverdraft();
                    } else {
                        cout  Not a checking account!  endl;
                    }
                } else {
                    cout  Invalid account index!  endl;
                }
                break;
            }
            case 8 {
                int index;
                cout  Enter account index ;
                cin  index;
                if (index = 0 && index  accounts.size()) {
                    accounts[index]-displayInfo();
                } else {
                    cout  Invalid account index!  endl;
                }
                break;
            }
            default
                cout  Invalid choice!  endl;
        }
    }

    return 0;
}
