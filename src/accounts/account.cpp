#include "account.h"

static std::vector<Account> accounts;
static int nextAccountId = 1;

Account AccountManager::createAccount(const std::string& username, const std::string& email) {
    Account account{nextAccountId++, username, email};
    accounts.push_back(account);
    return account;
}

int AccountManager::count() {
    return accounts.size();
}

std::vector<Account> AccountManager::getAccounts() {
    return accounts;
}
