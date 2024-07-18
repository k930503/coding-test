#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubscribers = 0;
int maxSales = 0;

void backtrack(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discounts, vector<int>& currentDiscounts, int index) {
    if (index == emoticons.size()) {
        int totalSales = 0;
        int subscribers = 0;

        for (auto& user : users) {
            int minDiscount = user[0];
            int minPrice = user[1];
            int purchaseAmount = 0;

            for (int i = 0; i < emoticons.size(); ++i) {
                if (currentDiscounts[i] >= minDiscount) {
                    purchaseAmount += emoticons[i] * (100 - currentDiscounts[i]) / 100;
                }
            }

            if (purchaseAmount >= minPrice) {
                subscribers += 1;
            } else {
                totalSales += purchaseAmount;
            }
        }

        if (subscribers > maxSubscribers || (subscribers == maxSubscribers && totalSales > maxSales)) {
            maxSubscribers = subscribers;
            maxSales = totalSales;
        }

        return;
    }

    for (int discount : discounts) {
        currentDiscounts[index] = discount;
        backtrack(users, emoticons, discounts, currentDiscounts, index + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discounts = {10, 20, 30, 40};
    vector<int> currentDiscounts(emoticons.size(), 0);

    backtrack(users, emoticons, discounts, currentDiscounts, 0);

    return {maxSubscribers, maxSales};
}
