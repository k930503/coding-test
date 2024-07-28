#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<bool> visited;
vector<vector<int>> adjacentList;
vector<int> cardCount;
void dfs(int node, int& count) {
    visited[node] = true;
    count++;
    for (int next: adjacentList[node]) {
        if (!visited[next]) {
            dfs(next, count);
        }
    }
}

int solution(vector<int> cards) {
    visited.assign(cards.size() + 1, false);
    adjacentList.assign(cards.size() + 1, vector<int>(0));
    for (int i = 0; i < cards.size(); i++) {
        adjacentList[i + 1].push_back(cards[i]);
        adjacentList[cards[i]].push_back(i + 1);
    }
    
    for (int card: cards) {
        if (!visited[card]) {
            int count = 0;
            dfs(card, count);
            cardCount.push_back(count);
        }
    }
    
    sort(cardCount.rbegin(), cardCount.rend());
    if (cardCount.size() > 1) {
        return cardCount[0] * cardCount[1];
    } else {
        return 0;
    }
}