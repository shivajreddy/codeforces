// https://codeforces.com/contest/2123/problem/C

#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1), pre(n + 1, INT_MAX), suf(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = min(pre[i - 1], v[i]);
    }

    for (int i = n; i >= 1; i--)
        suf[i] = max(suf[i + 1], v[i]);

    for (int i = 1; i <= n; i++)
        cout << (v[i] == pre[i] || v[i] == suf[i] ? 1 : 0);

    cout << "\n";
}

int main() {
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
