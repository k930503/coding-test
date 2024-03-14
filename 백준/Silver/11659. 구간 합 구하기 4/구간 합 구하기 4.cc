#include <string>
#include <iostream>

using namespace std;
int main() {
    int N, M = 0;
    
    int nums[100000] = {0};

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        nums[i] += sum;
        sum = nums[i];
    }

    for (int i = 0; i < M; i++) {
        int start, end = 0;
        cin >> start >> end;
        int temp = 0;
        if (start != 1) {
            temp = nums[start - 2];
        }
        // cout << nums[end - 1] - temp << endl;
        printf("%d\n", nums[end - 1] - temp);
    }
    return 0;
}
