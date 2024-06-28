#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp(str1.length(), vector<int>(str2.length(), 0));
    std::string::size_type index = str1.find(str2[0]);
    if (index == string::npos) {
        for (int i = 0; i < str1.length(); i++) {
            dp[i][0] = 0;
        }
    } else {
        for (int i = 0; i < str1.length(); i++) {
            if (i < (int)index) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }
    }

    index = str2.find(str1[0]);
    if (index == string::npos) {
        fill(dp[0].begin(), dp[0].end(), 0);
    } else if ((int)index == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else {
            fill(dp[0].begin(), dp[0].begin() + (int)index - 1, 0);
            fill(dp[0].begin() + (int)index, dp[0].end(), 1);
    }


    for (int i = 1; i < str1.length(); i++) {
        for (int j = 1; j < str2.length(); j++) {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int str1Index = (int)str1.length() - 1;
    int str2Index = (int)str2.length() - 1;
    int answer1 = dp[str1Index][str2Index];
    cout << answer1 << '\n';

    vector<char> answer2;
    while (answer2.size() < answer1) {
        if (str1[str1Index] == str2[str2Index]) {
            answer2.push_back(str1[str1Index]);
            str1Index--;
            str2Index--;
        } else if (str1Index == 0 && str2Index > 0 || dp[str1Index][str2Index - 1] >= dp[str1Index - 1][str2Index]) {
            str2Index--;
        } else {
            str1Index--;
        }
    }

    if (answer1 != 0) {
        for (int i = answer1 - 1; i >= 0; i--) {
            cout << answer2[i];
        }
    }
    return 0;
}