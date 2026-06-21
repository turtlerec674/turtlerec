#include "currency.h"

static std::vector<Wallet> wallets;

Wallet CurrencyManager::createWallet(int userId) {
    Wallet wallet{userId, 0, 0};
    wallets.push_back(wallet);
    return wallet;
}

Wallet* CurrencyManager::getWallet(int userId) {
    for (auto& w : wallets) {
        if (w.userId == userId) return &w;
    }

    return nullptr;
}

bool CurrencyManager::addTokens(int userId, int amount) {
    Wallet* wallet = getWallet(userId);
    if (!wallet) return false;

    wallet->tokens += amount;
    return true;
}

bool CurrencyManager::spendTokens(int userId, int amount) {
    Wallet* wallet = getWallet(userId);
    if (!wallet) return false;
    if (wallet->tokens < amount) return false;

    wallet->tokens -= amount;
    return true;
}

int CurrencyManager::count() {
    return wallets.size();
}
