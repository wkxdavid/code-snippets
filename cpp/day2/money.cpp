// procedural programming: input, process, output
//
//     flow       task             what to use
//     -----------------------------------------------
//     out        initialize       reference parameter
//     in/out     modify           reference parameter
//     in         utilize          value parameter
//     none       local detail     local variable

#include <iostream>

using namespace std;

// This method introduces the program to the user and gets initial balance
void init(double & balance);

// This function processes a series of transactions to update the balance
void update(double & balance);

// This function reports the final balance
void report(double balance);

int main() {
    double money;
    init(money);
    update(money);
    report(money);
}

void init(double & balance) {
    cout << "This program allows you to perform a series of" << endl;
    cout << "transactions for a bank account" << endl << endl;
    cout << "beginning balance? ";
    cin >> balance;
    cout << endl;
}

void update(double & balance) {
    cout << "how many transactions? ";
    int count;
    cin >> count;
    for (int i = 1; i <= count; i++) {
        cout << "    transaction #" << i << "? ";
        double amount;
        cin >> amount;
        balance += amount;
        cout << "    balance now = $" << balance << endl;
    }
    cout << endl;
}

void report(double balance) {
    cout << "final balance = $" << balance << endl;
}