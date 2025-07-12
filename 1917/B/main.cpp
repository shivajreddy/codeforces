// B. Erase First or Second Letter
// https://codeforces.com/problemset/problem/1917/B

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

int rec(unordered_set<string>& seen, const string& s, int l, int r) {
    if (l > r) return 0;
    string key = s.substr(l, r - l + 1);
    if (seen.count(key)) return 0; // already visited
    seen.insert(key);              // mark as visited

    int res = 1;
    if (s.substr(l + 1, r - l) == s.substr(l, r - l)) {
        res += rec(seen, s, l + 1, r); // only one side shrinks
    } else {                           // both sides shrinks
        res += rec(seen, s, l + 1, r);
        res += rec(seen, s, l, r - 1);
    }

    res += rec(seen, s, l + 1, r - 1);
    return res;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_set<string> seen;
    int res = rec(seen, s, 0, n - 1);
    for (const string& num : seen) {
        cout << num << endl;
    }
    cout << res << "\n";
}

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}
