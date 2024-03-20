#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int answer = 0;
    int s, p;
    string str;
    unordered_map<char, int> acgt;
    unordered_map<char, int> curAcgt;
    unordered_map<string, bool> password;
    int cntA, cntC, cntG, cntT;
    cin >> s >> p >> str >> cntA >> cntC >> cntG >> cntT;

    acgt.insert({'A', cntA});
    acgt.insert({'C', cntC});
    acgt.insert({'G', cntG});
    acgt.insert({'T', cntT});

    curAcgt.insert({'A', 0});
    curAcgt.insert({'C', 0});
    curAcgt.insert({'G', 0});
    curAcgt.insert({'T', 0});

    for (int i = 0; i < p; i++) {
        if (str[i] == 'A') {
            curAcgt['A']++;
        } else if (str[i] == 'C') {
            curAcgt['C']++;
        } else if (str[i] == 'G') {
            curAcgt['G']++;
        } else {
            curAcgt['T']++;
        }
    }

    for (int i = 0; i < s - p + 1; i++) {
        if (acgt['A'] <= curAcgt['A'] && acgt['C'] <= curAcgt['C'] && acgt['G'] <= curAcgt['G'] && acgt['T'] <= curAcgt['T']) {
//            if (password.find(str.substr(i, p)) == password.end()) {
                answer++;
//            }
        }
        curAcgt[str[i]]--;
        curAcgt[str[i + p]]++;
    }
    cout << answer;
    return 0;
}
