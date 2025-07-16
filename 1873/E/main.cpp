// E. Building an Aquarium
// https://codeforces.com/problemset/problem/1873/E

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

void solve2() {
    int n, x;
    cin >> n >> x;

    vi a(n);
    loop(i, 0, n) cin >> a[i];
}

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    ll a[n];
    loop(i, 0, n) cin >> a[i];

    ll lo = 0, hi = 2'000'000'007;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            tot += max(mid - a[i], 0LL);
        }
        if (tot <= x)
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo << endl;
}
