// D. Three Activities
// https://codeforces.com/problemset/problem/1914/D

// { Imports, TypeNames, Macros
#include <bits/stdc++.h>
#include <functional>
using namespace std;

// shorter type names
typedef long long ll;
typedef vector<int> vi;

// Macros
#define PB push_back
#define loop(i, a, b) for (int i = a; i < b; i++)
// }

vi find_max(vi& arr) {
    int n = arr.size();
    vector<pair<int, int>> tmp(n);
    loop(i, 0, n) {
        tmp[i].first = arr[i];
        tmp[i].second = i;
    }
    sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
    vi res(3);
    loop(i, 0, 3) res[i] = tmp[i].second;
    return res;
}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    loop(i, 0, n) cin >> a[i];
    vi b(n);
    loop(i, 0, n) cin >> b[i];
    vi c(n);
    loop(i, 0, n) cin >> c[i];

    vi max_a = find_max(a);
    vi max_b = find_max(b);
    vi max_c = find_max(c);

    int res = 0;
    loop(i, 0, 3) loop(j, 0, 3) loop(k, 0, 3) {
        int mxa = max_a[i], mxb = max_b[j], mxc = max_c[k];
        if ((mxa == mxb) || (mxb == mxc) || (mxc == mxa)) continue;
        res = max(res, a[mxa] + b[mxb] + c[mxc]);
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
