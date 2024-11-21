#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx; // Define a mutex object.
int account_balance = 1000;

void withdraw(int amount)
{
    mtx.lock(); // Lock the mutex
    if (account_balance >= amount)
    {
        cout << "Withdraw= " << amount << endl;
        account_balance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << account_balance << endl;
    }
    else
    {
        cout << "Insufficient funds. Cannot withdraw " << amount << "." << endl;
    }
    mtx.unlock(); // Unlock the mutex
}

void deposit(int amount)
{
    mtx.lock(); // Lock the mutex
    cout << "Deposit " << amount << endl;
    account_balance += amount;
    cout << "Deposit successful. Current balance: " << account_balance << endl;
    mtx.unlock(); // Unlock the mutex
}

int main()
{

    thread t1(withdraw, 500);
    thread t2(deposit, 300);
    thread t3(withdraw, 700);
    thread t4(withdraw, 200);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "Account balance: " << account_balance << endl;

    return 0;
}
