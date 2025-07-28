// E. Cardboard for Pictures
// https://codeforces.com/problemset/problem/1850/E

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
    ll n, c;
    cin >> n >> c;

    vector<ll> a(n);
    loop(i, 0, n) cin >> a[i];

    ll S = 0;
    for (int num : a) S += pow(num, 2);

    ll total_sum = 0;
    for (int num : a) total_sum += num;

    ll b = c - S;

    loop(i, 0, n) cout << a[i] << " ";
    cout << endl;
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
