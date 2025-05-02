class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, string holderName, double balance, double limit)
        : BankAccount(accNum, holderName, balance), overdraftLimit(limit) {}

    
    {
        if (amount > 0 && amount <= (getBalance() + overdraftLimit)) 
        {
            double newBalance = getBalance() - amount;
            // Assuming we want to allow overdraft, we can check if it goes below zero
            if (newBalance < 0) {
                cout << "Warning: Overdraft limit exceeded!" << endl;
            }
            BankAccount::withdraw(amount); // Call the base class withdraw
        } else {
            cout << "Withdrawal exceeds overdraft limit" << endl;
        }
    }

    void displayAccountInformation() 
    {
        BankAccount::displayAccountInformation(); 
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};


