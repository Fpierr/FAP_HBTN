#!/usr/bin/python3
"""Bank System Fanuel"""

class Bank:
    """Simple bank system to manage account operations."""


    def __init__(self, balance: list):
        """Initialize with a list of account balances."""
        self.balance = balance

    def isValidAccount(self, account: int) -> bool:
        """Check if account number is valid."""
        return 1 <= account <= len(self.balance)

    def deposit(self, account: int, money: int) -> bool:
        """Deposit money into account."""
        if not self.isValidAccount(account):
            return False
        self.balance[account - 1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        """Withdraw money from account."""
        if not self.isValidAccount(account) or self.balance[account - 1] < money:
            return False
        self.balance[account - 1] -= money
        return True

    def transfer(self, from_account: int, to_account: int, money: int) -> bool:
        """Transfer money between accounts."""
        if (not self.isValidAccount(from_account) or 
            not self.isValidAccount(to_account) or 
            self.balance[from_account - 1] < money):
            return False
        self.balance[from_account - 1] -= money
        self.balance[to_account - 1] += money
        return True

    def check_balance(self, account: int) -> int:
        """Check account balance."""
        if not self.isValidAccount(account):
            return -1
        return self.balance[account - 1]
