// https://codeforces.com/problemset/problem/1850/D
// D. Balanced Round

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
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // edge case
    if (n == 1) {
        cout << "0\n";
        return;
    }

    sort(v.begin(), v.end());

    vector<int> ad;
    for (int i = 1; i < n; i++) {
        ad.push_back(v[i] - v[i - 1]);
    }

    int longest_seq = 0; // length of seq that has all abs <= k
    for (int i = 0, curr_len = 0; i < ad.size(); i++) {
        if (ad[i] <= k) {
            curr_len++;
            longest_seq = max(longest_seq, curr_len);
        } else {
            curr_len = 0;
        }
    }

    int res = n - longest_seq - 1;
    cout << res << "\n";
}

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
