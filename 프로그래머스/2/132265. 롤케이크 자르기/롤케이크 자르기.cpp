#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> chulsoo;
    unordered_map<int, int> brother;
    chulsoo[topping[0]] = 1;
    for (int i = 1; i < topping.size(); i++) {
        brother[topping[i]]++;
    }
    for (int i = 1; i < topping.size(); i++) {
        chulsoo[topping[i]]++;
        brother[topping[i]]--;
        if (brother[topping[i]] == 0) {
            brother.erase(topping[i]);
        }
        if (chulsoo.size() == brother.size()) {
            answer++;
        }
    }
    
    return answer;
}