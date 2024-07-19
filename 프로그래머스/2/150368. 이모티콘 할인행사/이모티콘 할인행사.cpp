#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubscribers = 0;
int maxSales = 0;
vector<int> discounts = {10, 20, 30, 40};

void backtrack(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& currentDiscounts, int index) {
    if (index == emoticons.size()) {
        int joinCount = 0;
        int saleAmount = 0;
        for (auto& user: users) {
            int amount = 0;
            for (int i = 0; i < currentDiscounts.size(); i++) {
                if (user[0] <= currentDiscounts[i]) {
                    amount += emoticons[i] - (emoticons[i] / 100 * currentDiscounts[i]);
                }
            }
            if (amount >= user[1]) {
                joinCount++;
            } else {
                saleAmount += amount;
            }
        }
        if (maxSubscribers < joinCount) {
            maxSubscribers = joinCount;
            maxSales = saleAmount;
        } else if (maxSubscribers == joinCount) {
            maxSales = max(maxSales, saleAmount);
        }
        return;
    }
    for (int i = 0; i < discounts.size(); i++) {
        currentDiscounts[index] = discounts[i];
        backtrack(users, emoticons, currentDiscounts, index + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> currentDiscounts(emoticons.size(), 0);

    backtrack(users, emoticons, currentDiscounts, 0);

    return {maxSubscribers, maxSales};
}
