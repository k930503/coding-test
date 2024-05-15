//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
//    int m;
//    cin >> m;
//    vector<int> colorCount(m);
//    int n = 0;
//    for (int i = 0; i < m; i++) {
//        cin >> colorCount[i];
//        n += colorCount[i];
//    }
//    int k;
//    cin >> k;
//
//    double answer = 0.0;
//    for (int i = 0; i < m; i++) {
//        double probability = 1.0;
//        if (colorCount[i] >= k) {
//            for (int j = 0; j < k; j++) {
//                probability *= (double)(colorCount[i] - j) / (n - j);
//            }
//        }
//        answer += probability;
//    }
//    cout << fixed;
//    cout.precision(9);
//    cout << answer;
//    return 0;
//}
#include <iostream>
using namespace std;

static int M, K, T;
static int D[51];
static double probability[51];
static double ans = 0.0;

int main() {
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> D[i];
        T += D[i];
    }

    cin >> K;

    for (int i = 0; i < M; i++) {
        if (D[i] >= K) {
            probability[i] = 1.0;
            for (int k = 0; k < K; k++) {
                probability[i] *= (double)(D[i] - k) / (T - k);
            }
        }
        ans += probability[i];
    }
    cout << fixed;
    cout.precision(9);
    cout << ans;
}