// B. Collecting Game
// https://codeforces.com/problemset/problem/1904/B

#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void solve() {
    int n;
    cin >> n;

    vector<int> original_v(n);
    for (int i = 0; i < n; i++)
        cin >> original_v[i];

    // copy and sort the input, (n log n)
    vector<int> v = original_v;
    sort(v.begin(), v.end());

    unordered_map<int, int> hm;

    // for (int i = n - 1; i >= 0; i--) {
    //     int num = v[i];
    //     cout << num << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++) {
        int score = v[i];
        int res = max(i - 1, 0);

        {
            cout << res;
        }
        hm[num] = res;
    }

    // output results
    for (int num : original_v) {
        cout << hm[num] << " ";
    }
    cout << "\n";
}

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
