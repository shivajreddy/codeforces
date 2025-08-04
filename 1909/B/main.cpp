// B. Make Almost Equal With Mod
// https://codeforces.com/problemset/problem/1909/B

#include <bits/stdc++.h>
using namespace std;

// shorter type names
typedef long long ll;
typedef vector<int> vi;

// Macros
#define PB push_back
#define loop(i, a, b) for (int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    vi a(n);
    loop(i, 0, n) cin >> a[i];

    // EDITORIAL INSIGHT: Try k = 2^1, 2^2, ..., 2^57

    // Mathematical proof:
    // - f(k) = number of distinct values after mod k operation
    // - If f(k) = 1, then f(2k) = 2 (key relationship!)
    // - f(1) = 1, f(2^57) = n, so there exists m where f(2^m) = 1 and
    // f(2^(m+1)) = 2
    //
    // Binary interpretation:
    // - mod 2^j means looking at the last j bits
    // - We find j such that last j bits create exactly 2 distinct patterns

    for (int bit = 1; bit <= 57; bit++) { // Editorial says up to 2^57
        long long k = 1LL << bit;         // k = 2^bit

        set<long long> remainders;
        for (int i = 0; i < n; i++) {
            remainders.insert(a[i] % k);
        }

        if (remainders.size() == 2) {
            cout << k << "\n";
            return;
        }
    }
}

void solve2() {
    int n;
    cin >> n;

    vi a(n);
    loop(i, 0, n) cin >> a[i];

    auto valid = [&](ll num) {
        unordered_map<int, int> hm;
        loop(i, 0, n) {
            ll x = a[i] % num;
            hm[x]++;
            if (hm.size() > 2) return false;
        }
        return true;
    };

    ll lo = 1, hi = 1e18;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (valid(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << lo << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int tc;
    cin >> tc;
    while (tc--) solve();
}
