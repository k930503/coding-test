#include <string>
#include <vector>
using namespace std;

string vowel[5] = {"A", "E", "I", "O", "U"};
int count = -1;

bool dfs(string current, string word) {
    count++;
    if (current == word) {
        return true;
    }
    if (current.length() == 5) {
        return false;
    }
    
    for (int i = 0; i < 5; i++) {
        bool isFound = dfs(current + vowel[i], word);
        if (isFound) {
            return true;
        }
    }
    return false;
}

int solution(string word) {
    dfs("", word);
    return count;
}