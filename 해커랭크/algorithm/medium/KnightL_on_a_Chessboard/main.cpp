#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef pair<int, int> point;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'knightlOnAChessboard' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> answer;
    answer.assign(n - 1, vector<int>(n - 1, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i > j) {
                continue;
            }
            int dx[4] = {1, 1, -1, -1};
            int dy[4] = {1, -1, 1, -1};
            vector<vector<bool>> visited;
            visited.assign(n, vector<bool>(n, false));
            queue<point> q;
            q.emplace(0, 0);
            visited[0][0] = true;
            int count = 0;
            int level = 0;
            int curDepthSize = 1;

            bool isPossible = false;
            while (!q.empty()) {
                point current = q.front();
                q.pop();
                count++;
                if (current.first == n - 1 && current.second == n - 1) {
                    isPossible = true;
                    break;
                }
                for (int k = 0; k < 4; k++) {
                    int nextX = current.first + i * dx[k];
                    int nextY = current.second + j * dy[k];
                    if (nextX > -1 && nextY > -1 && nextX < n && nextY < n) {
                        if (!visited[nextX][nextY]) {
                            q.emplace(nextX, nextY);
                            visited[nextX][nextY] = true;
                        }
                    }
                    nextX = current.first + j * dx[k];
                    nextY = current.second + i * dy[k];
                    if (nextX > -1 && nextY > -1 && nextX < n && nextY < n) {
                        if (!visited[nextX][nextY]) {
                            q.emplace(nextX, nextY);
                            visited[nextX][nextY] = true;
                        }
                    }
                }
                if (count == curDepthSize) {
                    count = 0;
                    level++;
                    curDepthSize = q.size();
                }
            }
            if (isPossible) {
                answer[i - 1][j - 1] = level;
                answer[j - 1][i - 1] = level;
            } else {
                answer[i - 1][j - 1] = -1;
                answer[j - 1][i - 1] = -1;
            }
        }
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
