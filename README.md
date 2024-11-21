1. What does the program do?

Simulates deposits and withdrawals from a shared bank account balance.
Uses a mutex to ensure thread-safe updates to the shared balance.

2. Why is the mutex needed?

The mutex prevents two threads from accessing or modifying the account_balance at the same time, avoiding data corruption.
What happens without the mutex?

Without the mutex, the balance might be updated incorrectly due to simultaneous access by multiple threads.
