#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int answer = 0;
    int n;
    cin >> n;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
       int start = 0;
       int end = n - 1;
       while (start < end) {
           if (start == i) {
               start++;
               continue;
           }
           if (end == i) {
               end--;
               continue;
           }

           int sum = v[start] + v[end];
           if (v[i] > sum) {
               start++;
           } else if (v[i] < sum) {
               end--;
           } else {
               answer++;
               break;
           }
       }
    }
    cout << answer;
    return 0;
}
