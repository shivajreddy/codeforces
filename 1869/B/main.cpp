// B. 2D Traveling
// https://codeforces.com/problemset/problem/1869/B

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
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    vector<vector<int>> mat(n, vector<int>(2));
    loop(i, 0, n) cin >> mat[i][0] >> mat[i][1];

    auto get_dist = [&](int city1_idx, int city2_idx) -> int {
        if (city1_idx < k && city2_idx < k) return 0; // both are major cities
        int ax = mat[city1_idx][0], ay = mat[city1_idx][1];
        int bx = mat[city2_idx][0], by = mat[city2_idx][1];
        return abs(bx - ax) + abs(by - ay);
    };

    int start = a - 1, target = b - 1;
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
