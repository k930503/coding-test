#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n, 0);

    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }

    // 오름차순을 구하는 문제지만, 뒷쪽부터 정렬이 되기 때문에 바로 출력하려면 내림차순으로. 아니면 for문을 거꾸로 돌아서 앞쪽부터 오름차순 정렬되게 해서 출력하기.
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] < v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
        cout << v[v.size() - 1 - i] << '\n';
    }
    cout << v[0];
    return 0;
}
