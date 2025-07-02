// https://codeforces.com/problemset/problem/1034-2

#include <iostream>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
}
int main() {
    setupIO();

    int t;
    cin >> t;

    int n, j, k;
    for (int i = 0; i < t; i++) {
        // cout << "for test-i:" << i << "\n";
        cin >> n >> j >> k;
        // cout << "n: " << n << " j: " << j << " k: " << k << endl;

        // next line will have n numbers collect them and put in array, and
        // call solution
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // If k >= 2, then we can always let every one except our target
        // fight, in a way that our target never takes part in any fight
        // Ex: 5 5 5 4 4 3 3 3 2 2 2 2 2 2 1, say our target is 4,
        // we can k is 2. meaning we can just put 4 separte and let every
        // other person fight so that 4 among the  k(2) reamining persons
        if (k > 1) {
            cout << "YES\n";
        } else {

            // if k is 1, then our target element must be the largest weight
            // player
            int player = arr[j - 1];
            int max_num = -1;
            for (int i = 0; i < n; i++) {
                if (max_num < arr[i]) {
                    max_num = arr[i];
                }
            }
            // cout << "MAX_NUM" << max_num << endl;
            // cout << "player" << player << endl;

            if (player == max_num) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }

            delete[] arr;
        }
    }
}
