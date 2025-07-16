// B. Deja Vu
// https://codeforces.com/problemset/problem/1891/B

#include <bits/stdc++.h>
using namespace std;

// shorter type names
typedef long long ll;
typedef vector<int> vi;

// Macros
#define PB push_back
#define loop(i, a, b) for (int i = a; i < b; i++)

void setupIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void solve();

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--) solve();
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    loop(i, 0, n) cin >> a[i];

    vi x(q);
    loop(i, 0, q) cin >> x[i];

    vi res = a;

    loop(i, 0, q) { // 10^5, xi=[1..30]
        int d = pow(2, x[i]);
        int add = pow(2, x[i] - 1);
        loop(j, 0, n) { // 10^5, ai=[1..10^9]
            if (res[j] % 2 == 1) continue;
            if (res[j] % d == 0) res[j] += add;
        }
    }

    loop(i, 0, n) cout << res[i] << " ";
    cout << '\n';
}
