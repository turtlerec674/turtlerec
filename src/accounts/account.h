#pragma once
#include <string>
#include <vector>

struct Account {
    int id;
    std::string username;
    std::string email;
};

class AccountManager {
public:
    static Account createAccount(const std::string& username, const std::string& email);
    static int count();
    static std::vector<Account> getAccounts();
};
