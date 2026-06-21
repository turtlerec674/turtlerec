#pragma once
#include <vector>

struct Wallet {
    int userId;
    int tokens;
    int credits;
};

class CurrencyManager {
public:
    static Wallet createWallet(int userId);
    static Wallet* getWallet(int userId);
    static bool addTokens(int userId, int amount);
    static bool spendTokens(int userId, int amount);
    static int count();
};
