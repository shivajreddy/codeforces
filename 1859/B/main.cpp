// B. Olya and Game with Arrays
// https://codeforces.com/problemset/problem/1859/B

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

void test_case();

int main() {
    setupIO();

    int tc;
    cin >> tc;
    while (tc--) test_case();
}

void test_case() {
    int n;
    cin >> n;

    vector<vector<int>> all_arrays(n);

    int curr_n = n;
    loop(i, 0, n) {
        int m;
        cin >> m;
        vi a(m);
        loop(j, 0, m) cin >> a[j];
        // loop(k, 0, m) cout << a[k] << " ";
        // cout << endl;
        sort(a.begin(), a.end()); // sort each array
        all_arrays[i] = a;
    }

    loop(i, 0, n) {
        loop(j, 0, all_arrays[i].size()) cout << all_arrays[i][j] << " ";
        cout << endl;
    }
}
