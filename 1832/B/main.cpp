// B. Maximum Sum
// https://codeforces.com/problemset/problem/1832/B

// { Imports, TypeNames, Macros
#include <bits/stdc++.h>
using namespace std;

// shorter type names
typedef long long ll;
typedef vector<int> vi;

// Macros
#define PB push_back
#define loop(i, a, b) for (int i = a; i < b; i++)
// }

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    loop(i, 0, n) cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> prefix(n);
    prefix[0] = a[0];
    loop(i, 1, n) prefix[i] = prefix[i - 1] + a[i];

    ll res = -1;
    loop(i, 0, k + 1) {
        int left = 2 * i;
        int right = n - 1 - (k - i);
        ll sum = prefix[right] - (left == 0 ? 0 : prefix[left - 1]);
        res = max(res, sum);
    }
    cout << res << endl;
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
