#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();   
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    
    string temp = "";
    vector<int> current;
    for (int i = 2; i < s.length() - 2; i++) {
        if (s[i] != '{' && s[i] != '}' && s[i] != ',') {
            temp += s[i];
        }
        
        if (s[i + 1] == ',' && s[i] != '}') {
            current.push_back(stoi(temp));
            temp = "";
        } else if (s[i + 1] == '}') {
            current.push_back(stoi(temp));
            v.push_back(current);
            current.clear();
            temp = "";
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    unordered_map<int, bool> used;
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int target = v[i][j];
            if (!used[target]) {
                answer.push_back(target);
                used[target] = true;
            }
        }
    }
    
    return answer;
}