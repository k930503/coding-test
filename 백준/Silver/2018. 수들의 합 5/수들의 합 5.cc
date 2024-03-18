#include <iostream>

using namespace std;

int calculateSequenceSum(int start, int n) {
    return n * (2 * start + n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int start = 1;
    int end = 1;
    int cnt = 0;

    cin >> N;

    while (start <= N) {
        int temp = calculateSequenceSum(start, end - start + 1);
        if (temp == N) {
            cnt++;
            if (end == N) {
                break;
            }
            start++;
            end++;
        } else if (temp > N) {
            start++;
        } else {
            if (end == N) {
                break;
            }
            end++;
        }
    }
    cout << cnt << "\n";
    return 0;
}

// 다른 사람이 나보다 잘 푼 정답.
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n,pos1=1,pos2=1,sum=1,cnt=1;
//    cin >> n;
//
//    while (pos2 != n)
//    {
//        if (sum == n)
//        {
//            cnt++, pos2++;
//            sum += pos2;
//        }
//        else if (sum > n)
//        {
//            sum -= pos1;
//            pos1++;
//
//        }
//        else
//        {
//
//            pos2++;
//            sum += pos2;
//        }
//    }
//
//    printf("%d", cnt);
//    return 0;
//}
